#include "sll.h"

#include <stdio.h>

size_t sizeSLL(const node_t *pHead)
{
   const node_t *pNext = pHead;
   size_t size = 0;

   if (pHead == NULL)
   {
      size = 0;
   }
   else
   {
      while (pNext != NULL)
      {
	size++;
	pNext = pNext->pNextNode;
      }
   }

   return size;
}


void insertSLL(node_t **ppHead, int data, int node)    ///opdracht 1 - c
{
   node_t *pNext = *ppHead;
   node_t *pPrevious = NULL;
   node_t *pNew = (node_t *)malloc(sizeof(node_t));    //create a new node
   int currentNode = 0;
   
   /* Check if allocation has succeeded */
   if (pNew != NULL && node != 0 && sizeSLL(*ppHead) > node)          /// check if malloc is ok
     {
     
       /// first find the node where the new node will be added
       /// inspiration from sizeSll()
       if (ppHead != NULL)
	 while (pNext != NULL && currentNode != node)                 /// iterate trough sll to find node 2
	 {
	   pPrevious = pNext;
	   pNext = pNext->pNextNode;
	   currentNode++;
	   printf("Current node is %d %p\n",currentNode, pNext);      /// Some debug information
	 }
       pNew->data = data;                                    /// set data in new node
       pPrevious->pNextNode = pNew;                          /// set pointer to new node in previous
       pNew -> pNextNode = pNext;                            /// set pointer in new node restore the chain
     }
}

void addSLL(node_t **ppHead, int data)
{
   node_t *pNext = *ppHead;
   node_t *pNew = (node_t *)malloc(sizeof(node_t));

   /* Check if allocation has succeeded */
   if (pNew != NULL)
   {
      pNew->data = data;
      pNew->pNextNode = NULL;
   }
   if (pNext != NULL)
   {
      /* Traverse through every subsequent node in the SLL */
      while (pNext->pNextNode != NULL)
      {
         pNext = pNext->pNextNode;
      }
      pNext->pNextNode = pNew;
   }
   else
   {
      *ppHead = pNew;
   }
}

void clearSLL(node_t **ppHead)
{
   node_t *pToBeRemoved = *ppHead;
   node_t *pNext = NULL;

   while (pToBeRemoved != NULL)
   {
      pNext = pToBeRemoved->pNextNode;
      printf("value %d\n",pToBeRemoved->data );
      free(pToBeRemoved);
      pToBeRemoved = pNext;
   }
   free(pToBeRemoved);
   *ppHead = NULL;
}

void showSLL(const node_t *pHead)
{
   const node_t *pNext = pHead;

   if (pHead == NULL)
   {
      printf("SLL is empty\n");
   }
   else
   {
      while (pNext != NULL)
      {
         printf("Node %p:  Data = %d  pNext = %p\n", pNext, pNext->data,
                pNext->pNextNode);
         pNext = pNext->pNextNode;
      }
   }
}
