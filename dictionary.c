// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
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
       char word[46];

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

                // hash word to obtain it hash value
               int q = hash(word);

               node *head = table[q];

               if(head==NULL)
               {
                 table[q] = n;
               }
               else
               {
                   n->next=table[q];
                   head=n;
               }
            }
                 fclose(inptr);
                    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
