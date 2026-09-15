# == comparison operators, check if two values are equal or not
# is => checks if two variables refer to the same object in memory
a = 10 
b = 20
if a == b:
    print("a is equal to b")
else:
    print("a is not equal to b")

a = 10
b = a
if a is b:
    print("a is equal to b")
else:
    print("a is not equal to b")

# *args and **kwargs 
# *args is allows a function to accept any number of positional arguments, which are passed as a tuple.
# **kwargs(keywords arguments) allows a function to accept any number of keyword arguments, which are passed as a dictionary.
def my_function(*args, **kwargs):
    print("Positional arguments:", args)
    print("Keyword arguments:", kwargs) 

my_function(1, 2, 3, name="John", age=30)