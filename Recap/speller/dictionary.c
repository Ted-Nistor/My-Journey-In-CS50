// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert to lowercase
    char lower_word[strlen(word) + 1];
    for (int i = 0; word[i] != '\0'; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[strlen(word)] = '\0';
    // Compute the hash vakue for the lowercase word
    unsigned int index = hash(lower_word);
    // Traverse the linked list at the inidex to find a node with the matching word
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lower_word) == 0)
        {
            // If the word is found, return true
            return true;
        }
        cursor = cursor->next;
    }
    // If we reach the end of the list without finding the word, then it's not in the dictionary
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value * 31) + word[i];
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;

    }
    // Initialize word_count to 0
    int word_count = 0;
    // Read file word by word and add to hash table
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for the word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }
        // Copy the word into the new node
        strcpy(new_node->word, word);
        //Hash the word to get an index
        int index = hash(word);
        //Insert the new node into the hash table at the appropriate index
        if (table[index] == NULL)
        {
            table[index] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        // Increment word count
        word_count++;
    }
    // Close dictionary file
    fclose(file);
    //Return true if successful
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    unsigned int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            count++;
            cursor = cursor->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over each index of the hash table
    for (int i = 0; i < N ; i++)
    {
        // Free the linked list at the index, if it exists
        while (table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }
    }
    return true;
}
