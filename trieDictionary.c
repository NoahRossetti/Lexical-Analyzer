// trie dictionary attempt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

/*
char* loadWords[] = {
"skip" , "ident" , "number", "plus", "minus",
"mult", "slash" , "fi", "eq", "neq", "les", "leq",
"gtr", "geq", "lparent", "rparent", "comma", "semicolon",
"period", "becomes", "begin", "ends", "if", "then",
"while", "do", "call", "const", "var", "proc", "write",
"read" , "else"
};
*/





// begin = 21, end = 22, if = 23, then = 24, while = 25, do = 26, call = 27, const = 28, var = 29, procedure = 30, write = 31, read = 32, else = 33

typedef struct trieNode trieNode;

struct trieNode 
{
        int token;
        int isWord;
        trieNode* child[37];
        // values for trie structure are as follows: 
        // adresses 0-25: alphabet
        // addresses 26-36: decimal values 0-9
        // address 37: '_' underscore

        //TODO: if ya find another character that should be represented in the trie lmk pls

};


trieNode* createNode()
{
    trieNode* node = malloc(sizeof(trieNode));
    node->isWord = 0;
    return node;
}


void insertTrie(trieNode* root, char* bufferArr)
{
        trieNode* navigator = root;

        //TODO: assuming null terminated by strcpy or something, might need to put a sentinel
        for(int i = 0; bufferArr[i]; i++)
        {
                if(navigator->child[bufferArr[i] - 'a'])
                {
                        navigator = navigator->child[bufferArr[i] - 'a'];

                        if(!(bufferArr[i + 1]))//if the next letter is the terminator, word flag is deployed
                        {
                                navigator->isWord = 1;
                                printf("\nstring: %s inserted!\n", bufferArr);
                        }
                }
                else
                {
                        navigator->child[bufferArr[i] - 'a'] = createNode();
                        navigator = navigator->child[bufferArr[i] - 'a'];

                        if(!bufferArr[i + 1])//if the next letter is the terminator, word flag is deployed
                        {
                                navigator->isWord = 1;
                        }
        
                }
        }
}



int checkTrie(trieNode* root, char* bufferArr)
{	
	trieNode* navigator = root;
	//TODO: again assuming its null terminated
	for(int i = 0; bufferArr[i]; i++)
	{
		if(navigator->child[bufferArr[i] - 'a']) //checks if next node exists in the trie
		{
			navigator = navigator->child[bufferArr[i] - 'a'];
			if( navigator->isWord == 1 && !bufferArr[i + 1])
			{
				return 1;
            }
		}
		else //if next node does not exist in the trie 
		{
			//TODO remove debug print statement later
			printf("\n REMOVE LATER word not found in trie \n");
			return 0;
		}
    }
}

void editToken(trieNode* root, char* bufferArr, int token)
{
    trieNode* navigator = root;
	//TODO: again assuming its null terminated
	for(int i = 0; bufferArr[i]; i++)
	{
		if(navigator->child[bufferArr[i] - 'a']) //checks if next node exists in the trie
		{
			navigator = navigator->child[bufferArr[i] - 'a'];
			if( navigator->isWord == 1 && !bufferArr[i + 1])
			{
				navigator->token = token;
            }
		}
		else //if next node does not exist in the trie 
		{
			//TODO remove debug print statement later
			printf("\n REMOVE LATER word not found in trie \n");
		}
    }
}

int getToken(trieNode* root, char* bufferArr)
{
    trieNode* navigator = root;
	//TODO: again assuming its null terminated
	for(int i = 0; bufferArr[i]; i++)
	{
		if(navigator->child[bufferArr[i] - 'a']) //checks if next node exists in the trie
		{
			navigator = navigator->child[bufferArr[i] - 'a'];
			if( navigator->isWord == 1 && !bufferArr[i + 1])
			{
				return navigator->token;
            }
		}
		else //if next node does not exist in the trie 
		{
			//TODO remove debug print statement later
			printf("\n REMOVE LATER word not found in trie \n");
            return -99;
		}
    }
}


void deleteTrie(trieNode* root)
{
    if(!root) // if root is null, function ends
    {
        return;
    }

    for(int i = 0; i < 37; i++)
    {
        if(root->child[i]) // if child node exists, call the function recursively on that subtrie
        {
            deleteTrie(root->child[i]);
        }
    }

    free(root);

}


void main()
{
    char inputArr[50] = {"start"};

    char *words[ ] = { "null", "begin", "call", "const", "do", "else", "end", "if",
                        "odd", "procedure", "read", "then", "var", "while", "write"};
    
    char* tokenWords[] = {"begin", "end", "if", "then", "while", "do", "call", "const", "var", "procedure", "write", "read", "else" };  
    
    trieNode* root = createNode();

    if(root != NULL)
    {
        printf("\nroot exists!\n");
    }


    for(int i = 0; i < 15; i++)
    {
        insertTrie(root, words[i]);
        printf("\n%s\n", words[i]);
    }

    for(int i = 0; i < 13; i++)
    {
        editToken(root, tokenWords[i], i + 21);
    }

    for(int i = 0; i < 13; i++)
    {
        int token = getToken(root, tokenWords[i]);
        printf("\n%d\n", token);
    }

    
    while(strcmp(inputArr, "quit"))
    {
        scanf("%s", inputArr);


        printf("\nis the string ''%s'' present in the trie: %d\n", inputArr, checkTrie(root, inputArr));

    }

    deleteTrie(root);
}
