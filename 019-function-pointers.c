/*
    Function pointer stores the address of a function.
*/

#include <stdio.h>

void function(int x)
{
    printf("x: %d\n", x);
}

double add(double a, double b)
{
    return (a + b);
}

int main()
{
    // variables
    double a = 5;
    double b = 8;
    double result;

    // concept
    void (*function_pointer)(int);
    function_pointer = &function;
    (*function_pointer)(4);

    // add function using function pointer
    double (*add_pointer)(double, double);
    add_pointer = &add;
    result = (*add_pointer)(a, b);
    printf("a+b: %.0lf\n", result);

    return 0;
}