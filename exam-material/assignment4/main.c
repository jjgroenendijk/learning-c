#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct sensorNode
{
    int senseNumber;
    int *values; // sensor uses an array with SIZE integer values
} sensorNode_t;

void funcSensorNode(sensorNode_t *destination, const sensorNode_t source, const int size);
void printSensorNode(const sensorNode_t node, const int size);

int main(void)
{
    sensorNode_t node1 = {1, NULL};
    sensorNode_t node2 = {2, NULL};
    node1.values = (int *)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        node1.values[i] = i * 10;
    }
    printSensorNode(node1, SIZE);
    funcSensorNode(&node2, node1, SIZE);
    //    printSensorNode(node2, SIZE);          // Uncomment this part after implementing funcSensorNode()
}

void funcSensorNode(sensorNode_t *destination, const sensorNode_t source, int size)
{

    /*
        for (int i = 0; i < size; i++) {
            destination->values[i] += source.values[i];
        }
    */
}

void printSensorNode(sensorNode_t node, int size)
{
    printf("Values of sensor %d:\n", node.senseNumber);
    for (int i = 0; i < size; i++)
        printf("%d\n", node.values[i]);
}

/*
This is a C program that defines a structure sensorNode_t which represents a sensor node with a unique senseNumber and an array of values with SIZE elements.

The program declares three functions: funcSensorNode, printSensorNode, and main.

main initializes two sensor nodes node1 and node2. It allocates memory for the values array of node1 using malloc and initializes each element of the array with the values of i * 10, where i ranges from 0 to 4.

The function printSensorNode is called to print the values of node1 on the console.

funcSensorNode is then called with node2 as the destination parameter and node1 as the source parameter. The purpose of funcSensorNode is not defined and the function body is empty. The program does not print the values of node2 after calling funcSensorNode.

The program defines SIZE as a constant with a value of 5 using the #define preprocessor directive. It also includes the standard library headers stdio.h and stdlib.h.
*/