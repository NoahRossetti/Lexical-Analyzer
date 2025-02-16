#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
{
skipsym = 1, identsym, numbersym, plussym, minussym,
multsym, slashsym, fisym, eqsym, neqsym, lessym, leqsym,
gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
periodsym, becomessym, beginsym, endsym, ifsym, thensym,
whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
readsym , elsesym
} token_type;


//numerical value assigned to each token
/*skipsym = 1, identsym = 2, numbersym = 3, plussym = 4, minussym = 5,
multsym = 6, slashsym = 7, fisym = 8, eqlsym = 9, neqsym = 10, lessym = 11, leqsym =
12, gtrsym = 13, geqsym = 14, lparentsym = 15, rparentsym = 16, commasym = 17,
semicolonsym = 18, periodsym = 19, becomessym = 20,
beginsym = 21, endsym = 22, ifsym = 23, thensym = 24, whilesym = 25, dosym = 26,
callsym = 27, constsym = 28, varsym = 29, procsym = 30, writesym = 31,
readsym = 32, elsesym = 33.*/

char* loadWords[] = {
"skip" , "ident" , "number", "plus", "minus",
"mult", "slash" , "fi", "eq", "neq", "les", "leq",
"gtr", "geq", "lparent", "rparent", "comma", "semicolon",
"period", "becomes", "begin", "ends", "if", "then",
"while", "do", "call", "const", "var", "proc", "write",
"read" , "else"
}

typedef struct trieNode trieNode
{
        int data;
        bool isWord = 0; //default value is 0
        trieNode* children[37];
        // values for trie structure are as follows: 
        // adresses 0-25: alphabet
        // addresses 26-36: decimal values 0-9
        // address 37: '_' underscore

        //TODO: if ya find another character that should be represented in the trie lmk pls

}



trieNode* createTrieRoot()
{
        trieNode* root = malloc(1 * sizeof(trieNode));
        return root;
}

void insertTrie(char* bufferArr, trieNode* root)
{
        trieNode* navigator = root;

        //TODO: assuming null terminated by strcpy or something, might need to put a sentinel
        for(int i = 1; bufferArr[i]; i++)
        {
                if(navigator->children[bufferArr[i] - 'a'])
                {
                        navigator = navigator->children[bufferArr[i] - 'a'];

                        if(!bufferArr[i + 1])//if the next letter is the terminator, word flag is deployed
                        {
                                navigator->isWord = 1;
                        }
                }
                else
                {
                        navigator->children[bufferArr[i] - 'a'] = malloc(1 * sizeof(trieNode));
                        navigator = navigator->children[bufferArr[i] - 'a'];

                        if(!bufferArr[i + 1])//if the next letter is the terminator, word flag is deployed
                        {
                                navigator->isWord = 1;
                        }
        
                }
        }
}



bool checkTrie(trieNode* root, char* bufferArr)
{	
	trieNode* navigator = root;
	//TODO: again assuming its null terminated
	for(int i = 0; bufferArr[i]; i++)
	{
		if(navigator->[bufferArr[i] - 'a']) //checks if node exists in the trie
		{
			navigator = navigator->[bufferArr[i] - 'a'];
			if( navigator->isWord == true && !bufferArr[i + 1])
			{
				return true;
		}
		else
		{
			//TODO remove debug print statement later
			printf("\n REMOVE LATER word not found in trie \n");
			return false;
		}
}



