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
   addSLL(&pHead, 10);                                             /// each addSLL does a malloc() see in the SLL library
   showSLL(pHead);

   printf("Add new data to the SLL 0x%p:\n", pHead);
   addSLL(&pHead, 20);
   showSLL(pHead);

   // We have don 2 addSLL so we have done 2 mallocs()
   
   printf("Clear the SLL 0x%p:\n", pHead);

   // clearSLL deletes the complete SLL, clearSLL should releases the allocated memory Look at clearSLL inteh library ==>
   clearSLL(&pHead);
   showSLL(pHead);

   return 0;
}
