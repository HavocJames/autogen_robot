from autogen import ConversableAgent,AssistantAgent, UserProxyAgent
from autogen import GroupChat,GroupChatManager

from langchain_community.vectorstores.faiss import FAISS
from langchain.embeddings import CacheBackedEmbeddings
from langchain.storage import LocalFileStore
from langchain_community.embeddings import HuggingFaceInstructEmbeddings
from langchain_community.document_loaders.pdf import PyPDFLoader
from langchain.text_splitter import RecursiveCharacterTextSplitter

from googlesearch import search
import requests
from bs4 import BeautifulSoup

import serial
import serial.tools.list_ports

import pyttsx3
from vosk import Model, KaldiRecognizer
import pyaudio
import json

#stt setup and model calling
model = Model("./vosk-model-en-in-0.5")
#model = Model("./vosk-model-small-en-in-0.4")
recogniser = KaldiRecognizer(model, 16000)
mic = pyaudio.PyAudio()
sttstream = mic.open(format=pyaudio.paInt16, channels=1, rate=16000, input=True, frames_per_buffer=8192)

# serial port calling and setup
ports = serial.tools.list_ports.comports()
portsList = ports[0][0]
arduino = serial.Serial(portsList, baudrate = 115200)
if arduino.is_open:
    print("Connected to Arduino on port:",portsList)

# rag setup and calling
store = LocalFileStore("./CacheBackedEmbeddings/")
underlying_embeddings = HuggingFaceInstructEmbeddings(
    model_name="hkunlp/instructor-large",
    model_kwargs={"device": "cpu"},
    embed_instruction="Represent the document for retrieval:",
    query_instruction="Represent the question for retrieving supporting documents:",
    )

cached_embedder = CacheBackedEmbeddings.from_bytes_store(
    underlying_embeddings, store, namespace="hkunlp/instructor-large")

loader = PyPDFLoader("./data.pdf")
docs = loader.load()

text_splitter = RecursiveCharacterTextSplitter(
    chunk_size=1000, chunk_overlap=200, add_start_index=True
)
all_splits = text_splitter.split_documents(docs)
vectorstore = FAISS.from_documents(documents=all_splits, embedding=cached_embedder)
ret=vectorstore.as_retriever(search_type="similarity", search_kwargs={"k": 6})

# configure the models  and tools (groq api is used here) 
config_list={
        #"model" : "mixtral-8x7b-32768",
        #"model" : "llama3-8b-8192",
        "model" : "llama3-70b-8192",
        "base_url" : "https://api.groq.com/openai/v1",
        "api_type" : "openai",
        "api_key" :"<use your groq API or open API key>",
    }

llm_config = {
    "config_list": [config_list],
    "timeout": 60,
    "seed": 43,
    "temperature": 0,
    "functions":[
        {
            "name": "act",
            "description": "send string commands to the serial port .",
            "parameters": {
                "type": "object",
                "properties": {
                    "action": {
                        "type": "string",
                        "description": "  single word string command of the action  the robot must take  .",
                    }
                },
                "required": ["action"],
            },
        },
        {
            "name": "ddgsearch",
            "description": "does web search for unknown topics.",
            "parameters": {
                "type": "object",
                "properties": {
                    "find": {
                        "type": "string",
                        "description": "Refined message which keeps the original meaning and can be used to search internet for question answering.",
                    }
                },
                "required": ["find"],
            },
        },
        {
            "name": "rag",
            "description": "retrieve content for question answering from documents.",
            "parameters": {
                "type": "object",
                "properties": {
                    "message": {
                        "type": "string",
                        "description": "Refined message which keeps the original meaning and can be used to retrieve content for question answering.",
                    }
                },
                "required": ["message"],
            },
        },
    ],
}

# creating functions for agents
def ddgsearch(find):
    for j in search(find, tld="co.in",country="<your country>", num=1, stop=1, pause=1):
        bs = BeautifulSoup(requests.get(j).text, "html.parser")
        return (str(bs.get_text(strip=True)))
    
def rag(message):
    docs = ret.get_relevant_documents(message),
    return str(docs)

def act(action):
    arduino.write((action).encode('utf-8'))
    arduino.timeout = 0.1 
    return str(action," done")

# set up the text-to-speech 
def tts(text):  
    sttstream.stop_stream() 
    engine = pyttsx3.init()
    rate = engine.getProperty('rate')
    engine.setProperty('rate', rate-50)
    engine.say(text)
    engine.runAndWait()

