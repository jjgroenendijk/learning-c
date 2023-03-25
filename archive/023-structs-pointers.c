#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a simple struct for location data
    typedef struct {
        int x;
        int y;
    } location_t;

    // method 01
    location_t location01;

    location01.x = 8;
    location01.y = 16;

    printf("location01: (%d,%d)\n", location01.x, location01.y);

    // method 02 (data is placed at address of method 01)
    location_t *location02;
    location02 = &location01;

    location02->x = 9;
    location02->y = 18;

    printf("location02: (%d,%d)\n", location02->x, location02->y);

    // method 03 
    location_t *location03;

    location03 = malloc(sizeof(location_t));
    
    location03->x = 7;
    location03->y = 14;
    printf("location03: (%d,%d)\n", location03->x, location03->y);

    // alternatively use this
    (*location03).x = 4;
    (*location03).y = 8;
    printf("location03: (%d,%d)\n", location03->x, location03->y);

    return 0;
}
