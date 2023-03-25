/*

   Update the function isInt() to check if a string represents a valid
   integer value possibly preceded by only one + or − sign.   

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isInt(const char str[]);

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
            printf("argument %d:\t%s\t", i, argumentChar[i]);
            if (isInt(argumentChar[i]))
            {
                printf("integer: yes\n");
            }
            else 
            {
                printf("integer: false\n");
            }
        }
    }

    return 0;
}

bool isInt(const char str[])
{
    int i = 0;
    bool isInteger = true;
    bool isSignAllowed = true;

    if (str[i] == '+' || str[i] == '-')
    {
        i++;
        isSignAllowed = false;
    }

    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
        {
            isInteger = false;
            break;
        }
        i++;
    }

    if (i == 0 || (i == 1 && !isSignAllowed))
    {
        isInteger = false;
    }

    return isInteger;
}
