/********************************************************

 Noah Rossetti

 David Carmo

*********************************************************/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum {
skipsym = 1, identsym, numbersym, plussym, minussym,
multsym, slashsym, fisym, eqsym, neqsym, lessym, leqsym,
gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
periodsym, becomessym, beginsym, endsym, ifsym, thensym,
whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
readsym , elsesym} token_type;


//int value assigned to each token
/*skipsym = 1, identsym = 2, numbersym = 3, plussym = 4, minussym = 5,
multsym = 6, slashsym = 7, fisym = 8, eqlsym = 9, neqsym = 10, lessym = 11, leqsym =
12, gtrsym = 13, geqsym = 14, lparentsym = 15, rparentsym = 16, commasym = 17,
semicolonsym = 18, periodsym = 19, becomessym = 20,
beginsym = 21, endsym = 22, ifsym = 23, thensym = 24, whilesym = 25, dosym = 26,
callsym = 27, constsym = 28, varsym = 29, procsym = 30, writesym = 31,
readsym = 32, elsesym = 33.*/


typedef struct trieNode trieNode;

struct trieNode
{
        int token;
        int isWord;
        trieNode* child[37];
        // adresses 0-25: alphabet

};


trieNode* createNode()
{
    trieNode* node = malloc(sizeof(trieNode));
    node->isWord = 0;
    return node;
}

//Warning! Following functions require null terminated input!
void insertTrie(trieNode* root, char* bufferArr)
{
        trieNode* navigator = root;

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

//searches dictionary and returns true 1 or false 0 if the search is successful
int checkTrie(trieNode* root, char* bufferArr)
{
	trieNode* navigator = root;

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
		else //if next node does not exist in the trie, search ends
		{
			return 0;
		}
    }
}

//loads token values for reserved words into the trie
void editToken(trieNode* root, char* bufferArr, int token)
{
    trieNode* navigator = root;
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
    	}
}

