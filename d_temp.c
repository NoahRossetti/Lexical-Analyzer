/********************************************************

 Noah Rossetti

 David Carmo

*********************************************************/


/*
running list of things to do

- 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
{
skipsym = 1, identsym = 2, numbersym = 3, plussym = 4, minussym = 5,
multsym = 6, slashsym = 7, fisym = 8, eqlsym = 9, neqsym = 10, lessym = 11, leqsym =
12, gtrsym = 13, geqsym = 14, lparentsym = 15, rparentsym = 16, commasym = 17,
semicolonsym = 18, periodsym = 19, becomessym = 20,
beginsym = 21, endsym = 22, ifsym = 23, thensym = 24, whilesym = 25, dosym = 26,
callsym = 27, constsym = 28, varsym = 29, procsym = 30, writesym = 31,
readsym = 32, elsesym = 33
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

    }

























return 0;

}
