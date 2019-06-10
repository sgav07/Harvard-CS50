# Import the get_string function from cs50 modules and argv from sys library
from cs50 import get_string
from sys import argv

# Check if usage is correct and the user has entered exactly 2 arguments
if not len(argv) == 2:
    exit("usage: python caesar.py k")

# Check if the second argument is an integer to be later used as a key (Source: https://stackoverflow.com/questions/1265665/how-can-i-check-if-a-string-represents-an-int-without-using-try-except)
try:
    int(argv[1])
except ValueError:
    exit("usage: python caesar.py k")

# Prompt the user to provide string to be encrypted
text = get_string("plaintext: ")
print("ciphertext: ")

key = int(argv[1])

# Iterate over each character of the provided text
for j in range(len(text)):

    # Check for small letters
    if ord(text[j]) >= 97 and ord(text[j]) <= 122:
        c = chr((((ord(text[j]) + key) - 97) % 26) + 97)
        print(c, end="")

    # Check for capital letters
    elif ord(text[j]) >= 65 and ord(text[j]) <= 90:
        c = chr((((ord(text[j]) + key) - 65) % 26) + 65)
        print(c, end="")

    # Keep all other signs as they are
    else:
        print(text[j], end="")
print()