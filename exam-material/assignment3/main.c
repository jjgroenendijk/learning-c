// Jaap-Jan Groenendijk (1548148)

/* Call backfunctions and sorting                                   */
/* Exam March 30th, 2023                                            */
/* University of Applied Science (c) 2023                           */

/*

    Q:
    Als je in de regel qsort... het agrument sizeof(text)-1 vervangt door sizeof(text) dan wordt in de regel daarna de geen text afgedrukt. Wat is daarvan de oorzaak?

    A:
    Laatste character van een array met characters is een \0, wat aangeeft dat de string is afgelopen.
    Ik vermoed dat qsort vastloopt op dit symbool en geen goede vergelijking meer kan maken.
    De string gaat hiermee verloren.

*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *p1, const void *p2);
int compareReverse(const void *p1, const void *p2);

int main()
{
    // Declare array of random characters
    char text[] = "kbamobzwgddnwgghskqu";

    // Show original array
    printf("Original: %s\n", text);

    // Sort A-Z
    qsort(text, sizeof(text) - 1, sizeof(char), compare);
    printf("Sort A-Z: %s\n", text);

    // Sort Z-A
    qsort(text, sizeof(text) - 1, sizeof(char), compareReverse);
    printf("Sort Z-A: %s\n", text);

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

    return 0;
}

int compareReverse(const void *p1, const void *p2)
{
    char c1 = *(const char *)p1;
    char c2 = *(const char *)p2;

    if (c1 < c2)
    {
        return 1;
    }
    else if (c1 > c2)
    {
        return -1;
    }
    else
    {
        return 0;
    }

    return 0;
}