
import os
import openai
from urllib import response
from urllib.request import urlopen
from openai import OpenAI
from dotenv import load_dotenv
from IPython.display import display, Markdown



def fetch_website_contents(url):
    with urlopen(url) as response:
        return response.read().decode("utf-8", errors="ignore")


load_dotenv()
#command to run ollama server macbook: ollama run llama3.2
MODEL_NAME = "llama3.2"
message = "Hello, GPT! who is Sachin Tendulkar? Please provide a brief summary of his achievements in cricket."
messages = [{"role": "user", "content": message}]

def useOpenAI():
    openai = OpenAI(base_url='http://localhost:11434/v1', api_key='ollama')
    #openai.chat.completions.create() is used to create a chat completion using the specified model and messages. The response will contain the generated content based on the input message.
    input_message = input("Enter your message: ")
    if not input_message:
        input_message = messages
    else: 
        input_message = [{"role": "user", "content": input_message}]

    response = openai.chat.completions.create(
            model=f"{MODEL_NAME}",
            messages=input_message,
            stream=True

   )   
    print(response.choices[0].message.content)



if __name__ == "__main__":
    useOpenAI()
