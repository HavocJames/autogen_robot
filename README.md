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
#### Microphone and Speaker:
The microphone captures the speech or audio signal from the user. The speaker generates speech, likely based on the output from the agent manager.
#### Voice Recognition: 
This module converts the captured audio signal from the microphone into text using the VOSK Automatic Speech Recognition Model which is designed to be lightweight, efficient, and accurate.
#### LLM (Large Language Model):
The heart of the system lies in the LLM, which serves as the expertise base and language processing engine. The locally hosted model is called through API (Application Programming Interface) to be used for the agent’s interaction. The agent uses the resources provided by LLM to do its appropriate task.
#### Agent Manager: 
This component directs the recognized text to the appropriate agent and allocates the agent to the local LLM. Agent manager also enable agents to communicate with each other.
#### LLM Chain:
An appropriate response is given to the user’s question which is present in the knowledge base of the LLM.
#### RAG Agent: 
Retrieval Augmentation Generation Agent. It’s an agent trained to retrieve information from the local database, augment it with additional information and then use an LLM to generate a response.
#### Agent and Action Set: 
An agent can refer to a software program that is designed to carry out a specific task or set of tasks. In the context of this diagram, the agent is likely to fulfil the user's request using the results from the LLM. Action Set defines the set of actions that the robot can take and perform.
#### Controller:
It controls the hardware of the robot and does the actions told by the action agent from the action set.
