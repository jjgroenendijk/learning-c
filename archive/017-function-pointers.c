#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   Multiple functions in an array. This program uses an array with functions to
   create a simple calculator. Complete the program.
   Add the functions and text ("sub" , "add" , "div" , "mul" ) to the array.
   Test the program.

   Definition of a struct that holds the name of the operation (name)
   and a pointer (ope) that holds a pointer to the function that handles the
   operation.
   */

/// ope should hold the pointer to a function tha belongs to an operation 

typedef struct
{
    int (*ope)(int, int);
    char name [10];
} operation;

/*
   \brief sum, sub, mul, div * \param num1  The functions that handle the
   operations.
   \param num2
   \return
   */

int sum(int num1, int num2);
int sub(int num1, int num2);
int mult(int num1, int num2);
int divd(int num1, int num2);

int main()
{
    int x, y, choice, result;

    /// Array that contains the function and inforatmion for the operations
    operation operations[4];

    /// Replace the contents of the array below with the correct assignments
    operations[0].ope = &sum;
    strcpy(operations[0].name, "add");
    operations[1].ope = &sub;
    strcpy(operations[1].name, "subtract");
    operations[2].ope = &mult;
    strcpy(operations[2].name, "multiply");
    operations[3].ope = &divd;
    strcpy(operations[3].name, "divide");

    printf("Enter two integer numbers (on one line: ");
    scanf("%d%d", &x, &y);

    printf("Enter:\n"
            "0 to sum\n"
            "1 to subtract\n"
            "2 to multiply\n"
            "3 to divide\n");

    scanf("%d", &choice);

    if (operations[choice].ope != NULL && choice <= 3)
    {
        result = (operations[choice].ope)(x, y);
        printf("Operation: %s result: %d\n ", operations[choice].name, result);
    }
    else
    {
        printf("Function not available\n");
        exit (1);
    }

    return 0;
}

int sum(int x, int y)
{
    return(x + y);
}

int sub(int x, int y)
{
    return(x - y);
}

int mult(int x, int y)
{
    return(x * y);
}

int divd(int x, int y)
{
    if (y != 0)
    {
        return (x/y);
    }
    else 
    {
        return 0;
    }
}
