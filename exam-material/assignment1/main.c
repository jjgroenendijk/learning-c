// Jaap-Jan Groenendijk (1548148)
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
   // Declare doubles
   double result = 0.0;
   double d = 9, i = 2;

   // Declare functions
   double (*fPower)(double, double);
   fPower = &power;
   double (*fRoot)(double, double);
   fRoot = &root;

   // Calculate results
   double resultPower = (*fPower)(d, i);
   double resultRoot = (*fRoot)(d, i);

   // Print results
   printf("Result 01: %.01lf\n", resultPower);
   printf("Result 02: %.01lf\n", resultRoot);

   // Print address of function pointer power
   printf("Address of function power(): %p\n", &power);
   printf("Address of function pointer: %p\n", fPower);

   // Print address of function pointer root
   printf("Address of function power(): %p\n", &root);
   printf("Address of function pointer: %p\n", fRoot);

}

double power(double d, double i)
{
   double result = pow(d, i);
   return result;
}

double root(double d, double i)
{
   double result = pow(d, (1 / i));
   return result;
}
