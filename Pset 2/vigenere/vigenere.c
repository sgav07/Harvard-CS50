#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Vigenere`s cipher is an improvement of Caesar`s cipher by encrypting messages using a sequence of keys or by a keyword.
// When starting the program the user is entering the keyword that will be used for encryption and then he is prompted to provide the text that he wants to be encrypted

int shift (char c);
    
int main(int argc, string argv[])
{
    // Check for correct input of 2 strings - the function and only one more string
    string plaintext;
    string keyword = argv[1];
    if (argc != 2)
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    
    // Check if the second string from the input is something other than alphabetical
    for (int i=0, n = strlen (keyword); i < n; i++)
       
        if (! isalpha (keyword[i]))
        {
            printf ("Usage: ./vigenere keyword\n");
            return 1;
        }
    
    // Get the plaintext and proceed to ciphertext excryption:
       
            plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            
            // Let's work out on the keyword and turn all letters to small ones since the numerical key to capital and small letters is the same
            int keyLen = strlen(argv[1]);
            int keyCount = 0;
            for (int k=0; k < strlen(keyword); k++)
                keyword[k] = tolower(keyword[k]);
     
            // Start encrypting the entered plaintext
            for (int j=0; j < strlen (plaintext); j++)
            {
                // Make the key start over again if smaller than plaintext and turn the key to the expected value (e.g. "a" to 0)
                char key = keyword[(keyCount % keyLen)] - 97;
               
                // Go through the plaintext and encrypt the small letters:
                if (plaintext[j]>=97 && plaintext[j]<=122)
                {
                    printf("%c", (((( (int)plaintext[j] + key) - 97) % 26) + 97) );
                    keyCount++;
                }
                
                // Go through the plaintext and encrypt the capital letters:
                else if (plaintext[j]>=65 && plaintext[j]<=90)
                {
                    printf("%c", (((( (int)plaintext[j] + key) - 65) % 26) + 65) );
                    keyCount++;
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
