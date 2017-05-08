#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

/** 
 * Implementing a trie datastructure
 */
 typedef struct trie
 {
    bool isWord;
    struct trie* children[27];
 }
 trie;
 
 trie* firstnode;
 
 // function to freenode
void freenode(trie* firstnode)
{
    for(int i = 0; i < 27; i++)
    {
        if (firstnode -> children[i] != NULL)
        {
            freenode(firstnode -> children[i]);
        }
    }
    free(firstnode);
    return;
}
 // total number of words counter
 int noOfWords = 0;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
 return true;
    
     
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO

   return true;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
  
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
   
    
}