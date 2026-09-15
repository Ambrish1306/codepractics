




def my_decorator(funce):
    def wrapper(*args, **kwargs):
        print("Before the function is called.")
        result = funce(*args, **kwargs)
        print("After the function is called.")
        return result
    return wrapper

@my_decorator
def say_hello(name):
    print(f"Hello, {name}!") 

say_hello("Alice")  # This will print the messages before and after the function is called, as well as the greeting.   

@my_decorator
def add(a, b):
    return a + b

print(add(5, 3))  # This will print the messages before and after the function is called, as well as the result of the addition.

