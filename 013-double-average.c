#include <stdio.h>

void average2D(double *pD1, double *pD2);

int main()
{
    double d1 = 2.0;
    double d2 = 3.0;
    
    printf("old:\n");
    printf ("d1 = %lf d2 = %lf\n", d1 , d2);

    printf("\nnew:\n");
    average2D(&d1, &d2);
    printf("d1 = %lf d2 = %lf\n", d1 , d2);

    return 0;
}

void average2D(double *pD1, double *pD2)
{
    double temporaryVariable = 0;
    temporaryVariable = (*pD1 + *pD2) / 2;
    *pD1 = temporaryVariable;
    *pD2 = temporaryVariable;
}

