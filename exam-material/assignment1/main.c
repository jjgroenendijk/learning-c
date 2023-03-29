/* Function pointers                                                */
/* Exam March 30th, 2023                                            */
/* University of Applied Science (c) 2023                           */

#include <stdio.h>
#include <math.h>
#include <string.h>

double power(double d, double i);
double root(double d, double i);

int main(void)
{
   double result = 0.0;
   double (*fpointer);

   printf("Results: \n");

}

double power(double d, double i)
{
   double result = pow(d,i);
   return result;

}

double root(double d, double i)
{
   double result = pow(d,(1/i));
   return result;
}
