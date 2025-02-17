********************************************************

 Noah Rossetti

 David Carmo

*********************************************************/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
skipsym = 1, identsym, numbersym, plussym, minussym,
multsym, slashsym, fisym, eqsym, neqsym, lessym, leqsym,
gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
periodsym, becomessym, beginsym, endsym, ifsym, thensym,
whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
readsym , elsesym} token_type;


//numerical value assigned to each token
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
			if( navigator->isWord == true && !bufferArr[i + 1])
			{
				return 1;
            }
		}
		else //if next node does not exist in the trie
		{
			//TODO remove debug print statement later
			printf(" %s ", bufferArr);
			printf("\n REMOVE LATER word not found in trie \n");
			return 0;
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
    return;
}



































int main(int argc, char *argv[]){
trieNode* root = createNode();

//int length_tracker;
char inputArr[50] = {"start"};
int j;
int cap;
int i=0;
int commentflag=0;
char temp;
char test;
char output[100];
char arrayofinput[1000];
char identifierTable[100][12];

char *words[ ] = { "null", "begin", "call", "const", "do", "else", "end", "if",
"odd", "procedure", "read", "then", "var", "while", "write"};



//for (int i = 0; i < argc; i++) {
  //      printf("%s\n", argv[i]);
    //}




     if(root != NULL)
    {
        printf("\nroot exists!\n");
    }


    for(int i = 0; i < 15; i++)
    {
        insertTrie(root, words[i]);
        printf("\n%s\n", words[i]);
    }


    while(strcmp(inputArr, "quit"))
    {
        scanf("%s", inputArr);


        printf("\nis the string ''%s'' present in the trie: %d\n", inputArr, checkTrie(root, inputArr));

    }


































FILE *inputfile = fopen("input", "r");
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

//while ((test = fgetc(inputfile)) != EOF) {

 //fprintf(outputfile,"%c",test);


//}

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

//might need to add more symbols




    if(arrayofinput[i]<'A'&&arrayofinput[i]>20){


    if(arrayofinput[i]=='+') printf("%d", plussym);

    else if(arrayofinput[i]=='-') printf("%d", minussym);

    else if(arrayofinput[i]=='*') printf("%d", multsym);

    else if(arrayofinput[i]==',') printf("%d", commasym);

    else if(arrayofinput[i]=='=') printf("%d", eqsym);

    else if(arrayofinput[i]=='.') printf("%d", periodsym);

    else if(arrayofinput[i]=='<') printf("%d", lessym);

    else if(arrayofinput[i]=='>') printf("%d", gtrsym);

    else if(arrayofinput[i]==';') printf("%d", semicolonsym);

    //more to do
    else if(arrayofinput[i]==':'){
        printf("made it here");

        if(arrayofinput[i+1]=='='){
            i++;
         printf(" becomesym %d", becomessym);}

        else printf(" bb %d", fisym);

    }




    else if(arrayofinput[i]=='(') printf("%d", lparentsym);

    else if(arrayofinput[i]==')') printf("%d", rparentsym);


    // This will identify and tokenize integers
  else if(arrayofinput[i]=='0'||arrayofinput[i]=='1'||arrayofinput[i]=='2'||arrayofinput[i]=='3'||arrayofinput[i]=='4'||arrayofinput[i]=='5'||arrayofinput[i]=='6'||arrayofinput[i]=='7'||arrayofinput[i]=='8'||arrayofinput[i]=='9'){

        //this finds the length of the integer to make sure it is valid
        j = i;
        while(arrayofinput[j]>'/'&&arrayofinput[j]<='9'){


            j++;
            //printf(" i:%d j:%d character:%c ", i, j, arrayofinput[j]);
        }

        //printf(" i:%d j:%d ", i, j);


        if(i<i+5){
                printf(" %d ", numbersym);
            for(int k = i; k<j; k++) printf("%c", arrayofinput[k]);
            i=j-1;

        }

        else printf(" error: integer too long ");


    }

    else printf(" Invalid symbol ");
    }
    else{

    //This is to differentiate between integers and  rese
    if(arrayofinput[i]>='a'&&arrayofinput[i]<='z'){
            int j =i;
    while(arrayofinput[j]>='a'&&arrayofinput[j]<='z'){
        char id_res[11]={0};
        
        int k=0;
        //i++;

        while(arrayofinput[j]>='a'&&arrayofinput[j]<='z'){
             id_res[k] = arrayofinput[j];
              j++;
              k++;
              printf(" %s ", id_res);
            checkTrie(root, id_res);
        }

    j++




    }
    }


        printf(" word |");

    }







printf("|");
}














   deleteTrie(root);







return 0;

}

