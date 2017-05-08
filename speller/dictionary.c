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
    // letter as int
    int aInt = (int)'a';
    int zInt = (int)'z';
    
    // set current node to first node
    trie* currNode = firstnode;
    
    // looping through each letter in word
    int i = 0;
    while(word[i] != '\0')
    {
        char ch = word[i];
        
        
        // find is ch is apostrophe
        if (word[i] == '\'')
        {
            ch = zInt + 1;
        }
        // converting letter between 0 and 25
        int childIndex = tolower(ch) - aInt;
        
        if (currNode -> children[childIndex] != NULL)
        {
            currNode = currNode -> children[childIndex];
            i++;
        }
        else
        {
            return false;
        }
        
    }
    
    
        if (currNode -> isWord == true)
        {
            
            return true;
        }
        else
        {
            return false;
        }
    
     
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