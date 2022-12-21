#include <stdio.h>

// manual approximation of pi
#define pi 3.142857

int main()
{
	// initialize key variables
	double area, radius, diameter, circumference;
	
	// ask for user input
	printf("Please input circle diameter:\n");
	scanf("%lf", &diameter);

	// perform calculations
	radius = diameter / 2;
	area = pi * radius * radius;
	circumference = diameter * pi;

	// show calculation output
	printf("%.0lf is the diameter\n", diameter);
	printf("%.0lf is the radius\n", radius);
	printf("%.0lf is the area\n", area);
	printf("%.0lf is the circumference\n", circumference);

	// let computer know that all is well
	return 0;
}
