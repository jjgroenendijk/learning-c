#include <stdio.h>

void averageDdata(double data[], int size);

#define DATA_SIZE 4

int main()
{
    double sensorData[DATA_SIZE] = {1.0 , 2.0, 3.0, 4.0};

    int size;
    size = sizeof(sensorData)/sizeof(sensorData[0]);

    printf("OLD:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%.1lf\t", sensorData[i]);
    }

    averageDdata(sensorData, size);

    printf("\nNEW:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%.1lf\t", sensorData[i]);
    }

    return 0;
}

void averageDdata(double data[], int size)
{
    // average all array indexes
    double temporary;

    //printf("\nsize: %d\n", size);

    for (int i = 0; i < size; i++)
    {
        //printf("\ndata: %.1lf", data[i]);
        temporary = temporary + data[i];
    }

    //printf("\nsum of array: %.1lf\n", temporary);
    temporary = temporary / size;

    for (int i = 0; i < size; i++)
    {
        data[i] = temporary;
    }
}
