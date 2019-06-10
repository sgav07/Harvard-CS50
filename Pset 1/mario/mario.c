#include <cs50.h>
#include <stdio.h>

// The user will be prompted to provide input from 1 to 8, inclusive
// Then the program takes the input and builds a pyramid with the provided number of blocks

int main(void)
{
    int height;
        do
            height = get_int ("Height: ");
        while 
             ((height < 1) || (height > 8));
    
     if  ((height >= 1) && (height <= 8))
        for (int i = 1; i <= height; i++)
        {
            for (int s=i; s<height; s++)
            {
               printf(" ");
            }    
            for (int k=1; k <= i; k++)
            {
                printf ("#"); 
            }   
        printf("\n");
        }
   }

