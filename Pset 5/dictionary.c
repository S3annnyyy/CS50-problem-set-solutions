// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//creating word counter
int wordCount = 0;

//number of buckets in hashtable
const unsigned int N = 26;

//Hash Table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int key = hash(word);
    node *nodePtr = table[key];

    while (nodePtr != NULL)
    {
        if (strcasecmp(nodePtr->word, word) == 0)
        {
            return true;
        }
        nodePtr = nodePtr->next;
    }
    return false;
}

// Hashes word to a number(hash function) source: hash function posted on reddit by delipity
unsigned int hash(const char *word)
{
    int value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        value += tolower(word[i]);
    }
    return value % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open file
    FILE *file = fopen(dictionary, "r");

    //checking if file is null
    if (file == NULL)
    {
        return false;
    }

    //setting all buckets to NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char tempword[LENGTH + 1];

    //reading strings from the file using scanf
    while (fscanf(file, "%s\n", tempword) != EOF)
    {
        //allocating memory for scanned words
        node *tempnode = malloc(sizeof(node));

        //adding data into node
        strcpy(tempnode->word, tempword);

         // Initializes & calculates index of word for insertion into hashtable
        int key = hash(tempword);

        //inserting new nodes into beginning of list
        if (table[key] == NULL)
        {
            tempnode->next = NULL;
            table[key] = tempnode;

        }
        else
        {
            tempnode->next = table[key];
            table[key] = tempnode;

        }
        wordCount++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //using for loop to go through all the buckets to unload
    for (int i = 0; i < N; i++)
    {
        node *nodePtr = table[i];

        //while loop to unload
        while (nodePtr != NULL)
        {
            //create new node to not abandon the rest of linked list
            node *deletePtr = nodePtr;
            nodePtr = nodePtr->next;
            free(deletePtr);
        }
        table[i] = NULL;
    }
    return true;
}
