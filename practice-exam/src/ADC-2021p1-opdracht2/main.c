/*!
 * This is the testframework for testing the function compareDoubles()
 * There are two testfunctions (to be) defined
 * test_compareDoublesEqual() 
   which tests the function compareDoubles() if two the same doubles are provided to the function
 *      be aware that the function has an epsilon argument which defines the accuracy of the test with the doubles
 *      so don't forget to do some boundary testing in your testfunction
 * 
 * test_compareDoubleNotEqual()
 * for testing the function compareDoubles() with different doubles
 *      check the functionality of the function compareDoubles() before defining your tests
 *
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h" 
#include "Unity/unity.h" 

#define UNITY_INCLUDE_PRINT_FORMATTED

void setUp()
{
   printf("\nStart testing functions for ADC assignment 2\n\n");
}

void tearDown()
{
   printf("\nReady testing functions for ADC assignment 2\n\n");
}

void test_compareDoublesEqual(void)
{
   printf("------ compareDoubles on equal\n");
   {
     /// Insert your first Unity based test here
     
   }
   {
     /// Insert your second Unity based test here
   }
   {
     /// Insert your third Unity based test here
   }
   {
     /// Insert your fourth Unity based test here
   }
}

void test_compareDoublesNotEqual(void)
{
   printf("------ compareDoubles on not_equal\n");
   printf("------ compareDoubles on D1 > D2\n");
   {
     /// Insert your first Unity based test here
     /// test on D1 > D2
   }
   {
     /// Insert your second Unity based test here
     /// test on D1 > D2
   }
   {
     /// Insert your third Unity based test here
     /// test on D1 < D2
   }
   {
     /// Insert your third Unity based test here
     /// Don't forget to do a boundary test! on D1 > D2 check with epsilon is 0.0002
   }
   {
     /// Insert your fourth Unity based test here
   }

}

int main(void)
{
   UNITY_BEGIN();

   /* start your test here, check how to run UNIT tests! */
   
   return UNITY_END();
}

