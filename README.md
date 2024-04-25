# autogen_robot
a robot that is powered by large language models and autogen as well as langchain tools
(it should be noted that  the  robot is controlled through the function act where the it sends strings of command to the microcontroller where the action is enabled )

# ABSTRACT 
LLM-based Humanoid Robot represents a pioneering exploration into the integration of Large Language Models (LLMs) within humanoid robotics, aiming to revolutionize human-robot interaction.
With the focus lies on developing a sophisticated AI Voice interactive robot assistant that leverages the capabilities of LLMs to create a seamless and intuitive interface between humans and robots. 
The primary objectives are to provide accurate and relevant responses when users seek directions or information through natural language understanding and to handle errors and recovery
effectively. 
This project provides a hands-free, instinctive interface, empowering users to navigate effortlessly through voice commands. Key to our approach is the deployment of a 21 Degree of Freedom (DOF) humanoid robot, serving as the physical embodiment of our LLM-based Humanoid Robot.
Equipped with cutting-edge hardware and software components, this robot embodies the fusion of artificial intelligence and robotics, offering users a natural and instinctive means of communication through voice commands. 
Central to the system's functionality is the utilization of LLM as the brain of the robot ensures rapid processing of user commands and responses, while also prioritizing data privacy and security. 
This approach enables the robot to tap into a vast knowledge base, providing accurate and relevant information to users in real time. 
Furthermore, the system incorporates advanced speech recognition and synthesis technologies, facilitating fluid dialogue between humans and the robot. 
Through sophisticated dialogue management techniques using chains and retrieval-augmented generation (RAG) from a local database, the robot can handle errors effectively and adapt its responses to suit the user's needs. 
The importance of this project lies in its potential to enhance accessibility, enabling a broader user base to interact with technology naturally.
It offers a significant time-saving solution, adapts to emerging technologies, and boosts efficiency and productivity By creating an efficient and user-friendly interface and exploring the full potential of LLM-based humanoid robots across various domains, including healthcare assistance, entertainment companionship, and beyond. 
The aim is to enhance accessibility and broaden the scope of human-robot interaction. Ultimately, this project contributes to the advancement of robotics technology, paving the way for a future where humanoid robots play an integral role in everyday life

# WORKING DIAGRAM
<img width="960" alt="working diagram" src="https://github.com/HavocJames/autogen_robot/assets/124689464/ddbd7298-ffce-4a90-afad-85d9295276b7">

In the principality of Artificial Intelligence and Robotics, effective human-machine interaction is crucial for seamless communication and task execution.
The architecture shown above outlines a refined system designed to facilitate such interaction through various components working in collaboration. 
This system integrates cutting-edge technologies including voice recognition, large language models (LLMs), and specialized agents to enable a robot to understand user queries, retrieve relevant information, take appropriate actions, and provide responses in natural language according to the local database given. At its core, the system comprises several key components: the Microphone, Voice Recognition, and Agent Manager which includes LLM Chain Agent, RAG Agent, Action Agent, Local Database, Action Set, Controller, Actuators and Speaker. 
Each component plays a significant role in different stages of the interaction process, from capturing user input to executing actions and delivering responses back to the user. 
The system starts with the capture of user speech by the Microphone, processed by the Voice Recognition module into text. This text is directed by the Agent Manager to either the RAG Agent for information retrieval as well as for generation or the Action Agent for task execution. 
The LLM serves as the core knowledge base, accessed through an API (Application Programming Interface), enabling agents to understand queries and generate responses. 
The RAG Agent reclaims and augments information from the local database using the LLM, while the Action Agent executes predefined tasks. 
The Controller orchestrates the hardware actions, and the Speaker generates synthesized speech based on Agent Manager Instructions, completing the interaction loop.
The functions of each block are given below:
#### 1 Microphone and Speaker:
The microphone captures the speech or audio signal from the user. The speaker generates speech, likely based on the output from the agent manager.
#### 2 Voice Recognition: 
This module converts the captured audio signal from the microphone into text using the VOSK Automatic Speech Recognition Model which is designed to be lightweight, efficient, and accurate.
#### 3 LLM (Large Language Model):
The heart of the system lies in the LLM, which serves as the expertise base and language processing engine. The locally hosted model is called through API (Application Programming Interface) to be used for the agent’s interaction. The agent uses the resources provided by LLM to do its appropriate task.
#### 4 Agent Manager: 
This component directs the recognized text to the appropriate agent and allocates the agent to the local LLM. Agent manager also enable agents to communicate with each other.
#### 5 LLM Chain:
An appropriate response is given to the user’s question which is present in the knowledge base of the LLM.
#### 6 RAG Agent: 
Retrieval Augmentation Generation Agent. It’s an agent trained to retrieve information from the local database, augment it with additional information and then use an LLM to generate a response.
#### 7 Agent and Action Set: 
An agent can refer to a software program that is designed to carry out a specific task or set of tasks. In the context of this diagram, the agent is likely to fulfil the user's request using the results from the LLM. Action Set defines the set of actions that the robot can take and perform.
#### 8 Controller:
It controls the hardware of the robot and does the actions told by the action agent from the action set.