//retrieves token value upon successful dictionary search
int getToken(trieNode* root, char* bufferArr)
{
    trieNode* navigator = root;
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
		else //if next node does not exist in the trie,
		{
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

int main(int argc, char *argv[]){
trieNode* root = createNode();

char lexStr[1000][11];
int     lexToken[1000];

// int length_tracker;
char inputArr[50] = {"start"};
int j;
int cap;
int i=0;
int commentflag=0;
char temp;
char test;
char window[12];
int identtracker=0;
// output array position tracker
int opt;
int outputarray[1000]={ [0 ... 999]=-19};
char arrayofinput[1000];
char identifierTable[100][12];

char *words[ ] =
{ "null", "begin", "call", "const", "do", "else", "end", "if",
"odd", "procedure", "read", "then", "var", "while", "write"};

char* tokenWords[] =
	{"begin", "end", "if", "then", "while", "do", "call", "const",
	"var", "procedure", "write", "read", "else"};
    for(int i = 0; i < 15; i++)
    {
        insertTrie(root, words[i]);
        printf("\n%s\n", words[i]);
    }
    for(int i = 0; i < 13; i++)
    	{
        	editToken(root, tokenWords[i], i + 21);
    	}

//*******************************************************************************************************************************/

FILE *inputfile = fopen("input.txt", "r");

FILE *outputfile = fopen("output", "w");

  // Lets us know if there is a problem retrieving file ( will remove later )
if(inputfile==NULL){
    printf("no file ");

	return 0;
}

if(outputfile==NULL){
    printf("no file ");

	return 0;
}


// removes invisble characters, comments and whitespaces from text
 while ((test = fgetc(inputfile)) != EOF) {
         fprintf(outputfile,"%c",test);

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
                commentflag=1;
            }
            else temp=' ';
        }

        if(commentflag==1&&test=='*'){
                temp=test;
        continue;}

        if(commentflag==1&&temp=='*'){

            if(test=='\\'){

                commentflag=0;
                temp=' ';
                continue;
            }
            else temp=' ';

        }


        if(commentflag==0) {
            arrayofinput[i]=test;
            printf("%c", arrayofinput[i]);
            i++;
        }
    cap=i;
    }






for(i=0;i<cap;i++){
//printf(" i top of loop: %d ", i);
//might need to add more symbols




    if(arrayofinput[i]<'A'&&arrayofinput[i]>20){


    if(arrayofinput[i]=='+'){ printf("%d", plussym); outputarray[opt]=plussym; lexStr[opt] = '+'; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]=='-') { printf("%d", minussym); outputarray[opt]=minussym; lexStr[opt] = '-'; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]=='*') {printf("%d", multsym); outputarray[opt]=multsym; lexStr[opt] = '*'; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]==','){ printf("%d", commasym); outputarray[opt]=commasym; lexStr[opt] = ','; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]=='='){ printf("%d", eqsym); outputarray[opt]=eqsym; lexStr[opt] = '='; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]=='.'){ printf("%d", periodsym); outputarray[opt]=periodsym; lexStr[opt] = '.'; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]=='<'){printf("%d", lessym); outputarray[opt]=lessym; lexStr[opt] = '<'; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]=='>'){ printf("%d", gtrsym); outputarray[opt]=gtrsym; lexStr[opt] = '>'; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]==';'){ printf("%d", semicolonsym); outputarray[opt]=semicolonsym; lexStr[opt] = ';'; lexToken[opt] = outputarray[opt];}

    //more to do
    else if(arrayofinput[i]==':'){


        if(arrayofinput[i+1]=='='){
            i++;
            opt++;
         printf("%d", becomessym);
         outputarray[opt]=becomessym;
         lexStr[opt] = ":=";
         lexToken[opt] = outputarray[opt];
         
         }

        else{ printf("%d", fisym); outputarray[opt]=fisym; lexStr[opt] = "fi"; lexToken[opt] = outputarray[opt];} // i dont get this one, why is it here?

    }




    else if(arrayofinput[i]=='('){ printf("%d", lparentsym); outputarray[opt]=lparentsym; lexStr[opt] = "("; lexToken[opt] = outputarray[opt];}

    else if(arrayofinput[i]==')'){ printf("%d", rparentsym); outputarray[opt]=rparentsym; lexStr[opt] = ")"; lexToken[opt] = outputarray[opt];}


    // This will identify and tokenize integers
  else if(arrayofinput[i]=='0'||arrayofinput[i]=='1'||arrayofinput[i]=='2'||arrayofinput[i]=='3'||arrayofinput[i]=='4'||arrayofinput[i]=='5'||arrayofinput[i]=='6'||arrayofinput[i]=='7'||arrayofinput[i]=='8'||arrayofinput[i]=='9'){

        //this finds the length of the integer to make sure it is valid
        j = i;
        while(arrayofinput[j]>'/'&&arrayofinput[j]<='9'){
            j++;
        }


        if(j<i+5){
            char integerconverter[6];
            int convertednumber;
            int arrayfiller=0;
                printf(" %d ", numbersym);
                outputarray[opt]=numbersym;
            for(int k = i; k<j; k++){ printf("%c", arrayofinput[k]);
                integerconverter[arrayfiller]=arrayofinput[k];
                arrayfiller++;


            }
            //converts number from string to int
            convertednumber=atoi(integerconverter);
            opt++;
            i=j-1;
            outputarray[opt]=convertednumber;
            printf(" %d ", convertednumber);
        }
        //need to make this insert -777 iterate opt
        else printf(" error: integer too long ");


    }

    //need to make this insert number 3 then -777 iterate opt
    else printf(" Invalid symbol ");
    }

    //seperates words and identifiers
    else if (isalpha(arrayofinput[i])){
        int wordfound =0;
        int wordstart;
        int finalk;
        int length;
        char foundword[12];
        char foundidentifier[12];
         for(int k = i; arrayofinput[k]; k++)
    {
        if(isalpha(arrayofinput[k])==0&&isdigit(arrayofinput[k])==0) break;
        int spaceLeft = 0;

        while(arrayofinput[k + spaceLeft] && spaceLeft < 11)
        {
            if(isalpha(arrayofinput[k + spaceLeft])==0&&isdigit(arrayofinput[k + spaceLeft])==0) break;
            spaceLeft++;
        }

        for(int l = 0; l < spaceLeft ; l++)
        {
            if(isalpha(arrayofinput[k + l])==0&&isdigit(arrayofinput[k + l])==0) break;
            window[l] = arrayofinput[k + l];
        }
        window[spaceLeft] = '\0';
        //printf("\nwindow is:%s\n", window);

        for(int l = 0; l < spaceLeft; l++)
        {
            char buffer[12];
            buffer[0] = '\0';
            strncat(buffer, window, l + 1);
           // printf("\nbuffer is:%s\n", buffer);
         if(checkTrie(root, buffer)){
            //i+strlen(buffer);
          printf(" reserved word found ");
          strcpy(foundword, buffer);
           // length=strlen(buffer);
           printf(" %s ", foundword);
           printf(" token: %d ",getToken(root, foundword));
            wordfound=1;
            break;
          }
          if(wordfound==1) break;
        }
        //keeps track of where a reserved word starts/ where a identifier ends
        finalk=k;
        //printf(" %d ", k);
        // printf(" %d ", i);
         if(wordfound==1) break;
    }

    //printf("final %d ", finalk);
    if(finalk>i&&wordfound==0){
        for(int k = i; k<finalk; k++)
        foundidentifier[k-i]=arrayofinput[k];
         outputarray[opt]=2;
    opt++;
    outputarray[opt]=identtracker;
    strcpy(identifierTable[identtracker],foundidentifier);
    printf(" identifier from table %s ", identifierTable[identtracker]);
    identtracker++;

    i=finalk;
    //printf(" i after no word: %d ", i);
    }
    else if(wordfound==1){
        for(int k = i; k<finalk; k++)
        foundidentifier[k-i]=arrayofinput[k];
        outputarray[opt]= getToken(root, foundword);
    i=finalk+strlen(foundword)-1;

   // printf(" i after word: %d ", i);
    }
    else{ foundidentifier[0]=arrayofinput[i];
    printf(" identifier: %s ", foundidentifier);
    outputarray[opt]=2;
    opt++;
    outputarray[opt]=identtracker;
    strcpy(identifierTable[identtracker],foundidentifier);
    printf(" identifier from table %s ", identifierTable[identtracker]);
    identtracker++;

    i=finalk;
   // printf(" i after no word: %d ", i);
    }
    //printf(" identifier: %s ", foundidentifier);
    }


printf("|");
opt++;
}

printf(" \n ");
for(i=0;i<opt;i++){


    printf("%d ", outputarray[i]);
}



for(i=0;i<opt;i++){
if(outputarray[i]==-19)continue;
if(outputarray[i]==2){
    fprintf(outputfile, "%d ", outputarray[i]);
    i++;
    fprintf(outputfile, "%s ",identifierTable[outputarray[i]]);
}
else{
    fprintf(outputfile,"%d ",outputarray[i]);
}

}













    deleteTrie(root);

    return 0;

}
