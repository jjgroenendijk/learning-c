#include <stdio.h>		// default library
#include <string.h>		// library needed for strcpy

struct house {
	char owner[30];
	int length;
	int width;
	int height;
};

int main()
{
	struct house h00;

	// This doesn't work
	// h00.owner = "John Doe";

	// This does work
	strcpy(h00.owner, "John Doe");

	h00.length = 8;
	h00.width = 9;
	h00.height = 7;

	int volume;
	volume = h00.length * h00.width * h00.height;

	printf("Owner of house is: %s\n", h00.owner);
	printf("Volume of house is: %d\n", volume);

	return 0;
}
