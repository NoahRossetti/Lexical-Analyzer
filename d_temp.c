/********************************************************

 Noah Rossetti

 David Carmo //testing out a trie system to id lexemes on my machine, will upload if it pans out

*********************************************************/


/*
running list of things to do

- make running list of things to do
- structure to identify words for lexeme table and token list (relearning all of tries brb)

*/
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



void createTrieRoot()
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




int main(int argc, char *argv[]){




int i=0;
int commentFlag=0;
char temp;
char test;
char output[100];
char arrayofinput[1000];
char identifierTable[100][12];

char *word[ ] = { "null", "begin", "call", "const", "do", "else", "end", "if",
"odd", "procedure", "read", "then", "var", "while", "write"};



//for (int i = 0; i < argc; i++) {
  //      printf("%s\n", argv[i]);
    //}




FILE *inputfile = fopen("input", "r");

  // Lets us know if there is a problem retrieving file ( will remove later )
if(inputfile==NULL){
    printf("no file ");

	return 0;
}


// removes invisble characters, comments and whitespaces from text
 while ((test = fgetc(inputfile)) != EOF) {
        //removes white spaces
        if(test==' ') continue;

        //removes invisible characters
        if(test=='\n'||test=='\t') continue;
        //arrayofinput[i]=test;

        //starts check for start of comments
        if(test=='/') {
            temp=test;
            continue;}

        if(temp=='/'){
            if(test=='*'){
                commentFlag=1;
            }
            else temp=' ';
        }

        if(commentFlag==1&&test=='*'){
                temp=test;
        continue;}

        if(commentFlag==1&&temp=='*'){

            if(test=='\\'){

                commentFlag=0;
                temp=' ';
                continue;
            }
            else temp=' ';

        }


        if(commentFlag==0) {
            arrayofinput[i]=test;
            printf("%c", arrayofinput[i]);
            i++;
        }

    }

























return 0;

}



