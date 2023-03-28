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
void prependSLL(nodes_t **pHead, int data);
void insertSLL(nodes_t *pHead, int position, int data);
void deleteStartSLL(nodes_t **pHead, int amount);
void deleteEndSLL(nodes_t *pHead, int amount);
void deletePos(nodes_t **pHead, int position);
void deleteSLL(nodes_t *pHead);
void reverseSLL(nodes_t **pHead);

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

    // append number to SLL
    appendSLL(pHead, 15);

    // prepend number to SLL
    prependSLL(&pHead, 16);

    // insert number to given position in SLL.
    insertSLL(pHead, 2, 44);

    // print sll content
    printSLL(pHead);

    // delete first node of the list
    deleteStartSLL(&pHead, 0);

    // delete x amount of nodes at the end of the list
    deleteEndSLL(pHead, 0);

    // delete at position
    // deletePos(&pHead, 3);

    // delete sll list
    // deleteSLL(pHead);

    // reverse SLL
    reverseSLL(&pHead);

    // print sll content
    printSLL(pHead);

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
    nodes_t *printPointer = pHead;

    printf("complete list\n");
    // check if SLL has links. print data if link has data
    if (printPointer == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        while (printPointer != NULL)
        {
            printf("\tprint: %d\n", printPointer->number);
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

void prependSLL(nodes_t **pHead, int data)
{
    printf("prepending: %d\n", data);

    nodes_t *prependPointer = (nodes_t *)malloc(sizeof(nodes_t));
    prependPointer->number = data;
    prependPointer->pNext = *pHead;

    *pHead = prependPointer;
}

void insertSLL(nodes_t *pHead, int position, int data)
{
    // create 2 pointers to work with
    nodes_t *insertPointer = (nodes_t *)malloc(sizeof(nodes_t));
    insertPointer->number = data;
    insertPointer->pNext = NULL;

    nodes_t *insertTMP = pHead;

    int z;
    for (z = 1; z < position; z++)
    {
        insertTMP = insertTMP->pNext;
    }

    insertPointer->pNext = insertTMP->pNext;
    insertTMP->pNext = insertPointer;
}

void deleteStartSLL(nodes_t **pHead, int amount)
{
    nodes_t *pDeleteStart = (nodes_t *)malloc(sizeof(nodes_t));
    pDeleteStart = *pHead;

    int i;
    for (i = 0; i < amount; i++)
    {
        *pHead = (*pHead)->pNext;
        free(pDeleteStart);
        pDeleteStart = *pHead;
    }
}

void deleteEndSLL(nodes_t *pHead, int amount)
{
    // unsafe code, but it works for demonstration purposes!
    for (int i = 0; i < amount; i++)
    {
        nodes_t *pDeleter = pHead;

        while (pDeleter->pNext->pNext != NULL)
        {
            pDeleter = pDeleter->pNext;
            printf("travelled to node: %d\n", pDeleter->number);
        }

        free(pDeleter->pNext);
        pDeleter->pNext = NULL;
    }
}

void deletePos(nodes_t **pHead, int position)
{
    if ((*pHead) == NULL)
    {
        printf("error: head is empty");
    }
    else if (position == 1)
    {
        deleteStartSLL(pHead, 1);
    }
    else
    {
        nodes_t *pCurrent = *pHead;
        nodes_t *pPrevious = *pHead;
        for (int i = 1; i < position; i++)
        {
            pCurrent = pCurrent->pNext;
        }

        for (int i = 1; i < (position - 1); i++)
        {
            pPrevious = pPrevious->pNext;
        }

        printf("deleting: %d\t position: %d\n", pCurrent->number, position);

        pPrevious->pNext = pCurrent->pNext;
        free(pCurrent);
        pCurrent = NULL;
    }
}

void deleteSLL(nodes_t *pHead)
{
    nodes_t *pTMP = pHead;

    while (pTMP != NULL)
    {
        pTMP = pTMP->pNext;
        printf("deleting %d\n", pHead->number);
        free(pHead);
        pHead = pTMP;
    }

    printf("list deleted\n");
}

void reverseSLL(nodes_t **pHead)
{
    /*
        General idea:

        temp2 = head->link;
        head->link = temp;
        temp = head;
        head = temp2
    */

    nodes_t *pPrev = NULL;
    nodes_t *pNext = NULL;

    while ((*pHead) != NULL)
    {
        pNext = (*pHead)->pNext;
        (*pHead)->pNext = pPrev;
        pPrev = *pHead;
        *pHead = pNext;
    }

    *pHead = pPrev;

    printf("list reversed\n");
}