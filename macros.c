#include <stdio.h>

#ifndef PI
#define PI 3.14
#endif

#define Area(r) (PI * r * r)

int main(int argc, char **argv) {
    printf("File: %s\n", __FILE__);
    printf("FileName: %s\n", __FILE_NAME__);
    printf("Line: %d\n", __LINE__);
    printf("Line: %s\n", __DATE__);
    printf("TIME: %s\n", __TIME__);

    printf("Area of circle with radius %d = %f", 5, Area(5));
}

