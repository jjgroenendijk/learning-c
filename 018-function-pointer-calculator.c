/*
 * Simple calculator using function pointers.
 */


#include <stdio.h>

int sum     (int a, int b) { return (a+b); };
int subtract(int a, int b) { return (a-b); };
int multiply(int a, int b) { return (a*b); };
int divide  (int a, int b) { return (a/b); };

int calculate(int a, int b, int (*op)(int, int))
{
    return op(a, b);
}

int main()
{
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("sum:\t%d\n",      calculate(a, b, &sum       ));
    printf("subtract:\t%d\n", calculate(a, b, &subtract  ));
    printf("multiply:\t%d\n", calculate(a, b, &multiply  ));
    printf("divide:\t%d\n",   calculate(a, b, &divide    ));

    return 0;
}
