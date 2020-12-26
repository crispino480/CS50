// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

//count word into the dictionary
 int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
 int n = strlen(word);
    char word_copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    // Adds null terminator to end string
    word_copy[n] = '\0';
    // Initializes index for hashed word
    int h = hash(word_copy);
    // Sets cursor to point to same address as hashtable index/bucket
    node *cursor = table[h];
    // Sets cursor to point to same location as head

    // If the word exists, you should be able to find in dictionary data structure.
    // Check for word by asking, which bucket would word be in? hashtable[hash(word)]
    // While cursor does not point to NULL, search dictionary for word.
    while (cursor != NULL)
    {
        // If strcasecmp returns true, then word has been found
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
        // Else word has not yet been found, advance cursor
        else
        {
            cursor = cursor->next;
        }
    }
    // Cursor has reached end of list and word has not been found in dictionary so it must be misspelled
    return false;
}
// Hashes word to a number
//Hash function rom CS50,math using all the letter
unsigned int hash(const char *word)
{
    // TODO
    int sum=0;
    for(int i = 0; i < strlen(word); i++)
    {
        sum+=tolower(word[i]);
    }
    return (sum%N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //To open th dictionary
    FILE *inptr = fopen(dictionary,"r");
    if(inptr == NULL)
    {
     return false;
    }
       char word[LENGTH +1];

       //read words from the dictionary into word
        while(fscanf(inptr,"%s", word) !=EOF)
             {
               node *n = malloc(sizeof(node));
               if(n==NULL)
                {
                 unload();
                 return false;
                }
                //copy the word into the char field of that node
                 strcpy(n->word,word );
                 n->next=NULL;
                 word_count++;

                // hash word to obtain it hash value
               int q = hash(word);

               if(table[q]==NULL)
               {
                 table[q] = n;
               }
               else
               {
                   n->next=table[q];
                   table[q]=n;
               }
            }
                 fclose(inptr);
                    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *cursor =NULL;
    node *tmp=NULL;

    for(int i=0; i<N ; i++)
    {
     while(table[i]==NULL)
     {
         i++;
     }
     cursor = table[i];

    while(cursor!=NULL)
    {
        tmp=cursor;
        cursor=cursor->next;
        free(tmp);
    }

    }
    return true;
}
