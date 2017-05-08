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
    
     // integer mapping for a and z
   int aInt = (int)'a';
   int zInt = (int)'z';
   
   // opening the dictionary file
   FILE* fp = fopen(dictionary,"r");
   
   // sanity check for null returned reference
   if (fp == NULL)
   {
    return false;
   }
   // mallocking memory for first node
   firstnode = (trie*) malloc(sizeof(trie));
   
   // integer for current position in children array
   int character = 0;
   
   // cursor node
   trie* currNode = NULL;
   
   // looping through dictionary until end of file is encountered
   while(EOF != (character = fgetc(fp)))
   {
   		// setting current node to first node
   		currNode = firstnode;
   		
   		// iterating through character and adding each 
   		// letter to children until "\n"
   		for(; character != '\n'; character = fgetc(fp))
   		{
   			// if apostrophe then store in 
   			if (character == '\'')
   			{
   				character = zInt + 1;
   			}
   			
   			// if the character is not in trie...create one
   			if (currNode -> children[character - aInt] == NULL)
   			{
   				// malloc a new node
   				currNode -> children[character - aInt] = (trie*)malloc(sizeof(trie));
   				currNode = currNode -> children[character - aInt];
   			}
   			// got to address in children
   			else
   			{
   				currNode = currNode -> children[character - aInt];
   			}
   			
   		}
   		currNode -> isWord = true;
   		noOfWords++;
   }
   
   // close the dictionary file
   fclose(fp);
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