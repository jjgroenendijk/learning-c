/*
	The goal of this program is to measure the time between 2 key presses.
	Code for measuring time will be reused for a school assignment.
 */

// Default C library
#include <stdio.h>

// Library for time measurement
#include <time.h>

int main()
{
	clock_t startTime, endTime;

	// Explain to users what they can expect from this program
	printf("Hi! This program will measure the time between 2 key presses.\n"
			"Press the spacebar to start the timer.\n"
			"Press the spacebar again to stop the timer.\n"
			"This program will tell you the time between registering the two presses.\n"
			"\n\n"
			"Please press the spacebar.\n");
	
	// Initialize character variable
	char spacebarPress;

	// Wait for spacebar press from user
	do {
		spacebarPress = getchar();
	}
	while (spacebarPress != ' ');
	
	// Save the time when user has pressed spacebar
	startTime = time(NULL);

	// Ask user to press spacebar again
	printf("Please press the spacebar again.\n");

	// Wait again for the second spacebar press
	do {
		spacebarPress = getchar();
	}
	while (spacebarPress != ' ');

	// Save time again 
	endTime = time(NULL);

	// Initialize double variable for saving elapsed time
	double elapsedTime;
	
	// Calculate elapsed time by subtracting starttime from endtime
	elapsedTime = difftime(endTime, startTime);

	// Let user know how long it took to press space two times
	printf("Time difference is:\n"
		"%lf seconds\n", elapsedTime);

	return 0;

}
