#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * Multiple functions in an array
 *
 * This program uses an Array with functions to create a simple
 * calculator
 * complete the program:
 *
 * 1) add the functions and text ("sub" , "add" , "div" , "mul" ) to the array
 * 2) test the program
 *
*/ 


/*!
 *  definition of a struct that holds the name of the operation (name)
 *  and a pointer (ope) that holds a pointer to the function that handles the
 *  operation
*/
typedef struct
{
  int (*ope)(int,int);                  // this struct uses a function point that poinst to teh operation to be done
   char name[10];
}  operation;

/*!
 * \brief sum, sub, mul, div    The functions that handle the operations
 * \param num1
 * \param num2
 * \return
 */
int sum(int num1, int num2);
int sub(int num1, int num2);
int mult(int num1, int num2);
int divd(int num1, int num2);


int main() 
{
   int x, y, choice, result;
   operation operations[4];       /// Array that contains the function and information for the operations

   /// Replace the contents of the array below with the correct
   /// assignments for each operation
   ///
   operations[0].ope = sum;                             /// opdracht 4 de function pointers worden in een array geplaatst
   strcpy(operations[0].name, "sum");                   /// de bijbehorende operatie wordt in de name geplaatst  
   operations[1].ope = sub;
   strcpy(operations[1].name, "sub");
   operations[2].ope = mult;
   strcpy(operations[2].name, "mult");
   operations[3].ope = divd;
   strcpy(operations[3].name, "divd");

   printf("Enter two integer numbers (on one line: ");
   scanf("%d%d", &x, &y);

   printf("Enter:\n0 to sum\n1 to subtract\n2 to multiply\n3 to divide\n");
   scanf("%d", &choice);

   if (operations[choice].ope != NULL && choice <= 3)
     {
       result = (operations[choice].ope)(x, y);          /// de functie wordt aangeroepen via de functie-pointer
       printf("Operation: %s  result: %d\n ", operations[choice].name, result);
     }
   else
     {
       printf("Function not available\n");
       exit(1);
     }

   return 0;
}

int sum(int x, int y)
{
   return(x + y);
}

int sub(int x, int y)
{
   return(x - y);
}

int mult(int x, int y)
{
   return(x * y);
}

int divd(int x, int y)
{
   if (y != 0)
   {
      return (x / y);
   }
   else
   {
      return 0;
   }
}
