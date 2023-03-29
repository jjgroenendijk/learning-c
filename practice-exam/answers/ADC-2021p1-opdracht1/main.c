/* Singly Linked List: SLL */

#include "sll.h"

#include <stdio.h>
#include <stdlib.h>

#define COUNTARGUMENT 1

int main(int argc, char *argv[])
{
  int count = 0;
  printf("Value of ARGC is %d\n", argc);
  if (argc > 1)                             // check the number arguments
    {
      count = atoi(argv[COUNTARGUMENT]);    // argv is an array with pointers to the argument strings, string must be converted to integer
      printf("The number of new nodes = %s\n", argv[COUNTARGUMENT]);
    }
  else
    {
      printf("We need at least 1 argument\n");
      exit(1);
    }
       
   node_t *pHead = NULL; /* Create an empty SLL,
                            pHead is the 'owner' of the SLL */

   for (int i = 1; i <= count; i++)                             // use a loop with count to add nodes
     {
       printf("Add new data to the SLL 0x%p:\n", pHead);
       addSLL(&pHead, i);
       showSLL(pHead);
       printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));
     }

   insertSLL(&pHead, 35, 2);                                   /// test insertSLL see sll.c
   showSLL(pHead);
   printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));


   printf("Clear the SLL 0x%p:\n", pHead);
   clearSLL(&pHead);
   showSLL(pHead);
   printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));

   return 0;
}
