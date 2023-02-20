#include <stdio.h>
#include <string.h>         // for strcpy
#include <stdlib.h>         // for qsort

typedef struct
{
    int numbers;
    char letters[3];        // string, needs additional '\0'
} zipcode_t;

int compareZipCodes(const void *pZC1, const void *pZC2);

int main()
{
    zipcode_t codes[] = {
        {1234, "AB"},
        {5678, "CD"},
        {9999, "ZZ"},
        {4321, "DC"},
        {1357, "AA"},
        {2468, "BB"}
    };

    int numCodes = sizeof(codes)/sizeof(codes[0]);
    printf("Amount of zipcodes: %d\n", numCodes);

    printf("\nUNSORTED\n");

    int i;

    for (i = 0; i < numCodes; i++)
    {
        printf("%d%s ", codes[i].numbers, codes[i].letters);
    }

    printf("\nSORTED\n");
    qsort(codes, numCodes, sizeof(codes[0]), compareZipCodes);

    for (i = 0; i < numCodes; i++)
    {
        printf("%d%s ", codes[i].numbers, codes[i].letters);
    }

    return 0;
}

int compareZipCodes(const void *pZC1, const void *pZC2)
{
    zipcode_t *zipCode1 = (zipcode_t*) pZC1;
    zipcode_t *zipCode2 = (zipcode_t*) pZC2;

    int result = zipCode1->numbers - zipCode2->numbers;
    
    if (result == 0)
    {
        result = strcmp(zipCode1->letters, zipCode2->letters);
    }
    
    return result;
}
