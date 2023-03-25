#include <stdio.h>

int main()
{
	// while loop
	int i0 = 1;

	while (i0 <= 5) 
	{
		printf("%i\n", i0);
		i0++;
	}

	// for loop
	for (int i1 = 1; i1 <= 5; i1++)
	{
		printf("%i\n", i1);
	}

	// do while loop
	int i2 = 1;
	do {
		printf("%i\n", i2);
		i2++;
	}
	while (i2 <= 5);

	// let computer know that all is wel
	return 0;
}
