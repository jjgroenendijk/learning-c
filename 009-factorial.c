/*
	Calculate the factorial of a given number.
	Created without searching internet sources.
*/

#include <stdio.h>

int main()
{
	double input, i = 1;
	printf("Please enter a number:\n");
	scanf("%lf", &input);

	for (double tmp = input; tmp >= 1; tmp--)
	{
		i = tmp * i;
	}

	printf("Factorial of %.0lf is:\n"
			"%.0lf", input, i);

	return 0;
}
