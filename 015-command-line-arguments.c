/*
   Write a program that adds up all command line arguments
   representing a valid integer value without a preceding + or − sign.

   Use atoi() to convert from an ASCII string to an integer value. If no 
   arguments are given an appropriate error message needs to be given. 
   Use the stderr stream for this error message.
   */

#include <stdio.h>
#include <stdlib.h>

int main(int argumentAmount, char *argumentChar[])
{
    int i, sum = 0;
    printf("Argument amount:%d\n", (argumentAmount - 1));

    if(argumentAmount <= 1)
    {
        printf("Please give more arguments\n");
    }

    else
    {
        for (i = 1; i < argumentAmount; i++)
        {
            printf("argument %d:\t%s\n", i, argumentChar[i]);
            sum += atoi(argumentChar[i]);
        }
        printf("sum: %d\n", sum);
    }
    
    return 0;
}
