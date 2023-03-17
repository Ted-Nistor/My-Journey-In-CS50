# from cs50 import get_int

# x = get_int("x: ")
# y = get_int("y ")

x = int(input("x: "))
y = int(input("y: "))
z = x / y

print(x + y)
print (z)
print (f"{z:.50f}") #if you want the program to show you a specific number
#of decimals

# you still have floating-point imprecission
# in python you can count as looong as you want so python doesn
# have integer overflow