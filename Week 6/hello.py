from cs50 import get_string


answer = get_string("what's your name?")
print("hello, " + answer)  # concactenation
print("hello,",answer) # it accepts and automatically gives you space between
print(f"hello, {answer}") # f stants for print format ,similar to printf in C
# print("hello, world")