#set up the speech-to-text 
def stt():
    sttstream.start_stream()
    while True:
        data = sttstream.read(4096)
        if recogniser.AcceptWaveform(data):
            result = recogniser.Result()
            result_json = json.loads(result)
            text_content = result_json.get("text", "")
            if text_content.strip():  
                return text_content 

#agent calling
llmchain = ConversableAgent(
    "llmchain",
    system_message=""" you are friendly robotic assistant called echo-bot.           
                    you have normal conversation with the user in a friendly manner.
                    you will answer user questions by thinking step by step based on the context.
                    Give out short answers. do not ask questions. 
                    you can also chat with user when there no need for function call.
                    """,
    llm_config=config_list,
    human_input_mode="NEVER",  # Never ask for human input.
    max_consecutive_auto_reply=1,  # Limit the number of consecutive auto-replies.
    is_termination_msg=lambda msg: msg.get("content") is not None and "TERMINATE" in msg["content"],
    code_execution_config=False,  # we don't want to execute code in this case.
)

ragagent = AssistantAgent(
    name="ragagent",
    system_message="""You are a helpful robot assistant,
                    find the answer from the document provided to answer to the question.
                    use the function rag.
                    the document contains rooms and teachers details 
                    do not engage in unwanted conversation.""",
    llm_config=llm_config,
    human_input_mode="NEVER",
    max_consecutive_auto_reply=2,
    function_map={"rag":rag},
    is_termination_msg=lambda msg: msg.get("content") is not None and "TERMINATE" in msg["content"],
    code_execution_config=False,  # we don't want to execute code in this case.
)

actionagent = AssistantAgent(
    "actionagent",
    system_message="""You are a helpful robot assistant. 
                    do not engage in unwanted conversation.
                    you deciding any physical action the robot must take.
                    use the function act
                    if the robot must walk send "WALK" on the act function.
                    if the robot must rise hand send "RISE" on the act function .""",
    llm_config=llm_config,
    human_input_mode="NEVER",  # Never ask for human input.
    max_consecutive_auto_reply=3, 
    function_map={"act":act},
    is_termination_msg=lambda msg: msg.get("content") is not None and "TERMINATE" in msg["content"],
    code_execution_config=False,  # we don't want to execute code in this case.
)

searchagent = AssistantAgent(
    name="searchagent",
    system_message="""You are a helpful web search assistant.
                    use the function ddgsearch
                    you will search the web if the content that require current knowledge.
                    find answer to question that is unknown and needs a websearch.
                    do not engage in unwanted conversation.                    
                    """,
    llm_config=llm_config,
    human_input_mode="NEVER",
    max_consecutive_auto_reply=2,
    function_map={"ddgsearch":ddgsearch},
    is_termination_msg=lambda msg: msg.get("content") is not None and "TERMINATE" in msg["content"],
    code_execution_config=False,  # we don't want to execute code in this case.
)

userproxy = UserProxyAgent(
    name="user_proxy",
    code_execution_config=False,
    is_termination_msg=lambda msg: msg.get("content") is not None and "TERMINATE" in msg["content"],
)

# configuring the group chat 
group_chat = GroupChat(
    agents=[llmchain, ragagent, actionagent, searchagent,],
    messages=[],
    admin_name = userproxy,
    max_round=10,
    speaker_selection_method = "auto",
    #speaker_selection_method=custom_speaker_selection_func,
    )

manager = GroupChatManager(groupchat=group_chat, 
    is_termination_msg=lambda x: x.get("content", "").find("TERMINATE") >= 0,
    llm_config=config_list
)

def intchat(qes):
    chat=userproxy.initiate_chat(
        manager,
        message=qes,
        summary_prompt="""Your name is echo-bot and you are friendly assistant robot. 
                    consider all the conversation as your own thought process
                    reply the answer in first person """,

        summary_method= "reflection_with_llm",
    #summary_method= "last_msg",
    )
    return (chat.summary)

#pprint.pprint(chat.cost)
#assistant.reset()

print("initialization completed system is now ready to respond ...... ")
tts("initialization completed system is now ready to respond ...... ")

while True:
    qes = stt() 
    ans=intchat(qes)
    print("user: ",qes)
    print("robot: ",ans)
    tts(ans)
