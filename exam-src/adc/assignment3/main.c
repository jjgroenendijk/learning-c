/* Call backfunctions and sorting                                   */
/* Exam March 30th, 2023                                            */
/* University of Applied Science (c) 2023                           */
/*                                                                  */
/* Answers:                                                         */
/*                                                                  */
/*                                                                  */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *p1, const void *p2);

int main()
{
    char text[] = "kbamobzwgddnwgghskqu";
    printf("Before %s\n", text);
    qsort(text, sizeof(text) - 1, sizeof(char), compare);
    printf("After %s\n", text);
    return 0;
}

int compare(const void *p1, const void *p2)
{
    char c1 = *(const char *)p1;
    char c2 = *(const char *)p2;

    if (c1 < c2)
    {
        return -1;
    }
    else if (c1 > c2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
