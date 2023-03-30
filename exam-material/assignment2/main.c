/* Singly Linked List: SLL                                          */
/* Exam March 30th, 2023                                            */
/* University of Applied Science (c) 2023                           */

#include "sll.h"

#include <stdio.h>
#include <stdlib.h>

int Func1SLL(const node_t *pSLL1);
void Func2SLL(node_t *pHead1, node_t **ppHead2);

int main(void)
{
    node_t *pHead1 = NULL; /* Create an empty SLL1, pHead1 is the 'owner' of SLL1 */
    node_t *pHead2 = NULL; /* Create an empty SLL2, pHead2 is the 'owner' of SLL2 */

    // add 3 nodes to SLL1
    addSLL(&pHead1, 10);
    addSLL(&pHead1, 20);
    addSLL(&pHead1, 30);
    printf("Information about SLL1:\n");
    showSLL(pHead1);

    // add 4 nodes to SLL2
    addSLL(&pHead2, 10);
    addSLL(&pHead2, 20);
    addSLL(&pHead2, 30);
    addSLL(&pHead2, 40);

    printf("Information about SLL2:\n");
    showSLL(pHead2);

    printf("Information from Func1SLL SLL1 is %d:\n", Func1SLL(pHead1));
    printf("Information from Func2SLL SLL2 is %d:\n", Func1SLL(pHead2));

    Func2SLL(pHead1, &pHead2);

    printf("Information about SLL1 after Func2SLL:\n");
    showSLL(pHead1);
    printf("Information about SLL2 after Func2SLL:\n");
    showSLL(pHead2);

    return 0;
}

int Func1SLL(const node_t *pHead)
{
    // declare variable to give back to main.
    int result = 0;

    const node_t *pNext = pHead;


    if (pHead != NULL)
    {
        while (pNext != NULL)
        {
            // Alles van SLL.data optellen in result.
            result += pNext->data;
            // Pointer naar de volgende waarde zetten.
            pNext = pNext->pNextNode;
        }
    }

    // Geef resultaat terug aan main
    return result;
}

// Ik zie iets over het hoofd in deze functie, maar ik weet niet wat.
// Output lijkt wel te kloppen.
void Func2SLL(node_t *pHead1, node_t **ppHead2)
{
    // check data has arrived
    if ((pHead1 != NULL) && (ppHead2 != NULL))
    {
        // ga naar het einde van singly linked list 1
        while (pHead1->pNextNode != NULL)
        {
            pHead1 = pHead1->pNextNode;
        }

        // verander de node pointer aan het einde van sll1 in het begin van sll2
        pHead1->pNextNode = (*ppHead2);
    }

    // phead2 opschonen en leegmaken
    *ppHead2 = NULL;
}
