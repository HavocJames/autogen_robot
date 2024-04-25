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
It integrates sensor data from the robot's environment, such as cameras and touch sensors, to inform its movements in real-time. 
Additionally, Hash robot engages in motion planning to calculate optimal trajectories and incorporates feedback control mechanisms to adjust movements based on sensory input
### Groq: 
It is the new blazing-fast AI platform that beat ChatGPT and Gemini is an
open-source query language, that offers a powerful and intuitive approach to querying data. that's easy to learn. 
Groq is the ‘fast and furious’ of the LLM world offering a staggering 500 tokens per second for smaller models with an output speed of 2.5 seconds. 
In the world of large language models (LLMs) speed matters and with the entry of Groq, a company founded by ex-Google engineers, it is about to get a major boost. 
The AI platform is making waves with its innovative Language Processing Unit (LPU.
This incredible speed advantage stems from Groq's unique approach. Unlike the jack-of-all-trade GPUs, the LPU is a specialist. It's built from the ground up with a "software-first" mentality to excel at processing the massive datasets that power LLMs.
This focus translates to predictable, lightning-fast performance with minimal latency.
Groq's LPU is the sushi knife of the LLM world, perfectly tailored for the intricate task of language processing.
The LPU's architecture, coupled with a specialized compiler, minimizes energy consumption and system lag. The race for AI supremacy is heating up, and Groq's LPU is a clear frontrunner. With its commitment to speed, efficiency, and specialization, Groq is paving the way for a future where AI feels more responsive and integrated into our lives than ever before.

# APPLICATIONS
The integration of a locally hosted Large Language Model (LLM) alongside advanced speech recognition and synthesis competence forms a robust foundation for a myriad of applications, particularly within the domain of human-robot interaction. 
This amalgamation inscribes several key challenges while unlocking numerous possibilities in various sectors. 
Firstly, by hosting the language model locally, data privacy concerns inherent in cloud-based solutions are productively mitigated. This local hosting ensures that sensitive information exchanged during interactions remains within controlled environments, assuring the confidentiality and security of the data given by the users.
Moreover, the synergy between speech recognition and synthesis technologies facilitates smooth communication between humans and robots. The LLM legitimizes robots to comprehend and generate natural language, enabling more intuitive and human-like interactions.
Hence allows users to communicate with robots using speech, and is then accurately transcribed into text, processed, and responded to in real-time, enhancing the overall user experience.
The incorporation of retrieval augmented generation (RAG) and Autogen mechanisms further upgrade interaction capabilities. RAG enables robots to retrieve and augment information from local databases which improves the relevance and accuracy of responses provided to user queries. 
Autogen, on the other hand, enables robots to autonomously generate responses based on contextual understanding, expanding the range of significant tasks they can perform.
#### Edge AI:
Edge AI refers to the deployment of artificial intelligence algorithms and models directly on edge devices, such as robots, rather than relying solely on cloud-based processing. 
Here the system described likely leverages Edge AI for real-time processing of speech recognition and synthesis on the 21 DOF humanoid robot, permitting efficient and responsive interaction with humans without constant reliance on external servers.
Applications could include real-time language understanding and generation during human-robot interactions at the edge, improving efficiency and reducing remission.
#### Reception:
Humanoid robots equipped with speech recognition and synthesis capabilities can serve as interactive receptionists. 
They can greet visitors, provide information about the premises, assist with check-ins, provide help during stays, and answer frequently asked questions. 
The locally hosted LLM enables the robot to understand and respond to various queries naturally and conversationally, enhancing the reception experience for guests but also ensuring data privacy by processing information locally.
### Healthcare:
Humanoid robots with speech recognition and synthesis capabilities can find applications in healthcare settings too. They can assist patients by providing information about their health issues, and medications, scheduling appointments, and answering general health-related queries. 
Moreover, these robots can offer companionship and emotional support to patients, especially in environments where human resources are limited and people who are isolated for some reason. 
The locally hosted LLM ensures that patient information is processed securely on-site, addressing concerns about data privacy in healthcare.
### Entertainment:
Humanoid robots equipped with speech recognition and synthesis capabilities can serve as interactive entertainers in various settings, such as theme parks, museums, or celebration venues. 
They can interact with visitors through conversations, storytelling, or providing information about exhibits or attractions. 
By maintaining data privacy, the locally hosted LLM enables the robot to tailor its interactions based on the preferences and interests of the audience.
# LIMITATIONS
The integration of Large Language Models (LLMs) into robotics represents a significant leap forward in human-robot interaction, which improves more natural and uninterrupted communication between humans and machines. By locally hosting an LLM, particularly in the context of a humanoid robot, we aimed to build the robot with advanced language processing capabilities, leveraging its vast information base to facilitate meaningful interactions and enhance overall user experience. This integration opens up an abundance of possibilities, ranging from speech recognition and synthesis to retrieval augmented generation (RAG) and auto-generation of responses.
With an LLM at its core, the humanoid robot can comprehend and respond to spoken commands, generate contextually relevant information, and even engage in dialogue with users on a wide range of subjects.
Moreover, the capability to run the LLM locally ensures real-time processing, enabling fast responses and reducing reliance on external servers or internet connectivity. However, despite the transformative potential of this merging, several challenges and limitations must be addressed. 
These include the risk of LLM hallucinations, where the model produces erroneous or misleading information, as well as concerns related to the robot's stability and balance, voice recognition accuracy, and power delivery. Overcoming these challenges requires careful consideration of both technical and practical aspects, encircling software development, hardware design, and user interface optimization.
By navigating these challenges and leveraging the capabilities of locally hosted LLMs, we strive to push the boundaries of human-robot interaction and pave the way for a future where robots truly understand, and respond according to the requirement, adapting to human language and behavior
###  Limited Agent Integration
Limited agent integration refers to the deliberate decision to restrict the incorporation of external agents or application programming interfaces (APIs) within the framework of the humanoid robot.
While integrating an LLM locally provides the robot with powerful language processing capabilities, depending on this internal system may impose certain limitations, particularly in scenarios requiring access to real-time data or specialized functionalities beyond the scope of the LLM itself.
One significant consequence of limited agent integration is the potential reduction in the dynamism and functionality of the humanoid robot during interactions with users and their queries. External agents and APIs can provide access to diverse sources of information, services, and functionalities that complement the abilities of the LLM.
For instance, an API could provide real-time weather updates, access to online databases and integration with external devices and services.
By restricting such integrations, the robot's ability to provide timely and contextually relevant information may be limited which leads to less dynamic interactions with users.
Furthermore, specialized tasks or services that are not directly supported by the LLM may require external integrations and supports which must be performed efficiently and accurately. 
For example, tasks such as navigation, object recognition, or complex calculations may require the use of specialized algorithms or services provided by external agents.
Without the ability to integrate these agents, the robot may struggle to perform such tasks effectively, resulting in decreased functionality and adaptability in certain scenarios
Overall, limited agent integration imposes difficulties on the breadth and depth of capabilities that the humanoid robot can offer.
Although the locally hosted LLM acts as a powerful cognitive engine for processing language, incorporating external agents and APIs can amplify its effectiveness. 
Therefore, the decision to limit agent integration should be carefully evaluated against the desired level of functionality and dynamism essential for the intended application of the humanoid robot.
### LLM Hallucinations
LLM hallucinations refer to typical cases where Large Language Models generate responses that contain erroneous or misleading information. These errors can arise due to biases present in the training data or limitations in the model's context understanding. 
Since LLMs are trained on vast datasets scraped from the internet, they can inadvertently learn and propagate biases present in the data which leads to inaccurate or inappropriate responses. 
Detection and elimination of LLM hallucinations pose a significant challenge. Traditional methods of verification, such as fact-checking, may not always be effective, especially in real-time interactions where immediate responses are required. 
Moreover, implementing automated verification mechanisms within the LLM framework adds complexity and computational overhead. To eliminate LLM hallucinations, researchers are exploring techniques such as bias reduction during training, context-aware response generation and ensemble learning approaches that combine multiple models to cross-verify responses.
However, these methods are still in the experimental stage and have the least chance of a comprehensive solution. Addressing these hallucinations requires an integration of technological advancements, algorithmic improvements, and human oversight to ensure that the robot's responses are accurate, trustworthy, and contextually appropriate.
### Robot Stability and Balance 
Robot stability and balance are fundamental aspects of humanoid robot design therefore providing safe and efficient operation in dynamic environments as well as when interacting with humans.
While integrating a locally hosted Large Language Model(LLM) improves the robot's cognitive capabilities, it does not inherently address the physical challenges related to stability and balance. The physical stability and balance of a humanoid robot are fundamentally determined by its mechanical design, control algorithms, and sensor feedback mechanisms. 
These components work together to ensure that the robot remains upright and steady during movement and interaction. Factors such as weight distribution, joint stiffness, and center of mass also play critical roles in maintaining stability. Hardware design comprises the structural components of the robot, including its body frame, actuators, and joints. Ensuring that these components are wholesome and well-balanced is essential for preventing instabilities that could lead to falls or accidents.
Sensor feedback mechanisms, such as inertial measurement units (IMUs) and force/torque sensors, provide critical feedback about the robot's orientation and interactions with the environment. By continuously monitoring these signals, the robot can detect deviations from the desired posture and take corrective actions to maintain stability and reliability. 
Failure to maintain stability and balance in a humanoid robot can cause serious issues, including accidents, injuries, and damage to the robot and its surroundings. Despite the advanced cognitive capabilities provided by the LLM, ensuring physical stability remains a crucial aspect of robot design and development
### Voice Recognition Accuracy
Voice recognition accuracy is critical for effective human-robot interaction, yet achieving high accuracy poses challenges, particularly in diverse environments with various accents and background noise. 
This being the most important part of our humanoid robot, the accuracy of speech recognition depends on several factors, including the quality of the underlying algorithms, the diversity and quality of the training data, and environmental conditions. 
Local hosting of the LLM does not inherently improve voice recognition accuracy, instead, the accuracy of voice recognition systems depends on robust algorithms capable of handling diverse speech patterns and noise levels effectively.
Inaccurate voice recognition can lead to misunderstandings and wrong answers during interactions with the robot. Users may experience difficulty in conveying commands or information, resulting in incorrect responses and failed interactions.
Moreover, in dynamic environments with unpredictable noise levels or any disturbances, maintaining high accuracy becomes even more challenging.
Therefore, ensuring accurate voice recognition requires continuous refinement of algorithms, thorough testing in diverse environments, and optimization of training data to account for different speech patterns and environmental conditions
### Power Delivery
Local hosting of the LLM entails substantial computational resources, which directly impact the power requirements of the humanoid robot. The computational demands imposed by running large language models locally can strain the robot's power supply system, potentially leading to inefficiencies or inadequate power distribution. 
An efficient power delivery system is essential to ensure the smooth operation of both the computational hardware, responsible for processing language inputs and generating responses, and the physical actuators, which enable the robot's movement and interaction with the environment. 
Inadequate power delivery have significant risks to the reliability and
usability of the humanoid robot. Insufficient power supply may result in performance degradation, causing delays or inconsistencies in processing language inputs and generating responses.
Moreover, it could lead to premature shutdowns, interrupting ongoing interactions as well as rendering the robot inoperable. These disruptions not only impair the robot's functionality but also decrease the user experience and trust in the system.
Addressing power delivery challenges requires careful consideration of the robot's power supply architecture, including battery capacity, voltage regulation as well as distribution mechanisms. 
Optimizing power management strategies is crucial to eliminating risks associated with excessive power consumption or insufficient supply. Furthermore, integrating energy-efficient components and implementing adaptive power-saving techniques can help extend battery life and improve overall system reliability.
By prioritizing efficient power delivery, the robustness and usability of the humanoid robot can be improved ensuring smooth operation and prolonged functionality in various operating conditions
