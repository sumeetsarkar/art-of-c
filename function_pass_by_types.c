#include <stdio.h>
#include <stdlib.h>

int add_by_value(int x, int y);
int add_by_pointer(int *x, int *y);
void add_by_pointer_res(int *x, int *y, int *res);

int main(int argc, char **argv) {
    printf("\npass by value: %d", add_by_value(8, 1));

    int x = 2;
    int y = 7;
    printf("\npass by pointer: %d", add_by_pointer(&x, &y));

    int res = 0;
    add_by_pointer_res(&x, &y, &res);
    printf("\npass by pointer res: %d", res);

    printf("\n");
    return EXIT_SUCCESS;
}

int add_by_value(int x, int y) {
    return x + y;
}

int add_by_pointer(int *x, int *y) {
    return *x + *y;
}

void add_by_pointer_res(int *x, int *y, int *res) {
    *res = *x + *y;
}

