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
    printSensorNode(node2, SIZE);          // Uncomment this part after implementing funcSensorNode()

    // Free memory for node 1
    free(node1.values);
    node1.values = NULL;

    // Free memory for node 2
    free(node2.values);
    node2.values = NULL;

    return 0;
}

// Source node kopieren naar destination node.
// Source node is const, dus die kan ook niet aangepast worden.
void funcSensorNode(sensorNode_t *destination, const sensorNode_t source, int size)
{
    // Allocate memory for destination node
    destination->values = (int *) malloc(sizeof(int) * SIZE);

    // Fill array with random data, to check if output is correct
    // If output is 0, then copying data has failed.
    for (int i = 0; i < SIZE; i++)
    {
        destination->values[i] = 0;
    }

    // Check if memory allocation succeeded
    if (destination->values != NULL)
    {
        printf("memory allocation probably succeeded!\n");

        // Copy every source array index i to destintaion array index i.
        for (int i = 0; i < size; i++)
        {
            destination->values[i] = source.values[i];
        }
    }
}

void printSensorNode(sensorNode_t node, int size)
{
    printf("Values of sensor %d:\n", node.senseNumber);
    for (int i = 0; i < size; i++)
        printf("%d\n", node.values[i]);
}