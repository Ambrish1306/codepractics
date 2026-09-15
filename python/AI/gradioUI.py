import os 
from dotenv import load_dotenv
from IPython.display import display, Markdown
from langchain_openai import ChatOpenAI
from openai import OpenAI
import gradio as gr

#this from openai import OpenAI is used to import the OpenAI class from the openai module, which allows you to interact with the OpenAI API for various tasks such as generating text, images, and more.
openai = OpenAI(base_url='http://localhost:11434/v1', api_key='ollama')
#this from langchain_openai import ChatOpenAI is used to import the ChatOpenAI class from the langchain_openai module, which provides a convenient interface for interacting with OpenAI's chat models, enabling you to create conversational AI applications.  
chat_openai = ChatOpenAI(
    model="llama3.2",
    base_url="http://localhost:11434/v1",
    api_key="ollama"
)
sysprompt = [
    {
        "role": "system",
        "content": "You are a helpful assistant",
    }
]
def generate_response(user_prompt):
    ollama_client = openai.chat.completions.create(
        model="llama3.2",
        messages= sysprompt + [{"role":"user", "content": user_prompt}],
        stream=True
    )
    result = ""
    for chunk in ollama_client:
        result += chunk.choices[0].delta.content or ""
        yield result
    #return ollama_client.choices[0].message.content

message_input = gr.Textbox(label="Your message:", info="Enter a message to be shouted", lines=7)
message_output = gr.Textbox(label="Response:", lines=8)
#gr.Interface(fn=generate_response, title="AmbrishGPT", inputs=message_input, 
#             outputs=message_output, flagging_mode="never").launch(share=True)


#############gardio app chat interface#########
system_message = "You are a helpful assistant. You will be provided with a message from the user and a history of previous messages. Your task is to generate a relevant and helpful response based on the user's message and the context provided by the history. Please ensure that your response is clear, concise, and informative."
MODEL = "llama3.2"
def chat(message, history):
    history = [{"role":h["role"], "content":h["content"]} for h in history]
    relevant_system_message = system_message

    messages = [{"role": "system", "content": relevant_system_message}] + history + [{"role": "user", "content": message}]

    stream = openai.chat.completions.create(model=MODEL, messages=messages, stream=True)

    response = ""
    for chunk in stream:
        response += chunk.choices[0].delta.content or ''
        yield response

gr.ChatInterface(fn=chat).launch(share = True)