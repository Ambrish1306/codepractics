from openai import OpenAI
from dotenv import load_dotenv
import tiktoken

load_dotenv()

OLLAMA_BASE_URL = "http://localhost:11434/v1"
MODEL_NAME = "llama3.2"

openai = OpenAI(base_url=OLLAMA_BASE_URL, api_key="ollama")

# tiktoken does not auto-map Ollama model names like "llama3.2"
# so use an explicit tokenizer name instead.
encoding = tiktoken.get_encoding("cl100k_base")

text = (
    "Hi my name is Ambrish Pandey and I am a software engineer. "
    "I have been working in the field of software development for over 5 years. "
    "I specialize in Python and have experience with various frameworks and libraries. "
    "In my free time, I enjoy learning about new technologies and contributing to open source projects."
)

tokens = encoding.encode(text)
print(f"Total tokens: {len(tokens)}")

for token_id in tokens[:20]:
    token_text = encoding.decode([token_id])
    print(f"{token_id} = {token_text!r}")

response = openai.chat.completions.create(
    model=MODEL_NAME,
    messages=[{"role": "user", "content": "Say hello in one sentence."}],
    stream=True

)

print("Model reply:")
print(response.choices[0].message.content)