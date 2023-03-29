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
     TEST_ASSERT_MESSAGE(compareDoubles(3.0, 3.0, 0.00002) == 0,"Test equal 3.0 == 3.0 with epsilon 0.00002");
   }
   {
     /// Insert your second Unity based test here
     TEST_ASSERT_MESSAGE(compareDoubles(3.0, 2.0, 0.00002) != 0,"Test equal 3.0 == 2.0 with epsilon 0.00002");
   }
   {
     TEST_ASSERT_MESSAGE(compareDoubles(3.00002, 3.00003, 0.00002) == 0,"Test equal 3.00002 == 3.00003 with epsilon 0.00002");
     /// Insert your third Unity based test here
   }
   {
     TEST_ASSERT_MESSAGE(compareDoubles(3.00002, 3.00004, 0.00002) == 0,"Test equal 3.00002 == 3.00004 with epsilon 0.00002");
     /// Insert your fourth Unity based test here
   }
   {
     TEST_ASSERT_MESSAGE(compareDoubles(3.00002, 3.00005, 0.00002) != 0,"Test equal 3.00002 != 3.00005 with epsilon 0.00002");
     /// Insert your fourth Unity based test here
   }
}

void test_compareDoublesNotEqual(void)
{
   printf("------ compareDoubles on not_equal\n");
   printf("------ compareDoubles on D1 > D2 and D1 < D2\n");
   {
     /// Insert your first Unity based test here
     /// test on D1 > D2
     TEST_ASSERT_MESSAGE(compareDoubles(4.0, 3.0, 0.00002) > 0,"Test equal 3.0 > 4.0 with epsilon 0.00002");

   }
   {
     /// Insert your second Unity based test here
     /// test on D1 > D2
     TEST_ASSERT_MESSAGE(compareDoubles(3.0, 4.0, 0.00002) < 0,"Test equal 3.0 > 4.0 with epsilon 0.00002");
   }
   {
     /// Insert your third Unity based test here
     /// test on D1 < D2
     TEST_ASSERT_MESSAGE(compareDoubles(4.00004, 4.00003, 0.00002) == 0,"Test equal 4.00005 == 4.00003 with epsilon 0.00002");
   }
   {
     /// Insert your third Unity based test here
     /// Do a boundary test! on D1 > D2 check with epsilon is 0.0002
     TEST_ASSERT_MESSAGE(compareDoubles(4.00006, 4.00003, 0.00002) > 0,"Test equal 4.00006 > 4.00003 with epsilon 0.00002");
   }

}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_compareDoublesEqual);
   RUN_TEST(test_compareDoublesNotEqual);

   return UNITY_END();
}

