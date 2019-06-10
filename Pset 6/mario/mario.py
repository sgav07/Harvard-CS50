# Include special functions from cs50
from cs50 import get_int

# Prompt the user to provide a number
height = get_int("Height: ")

# Check if usage is correct and the user has entered a number
while False:
    height = get_int("Height: ")
if height < 1 or height > 8:
    height = get_int("Height: ")

# Loop through the lines
for i in range(height):
    for j in range(height-i-1):
        print(" ", end="")
    for k in range(height-(height-i-1)):
        print("#", end="")
    print()
