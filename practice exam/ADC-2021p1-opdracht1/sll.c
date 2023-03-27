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

void insertSLL(node_t **ppHead, int data, unsigned int node)    ///opdracht 1 - c
{
   node_t *pNext = *ppHead;
   node_t *pPrevious = NULL;
   node_t *pNew = (node_t *)malloc(sizeof(node_t));
   int currentNode = 0;
   
   /* Check if allocation has succeeded */
   if (pNew != NULL && node != 0 && sizeSLL(*ppHead) > node)
     {
     
       /* To be implemented assignment 1-c */
       printf("\n----------insertSLL not implemented yet, see opdracht 1-c\n\n");
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
       pNew->data = data;
       pPrevious->pNextNode = pNew;
       pNew -> pNextNode = pNext;
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
      free(pToBeRemoved);
      pToBeRemoved = pNext;
   }
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
