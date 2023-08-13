#include <stdio.h>

int main(int argc, char **argv) {
    char colors[4];
    colors[0] = 'r';
    colors[1] = 'g';
    colors[2] = 'b';

    // no null check, fixed size iteration
    for (int i = 0; i < 4; i ++) {
        printf("val:%c, ", colors[i]);
    }
    printf("\n");

    char colors2[] = { 'r', 'g', 'b' };
    // null encountered after b
    for (int i = 0; colors2[i] != '\0'; i ++) {
        printf("val:%c, ", colors2[i]);
    }
    printf("\n");

    char colors3[] = { 'r', 'g', 'b', '\0' };
    // explicit null
    for (int i = 0; colors3[i] != '\0'; i ++) {
        printf("val:%c, ", colors3[i]);
    }
    printf("\n");

    // note the size declaration
    char colors4[4] = { 'r', 'g', 'b', 'y' };
    // null encountered after y
    for (int i = 0; colors4[i] != '\0'; i ++) {
        printf("val:%c, ", colors4[i]);
    }
    printf("\n");

    char colors5[4] = { 'r', 'g', 'b' };
    char *p5 = colors5; // same as char *p5 = &colors5[0];
    printf("p5: %s\n", p5); // rgb

    char *p_temp5 = p5;
    printf("p_temp5: %s\n", p_temp5); // rgb
    printf("p_temp5 first char: %c\n", *p_temp5); // r
    printf("p_temp5 second char: %c\n", *(p_temp5 + 1)); // g
    printf("p_temp5 third char: %c\n", *(p_temp5 + 2)); // b
    // *(p_temp5 + 1) not same as *p_temp5 + 1
    // *(p_temp5 + 1) is an increment in pointer address and * to print value at that address
    // *p_temp5 + 1 is increment to the value at *p_temp5
    printf("*p_temp5 + 1: %c\n", *p_temp5 + 1); // s
    printf("*p_temp5 + 2: %c\n", *p_temp5 + 2); // t

    printf("printing by incrementing pointer address in loop\n");
    while (*p_temp5 != '\0') {
        printf("%c ", *p_temp5); // r g b
        p_temp5 = p_temp5 + 1;
    }
    printf("\nAfter reaching null, last value of p_temp5: %c", *p_temp5);
    printf("\np5: %s", p5);
    printf("\np_temp5 (lost address of p5): %s", p_temp5);
    printf("\n");

    // get 'by' from 'rgby'
    char colors6[] = { 'r', 'g', 'b', 'y', '\0' };
    char *p6 = &colors6[2]; // note the null termination above
    printf("\np6: %s", p6);
    
    printf("\n");
    return 0;
}

