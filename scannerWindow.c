#include <stdio.h>
#include <string.h>

void main()
{
    char inputArr[] = { "nullbegincallconstdoelseendifoddprocedurereadthenvarwhilewrite"};
    char window[12];


    for(int i = 0; inputArr[i]; i ++)
    {   
        int space = 1;

        while(inputArr[i + space] != '\0' && space <= 11)
        {
            space++;
            printf("\nspace is:%d\n", space);
        }

        for(int k = 0; k < space ; k++)
        {
            window[k] = inputArr[i + k];
            printf("\nk is: %d", k);
        }
        window[space + 1] = '\0';
        printf("\nwindow is:%s\n", window);

        for(int k = 0; k < space; k++)
        {
            char bufferArr[12];
            bufferArr[0] = '\0';
            strncat(bufferArr, window, k + 1);
            printf("\nbuffer is:%s\n", bufferArr);
            printf("\nk is: %d", k);
        }
    }


}
