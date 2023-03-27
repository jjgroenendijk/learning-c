// Libraries
#include <stdio.h>
#include <stdlib.h> // used for malloc()

// Structure of a node
typedef struct node
{
    int number;
    struct node *pNext;
} nodes_t;

int countSLL(nodes_t *pHead);
void printSLL(nodes_t *pHead);
void appendSLL(nodes_t *pHead, int data);
void prependSLL(nodes_t *pHead, int data);

int main()
{
    // initialize the pointer to the list
    nodes_t *pHead = NULL;

    // allocate memory for list
    pHead = (nodes_t *)malloc(sizeof(nodes_t));

    // set data for first node
    pHead->number = 12;
    pHead->pNext = NULL;

    // create second node
    nodes_t *pCurrent = (nodes_t *)malloc(sizeof(nodes_t));
    pCurrent->number = 13;
    pCurrent->pNext = NULL;

    // point first node to second node
    pHead->pNext = pCurrent;

    // create third node
    pCurrent = (nodes_t *)malloc(sizeof(nodes_t));
    pCurrent->number = 14;
    pCurrent->pNext = NULL;

    // link 2nd node to 3rd node
    pHead->pNext->pNext = pCurrent;

    // print total amount of nodes
    printf("total: %d\n", countSLL(pHead));

    // print sll content
    printSLL(pHead);

    // append number to SLL
    appendSLL(pHead, 15);

    // prepend number to SLL
    prependSLL(pHead, 16);

    // free willy
    free(pHead);

    return 0;
}

int countSLL(nodes_t *pHead)
{
    // Initialize variable
    int count = 0;
    nodes_t *countPointer = NULL;
    countPointer = pHead;

    if (countPointer == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (countPointer != NULL)
        {
            count++;
            countPointer = countPointer->pNext;
        }
    }

    return (count);
}

void printSLL(nodes_t *pHead)
{
    // Initialize variable
    nodes_t *printPointer = NULL;
    printPointer = pHead;

    // check if SLL has links. print
    if (printPointer == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (printPointer != NULL)
        {
            printf("print: %d\n", printPointer->number);
            printPointer = printPointer->pNext;
        }
    }
}

void appendSLL(nodes_t *pHead, int data)
{
    printf("appending: %d\n", data);

    nodes_t *appendPointer = NULL;
    appendPointer = pHead;

    nodes_t *pTMP = (nodes_t *)malloc(sizeof(nodes_t));
    pTMP->number = data;
    pTMP->pNext = NULL;

    if (appendPointer != NULL)
    {
        while (appendPointer->pNext != NULL)
        {
            appendPointer = appendPointer->pNext;
        }
        appendPointer->pNext = pTMP;
    }
}

void prependSLL(nodes_t *pHead, int data)
{
    printf("prepending: %d\n", data);

    nodes_t *prependPointer = NULL;
    
    nodes_t *pTMP = (nodes_t*)malloc(sizeof(nodes_t));
    pTMP->number = data;
    pTMP->pNext = pHead;

    // Continue here
}