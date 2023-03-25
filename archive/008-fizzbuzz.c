/*
	Write down numbers from 1 to 100.
	Write fizz if number is a multiple of 3.
	Write buzz if number is a multiple of 5.
	Write fizzbuzz if number is a multiple of 3 and 5.
*/

#include <stdio.h>

int main() {
	for (int i = 1; i <= 100; i++) {
		printf("%i", i);

		if ((i % 15) == 0) {
			printf("\tfizzbuzz");
		}
		else if ((i % 5) == 0) {
			printf("\tbuzz");
		}
		else if ((i % 3) == 0) {
			printf("\tfizz");
		}
		
		printf("\n");	
	
	}
	return 0;
}
