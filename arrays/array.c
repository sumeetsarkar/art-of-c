#include <stdio.h>

int main() {
    short colors[3];

    // will print garbage values until values are assigned
    printf("%d\n", colors[0]);
    printf("%d\n", colors[1]);
    printf("%d\n", colors[2]);

    short sizeColors = sizeof(colors) / sizeof(colors[0]);

    colors[0] = 'r';
    colors[1] = 'g';
    colors[2] = 'b';

    printf("%d colors\n", sizeColors);
    
    for (short i = 0; i < sizeColors; i ++) {
       printf("%d - %c\n", i, colors[i]);
    }

    printf("\n");
    return 0;
}

