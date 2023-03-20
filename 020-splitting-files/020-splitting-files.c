#include <stdio.h>      // Use <> for standard libraries
#include "library.h"    // Use quotes "" for self made libraries
int main()
{
    int x = 7;
    int y = 12;
    int result = 0;

    add(&x, &y, &result);
    printf("01: %d\n", result);

    subtract(&x, &y, &result);
    printf("02: %d\n", result);

    multiply(&x, &y, &result);
    printf("03: %d\n", result);

    divide(&x, &y, &result);
    printf("04: %d\n", result);

    return 0;
}