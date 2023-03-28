#include <stdio.h>

float add(float a, float b) { return (a + b); }
float sub(float a, float b) { return (a - b); }
float mul(float a, float b) { return (a * b); }
float div(float a, float b) { return (a / b); }

float (*select_operation())(float, float)
{
    char operation;
    printf("choose action (+, -, *, /):");
    scanf("%c", &operation);

    switch (operation)
    {
    case '+':
        return add;
        break;
    case '-':
        return sub;
        break;
    case '*':
        return mul;
        break;
    case '/':
        return div;
        break;

    default:
        return 0;
        break;
    }
}

int main()
{
    //char operation;
    float a, b, result;

    // Declare function pointers.
    // Append the values the functions take.
    // Assign the address of the function.
    float (*pAdd)(float, float) = &add;
    float (*pSub)(float, float) = &sub;
    float (*pMul)(float, float) = &mul;
    float (*pDiv)(float, float) = &div;

    // array of functions is possible.
    // float (*functions[])(float, float) {add, sub, mul, div}

    printf("choose numbers:");
    scanf("%f %f", &a, &b);

    float (*operation)(float, float) = select_operation();

    return 0;
}