from langchain_openai import ChatOpenAI
from IPython.display import Markdown, display

llm = ChatOpenAI(
    model="llama3.2",
    base_url="http://localhost:11434/v1",
    api_key="ollama",
    streaming=True
)
response = llm.invoke([{"role": "user", "content": "Tell a joke for a student on the journey to becoming an expert in LLM Engineering"}])

display(Markdown(response.content))
print(response.content)

