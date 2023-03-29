/* Singly Linked List: SLL */

#include "sll-faulty.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   node_t *pHead = NULL; /* Create an empty SLL,
                            pHead is the 'owner' of the SLL */

   showSLL(pHead);

   printf("\nAdd new data to the SLL 0x%p:\n", pHead);
   addSLL(&pHead, 10);
   showSLL(pHead);

   printf("Add new data to the SLL 0x%p:\n", pHead);
   addSLL(&pHead, 20);
   showSLL(pHead);

   printf("Clear the SLL 0x%p:\n", pHead);
   clearSLL(&pHead);
   showSLL(pHead);

   return 0;
}
