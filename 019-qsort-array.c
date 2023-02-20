#include <stdio.h>
#include <stdlib.h>

int compare(const void *x_void, const void *y_void)
{
    int x = *(int *)x_void;
    int y = *(int *)y_void;

    return (x - y);
}

void printArray(int numbers[], int amount)
{
    int i;

    for (i = 0; i < amount; i++)
    {
        printf("%d \t", numbers[i]);
    }

    printf("\n");
}


int main()
{
    int numbers[] = {5, 4, 3, 7, 1, 9, 2, 8, 6, 0};
    int amount = (sizeof(numbers)/sizeof(int));

    // Unsorted Numbers
    printf("UNSORTED NUMBERS\n");
    printArray(numbers, amount);

    // Sorted Numbers
    printf("SORTED NUMBERS\n");
    qsort(numbers, amount, sizeof(int), compare);
    printArray(numbers, amount);

    return 0;
}
