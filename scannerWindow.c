#include <stdio.h>
#include <string.h>

void main()
{
    char inputArr[] = { "nullbegincallconstdoelseendifoddprocedurereadthenvarwhilewrite"};
    char window[12];


    for(int i = 0; inputArr[i]; i ++)
    {   
        int spaceLeft = 0;

        while(inputArr[i + spaceLeft] && spaceLeft < 11)
        {
            spaceLeft++;
            printf("\nspaceLeft is:%d\n", spaceLeft);
        }

        for(int k = 0; k < spaceLeft ; k++)
        {
            window[k] = inputArr[i + k];
        }
        window[spaceLeft] = '\0';
        printf("\nwindow is:%s\n", window);

        for(int k = 0; k < spaceLeft; k++)
        {
            char bufferArr[12];
            bufferArr[0] = '\0';
            strncat(bufferArr, window, k + 1);
            printf("\nbuffer is:%s\n", bufferArr);
        }
    }


}
