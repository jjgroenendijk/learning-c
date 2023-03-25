#include <stdio.h>
#include <stdlib.h>

// Prototype to use for assigment
//size_t sizeSLL(const node_t *pHead);

struct node 
{
    int data;
    struct node *link;
} ;

int main()
{
    printf("Working with a singly linked list!\n");

    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->link = NULL;

    printf("Head data: %d\n", head->data);

    return 0;
}
