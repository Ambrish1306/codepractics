import os 
from dotenv import load_dotenv
from openai import OpenAI
import gradio as gr
import json

MODEL_NAME = "llama3.2"
load_dotenv()
openai = OpenAI(base_url='http://localhost:11434/v1', api_key='ollama')

system_message = """
You are a helpful assistant for an Airline called FlightAI.
Give short, courteous answers, no more than 1 sentence.
Always be accurate. If you don't know the answer, say so.
"""
def chat(message, history):
    history = [{"role":h["role"], "content":h["content"]} for h in history]
    messages = [{"role": "system", "content": system_message}] + history + [{"role": "user", "content": message}]
    response = openai.chat.completions.create(model=MODEL_NAME, messages=messages)
    print(response)
    return response.choices[0].message.content

ticket_prices = {"london": "799", "paris": "899", "tokyo": "1400", "berlin": "499"}
#gr.ChatInterface(fn=chat).launch(share=True)
#############MCP/TOOL###############################################
def get_ticket_price(destination):
    print(f"Tool called for city {destination}")
    price = ticket_prices.get(destination.lower(), "Unknown ticket price")
    return f"The price of a ticket to {destination} is {price}"

#MCP
price_function = {
    "name": "get_ticket_price",
    "description": "Get the price of a return ticket to the destination city.",
    "parameters": {
        "type": "object",
        "properties": {
            "destination_city": {
                "type": "string",
                "description": "The city that the customer wants to travel to",
            },
        },
        "required": ["destination_city"],
        "additionalProperties": False
    }
}
tools = [{"type": "function", "function": price_function}]

def handle_tool_calls(message):
    responses = []
    for tool_call in message.tool_calls:
        if tool_call.function.name == "get_ticket_price":
            arguments = json.loads(tool_call.function.arguments)
            city = arguments.get('destination_city')
            price_details = get_ticket_price(city)
            responses.append({
                "role": "tool",
                "content": price_details,
                "tool_call_id": tool_call.id
            })
    return responses

def chat_tool(message, history):
    history = [{"role":h["role"], "content":h["content"]} for h in history]
    messages = [{"role": "system", "content": system_message}] + history + [{"role": "user", "content": message}]
    response = openai.chat.completions.create(model=MODEL_NAME, messages=messages, tools=tools)

    if response.choices[0].finish_reason=="tool_calls":
        message = response.choices[0].message
        responses = handle_tool_calls(message)
        messages.append(message)
        messages.extend(responses)
        response = openai.chat.completions.create(model=MODEL_NAME, messages=messages)
    
    return response.choices[0].message.content

print(get_ticket_price("london"))
gr.ChatInterface(fn=chat_tool).launch()
