// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#include "dictionary.h"


// define number of buckets in a hash table
#define hashtable_size 10000


// define a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Define global variables
int dictionary_word_counter = 0;
node *hashtable[hashtable_size] = {NULL};


// Create hash function. Source: https://stackoverflow.com/questions/7666509/hash-function-for-string

unsigned hash(char *word)
{
    unsigned hashval;

    for (hashval = 0; *word != '\0'; word++)
        hashval = *word + 31*hashval;
    return hashval % hashtable_size;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Create an array for word to be stored in
    char word[LENGTH+1];


    // Scan through the dictionary word by word, loading each word into the hash table
    while (fscanf(file, "%s", word) != EOF)
    {
         // Increase dictionary word counter accordingly
        dictionary_word_counter++;

        // Allocate space to store each new word
        node *new_node = malloc(sizeof(node));

        // Save the current word in the node's char property
        strcpy(new_node->word, word);

        // Generate hash for the word
        int index = hash(word);

        // Insert node into hashtable
        if ( (hashtable[index]) == NULL) // check if the array location is null
        {
            hashtable[index] = new_node;
            new_node->next = NULL;
        }

        else
        // Meaning there is already a node at that location and we assign our node as the head of the linked list
        {
            // Store the pointer to the old node in a temp variable
            new_node->next = hashtable[index];

            // Assign the new node to the head of the list
            hashtable[index] = new_node;
        }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}






// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char temp[LENGTH + 1];
    int word_length = strlen(word);


    // Change all letters to lowercase
    for(int i = 0; i < word_length; i++)
    {
        temp[i] = tolower(word[i]);
    }
    temp[word_length] = '\0';


    // Generate the hash index of the word
    int index = hash(temp);

    // In case hashtable is empty at the respective index, return false
    if (hashtable[index] == NULL)
    {
        return false;
    }

    // Traverse the linked list at the array index
    node *trav = hashtable[index];

    // Loop through the words and compare if node->next is not null
    while (trav != NULL)
    {
        if ( strcmp (temp, trav->word) == 0)
        {
            return true;
        }

        trav = trav->next;
    }

    // If the word is not found, return false
    return false;
}




// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (dictionary_word_counter > 0)
    {
        return dictionary_word_counter;
    }

    else
        return 0;
}





// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Create a variable to go through the index
    int index = 0;

    while (index < hashtable_size)
    {
        // If hashtable is empty at index, go to next index
        if (hashtable[index] == NULL)
        {
            index++;
        }

        // If hashtable is not empty, iterate through nodes and free trav
        else
        {
            while (hashtable[index] != NULL)
            {
                node *trav = hashtable[index];
                hashtable[index] = trav->next;
                free (trav);
            }

            index++;
        }
    }
    return true;
}