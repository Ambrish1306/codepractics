
import os
from dotenv import load_dotenv
from IPython.display import Markdown, display

def add(a, b):
    return a + b

number = [1,2,3,4,5]

print("The numbers are:", number[0])  # This will raise an error because sets are unordered and do not support indexing

if __name__ == "__main__":
    result = add(5, 3)
    print("The sum is:", result)
