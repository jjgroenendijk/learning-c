#include <stdio.h>

// function prototypes. more on this later
void modifyName(char *name);
void modifyNumber(int *number);

int main()
{
	// declare variables
	char name[30];
	int number;

	// ask user for input
	printf("please input your name:\n");
	scanf("%s", name);

	printf("please input a number:\n");
	scanf("%i", &number);

	// let user validate input
	printf("%s is the entered name\n", name);
	printf("%i is the entered number\n", number);

	// send entered data to functions
	modifyName(name);
	modifyNumber(&number);

	// show user the modified data
	printf("%s is your new name\n", name);
	printf("%i is your new number\n", number);

	// let the computer know that all is well :D
	return 0;
}

// function for modifying name
void modifyName(char *name)
{
	// modify data
	name[0] = 'a';
}

// function for modifying number
void modifyNumber(int *number)
{
	// multiply number by 2
	*number = *number * 2;
}
