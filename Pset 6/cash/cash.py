# Import the get_float function from cs50 modules
from cs50 import get_float

# Prompt the user to provide a dollar amount
amount = get_float("Change owed: ")

# Check if usage is correct and the user has entered a number
while False:
    amount = get_float("Change owed: ")
if amount < 0:
    amount = get_float("Change owed: ")

# Turn the value in cents:
cents = int(round(amount*100))

# Use modulo function to check for the number of coins from each group
quarters = int((cents / 25))
dimes = int(((cents % 25) / 10))
nickels = int((((cents % 25) % 10) / 5))
pennies = int(((((cents % 25) % 10) % 5) / 1))

# Sum the final number of coins
coins = quarters + dimes + nickels + pennies

# Print the final number of coins owed
print(f"{coins:.0f}")