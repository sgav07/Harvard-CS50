#Import get_string function from cs50 library
from cs50 import get_string

#Promp the user to enter his/her name
name = get_string("What is your name?\n")

#Print hello + name
print("hello,", name, end="")
print()