# TOOLS AND TECHNOLOGY USED
### LLM, or Large Language Model:
It represents the cornerstone of the humanoid robot's language processing capabilities, enabling it to comprehend, generate, and translate textual information while performing a myriad of natural language processing (NLP) tasks. 
This AI program functions as the central nervous system of the robot's conversational abilities, allowing it to understand user queries, generate contextually appropriate responses, and engage in meaningful dialogues.
Through extensive training on vast datasets, LLM acquires a deep understanding of language semantics, syntax, and context, enabling it to infer user intent and respond with accuracy and relevance.
Additionally, LLM's versatility extends beyond mere conversation, empowering the robot to perform various NLP tasks such as sentiment analysis, summarization, and language translation, thereby enhancing its utility and adaptability across diverse applications and environments.
### Langchain:
Langchain serves as a pivotal component empowering the robot to
function as a local host for Large Language Models (LLMs), offering a comprehensive suite of tools and services conveniently packaged as a Python library. 
This versatile framework facilitates a wide array of tasks essential for seamless LLM operation, including serving Retrieval-Augmented Generation (RAG) models for enhanced text generation, caching embeddings to optimize computational efficiency, conducting Google searches to access vast amounts of information, and managing vector stores for efficient data storage and retrieval.
By providing a unified platform with integrated functionalities, Langchain streamlines the deployment and management of LLMs, enabling the robot to leverage sophisticated language processing capabilities with ease
and efficiency in diverse applications.
###  Autogen: 
Autogen serves as a pivotal component in orchestrating the interaction
between users and the humanoid robot by creating and managing agents that engage in communication and chat activities on behalf of the robot.
These agents act as intermediaries, interpreting user queries and generating appropriate responses in realtime.
Autogen likely leverages the diverse functionalities provided by Langchain,
seamlessly integrating tools such as language models, retrieval-augmented generation(RAG) models, and vector stores to empower agents with sophisticated AI capabilities.
By harnessing these integrated tools, Autogen ensures the effective execution of AI chat code, enabling agents to engage users in meaningful and contextually relevant conversations, thereby enhancing the overall conversational experience and fostering more natural human-robot interactions.
###  Vosk and PYTTSX3: 
Vosk and PYTTSX3 are integral components responsible for facilitating seamless voice interaction between users and the humanoid robot. 
Vosk specializes in capturing and processing voice commands, employing advanced algorithms to accurately convert spoken words into text format, enabling the robot to comprehend user inputs effectively. 
Complementing Vosk, PYTTSX3 plays a crucial role in generating speech responses from text, utilizing the Espeak engine to convert textual outputs into audible responses. 
Together, these tools create a bidirectional communication channel, allowing users to interact with the robot through spoken commands while enabling the robot to respond audibly, enhancing the overall user experience and enabling more intuitive human-robot interaction.
### Hash robot: 
<https://github.com/hashrobotics-hr/hash_humanoid_robot_v3>

This component provides the robot with versatile and precise physical guidance similar to human movements, enhancing its capabilities in interacting with the physical world.
The Hash robot component serves as the essential motor control system for the humanoid robot, enabling it to perform tasks with versatility and precision akin to human movements. 
Through the orchestration of motors and actuators within the robot's joints and limbs, Hash robot translates digital commands into physical actions.
Itintegrates sensor data from the robot's environment, such as cameras and touch sensors, to inform its movements in real-time. 
Additionally, Hash robot engages in motion planning to calculate optimal trajectories and incorporates feedback control mechanisms to adjust movements based on sensory input
