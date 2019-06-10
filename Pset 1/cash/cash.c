// Stela Gavrilova
// 16 Feb 2019
// Problem Set 1

// A program that first asks the user how much is owed and then prints the minimum number of coins with which that change can be made.

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    float dollars;
    int quarters, dimes, nickels, pennies;
        // Execute this until the value is larger than 0
        do
        {
           // Get the dollar amount
           dollars = get_float("Change owed: ");
        }
        while 
            (dollars < 0);
        
    
        int cents = round(dollars*100);
               
        quarters = (cents / 25);
        dimes = ((cents % 25) / 10);
        nickels = (((cents % 25) % 10) / 5);
        pennies = ((((cents % 25) % 10) % 5) / 1);
    
        // Count the number of coins    
        int count = (quarters + dimes + nickels + pennies);
        printf("%i\n", count);
   
}
