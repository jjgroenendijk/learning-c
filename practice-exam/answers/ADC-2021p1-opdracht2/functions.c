#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h" 

int compareDoubles(const double d1, const double d2, const double epsilon)
{
   if (fabs(d1 - d2) < epsilon)
   {
      return 0;
   }
   else
   {
      return (d1 - d2) > 0.0? 1:-1;
   }
}

int compareIntegers(const int n1, const int n2)
{
   return (n1 - n2);
}

int compareCodes(const void *pC1, const void *pC2)
{
   const code_t *pData1 = (const code_t*)pC1;
   const code_t *pData2 = (const code_t*)pC2;


   if (pData1->n == pData2->n)
   {
      return compareDoubles(pData1->d, pData2->d, EPSILON);
   }
   else
   {
      return compareIntegers(pData1->n, pData2->n);
   }
}
