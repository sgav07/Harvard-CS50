#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// A program called caesar that enables the user to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime. The program then asks for plaintext promptline that later on is encrypted and returned to the user.

int main(int argc, string argv[])
{
    string plaintext;
    // Check if 2 words are entered
    if (argc != 2)
    {
        printf("./caesar key\n");
        return 1;
    }
    // In case 2 words are entered indeed, check if the second string is actually an integer to be used later as a key
    int key = atoi(argv[1]);
    for (int i=0; i<strlen (argv[1]); i++)
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf ("Usage: ./caesar key\n");
            exit(1);
        }
        else 
        {
            plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int j=0; j < strlen (plaintext); j++)
            {
                // Check for small letters:
                if (plaintext[j]>=97 && plaintext[j]<=122)
                {
                    printf("%c", (((( (int)plaintext[j] + key) - 97) % 26) + 97) );
                }
                // Check for capital letters:
                else if (plaintext[j]>=65 && plaintext[j]<=90)
                {
                    printf("%c", (((( (int)plaintext[j] + key) - 65) % 26) + 65) );
                }
                // Keep all other signs as they are
                else  
                {
                    printf("%c", plaintext[j]);
                }
            }
            printf("\n");
            return 0;
        }
}