#include <stdio.h>

void add(int *x, int *y, int *result) { *result = *x + *y; }

int main()
{
	// concept
	int a = 42;
	int *b = &a;

	printf("a: 	%d\n", a);
	printf("&a: %p\n", &a);
	printf("(*b): %d\n", (*b));
	printf("&b: %p\n", &b);

	// pointers to functions
	int w = 5;
	int x = 19;
	int result;

	// pass through the addresses of variables
	add(&w, &x, &result);
	printf("result: %d\n", result);

	// initialize pointers
	int *y = &w;
	int *z = &x;

	// pass throug pointers to function add
	add(y, z, &result);
	printf("result: %d\n", result);

	return 0;
}