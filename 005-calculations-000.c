#include <stdio.h>

int main()
{
	// declare variables
	double number1, number2, result;
	
	// ask for user input
	printf("Please insert the numbers to calculate.\n");
	printf("Number 1: ");
	scanf("%lf", &number1);
	printf("Number 2: ");
	scanf("%lf", &number2);
	printf("chosen numbers are %.0lf and %.0lf\n", number1, number2);
	
	// do some calculations
	result = number1 + number2;
	printf("%.0lf + %.0lf = %.4lf\n", number1, number2, result);

	result = number1 - number2;
	printf("%.0lf - %.0lf = %.4lf\n", number1, number2, result);

	result = number1 * number2;
	printf("%.0lf * %.0lf = %.4lf\n", number1, number2, result);
	
	result = number1 / number2;
	printf("%.0lf / %.0lf = %.4lf\n", number1, number2, result);

	// let the computer know that all is well
	return 0;
}

