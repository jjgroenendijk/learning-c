/* Singly Linked List: SLL */

#include "sll.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int count = 4;                        // default value for count, see assignment 1-a
  /// Solution for assignment 1a
  if (argc < 2)                        // check the number of arguments, must be at least 2 (progname and argument)
    {
      fprintf(stderr, "Usage: %s <number of nodes>\n", argv[0]);
      exit(1);                         // missing argument exit the program
    }  
  count = atoi(argv[1]);
  
  node_t *pHead = NULL; /* Create an empty SLL,
                            pHead is the 'owner' of the SLL */

  showSLL(pHead);
  printf("Size of the SLL = %lu\n", sizeSLL(pHead));


  // create a sll with count nodes
  for (int i = 0; i < count; i++)
     {
       printf("\nAdd new data to the SLL 0x%p:\n", pHead);
       addSLL(&pHead, i);
       showSLL(pHead);
       printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));
     }


  /// solution 1-c in sll.c
  ///
  insertSLL(&pHead, 35, 2);                    /// insert a node after node 2, see assignment 1-c 

  printf("=================List after insert ================\n");
  showSLL(pHead);
  printf("Clear the SLL 0x%p:\n", pHead);
  clearSLL(&pHead);
  showSLL(pHead);
  printf("Size of the SLL = %lu\n\n", sizeSLL(pHead));

  return 0;
}
