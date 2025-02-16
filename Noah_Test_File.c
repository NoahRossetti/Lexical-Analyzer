/********************************************************

 Noah Rossetti

 David Carmo

*********************************************************/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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




int main(int argc, char *argv[]){


//int length_tracker;
int j;
int cap;
int i=0;
int commentflag=0;
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






        printf(" word |");

    }







printf("|");
}






















return 0;

}
