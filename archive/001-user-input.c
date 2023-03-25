#include <stdio.h>

int main()
{
	// define array of 30 characters
	char name[30];

	// tell user what to do
	printf("Please input your name:\n");

	// ask user for name
	scanf("%s", name);

	// welcome user
	printf("Welcome %s\n", name);

	return 0;
}
