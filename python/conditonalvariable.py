import gradio as gr
from huggingface_hub import HfFolder, Repository, whoami

def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def findDuplicate(mylist):
    for i in range(len(mylist)):
        print(mylist[i])



if __name__ == "__main__":
    gr.ChatInterface(fn=findDuplicate, type="messages").launch()
    mylist = [1,2,3,4,5,6,7,8,9]
    findDuplicate(mylist)
    a = int(input("Enter first number:"))
    b = int(input("Enter second number:"))
    name = input("Enter your operation:")
    if name == "add":
        print(add(a,b))
    elif name == "sub":
        print(sub(a,b))
    else :
        print("Invalid opration")


    