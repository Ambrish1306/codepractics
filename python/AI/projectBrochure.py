import os
import sys

from openai import OpenAI
from dotenv import load_dotenv
#from IPython.display import Markdown, display

PROJECT_DIR = os.path.dirname(os.path.abspath(__file__))
if PROJECT_DIR not in sys.path:
    sys.path.insert(0, PROJECT_DIR)



MODEL_NAME = "llama3.2"

openai = OpenAI(base_url='http://localhost:11434/v1', api_key='ollama')
load_dotenv()
