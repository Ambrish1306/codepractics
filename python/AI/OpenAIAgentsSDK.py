from openai import AsyncOpenAI

OLLAMA_BASE_URL = "http://localhost:11434/v1"
ollama_client = AsyncOpenAI(base_url=OLLAMA_BASE_URL, api_key="ollama")
