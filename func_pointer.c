#include <stdio.h>
#include <stdlib.h>

void add(int a, int b, void (*pf)(int));
int add_r(int a, int b);
void sub(int a, int b, void (*pf)(int));
void done(const int result);

int main(int argc, char **argv) {
    void (*pf_done)(int) = &done;

    add(4, 9, pf_done);
    add(21, 5, pf_done);
    sub(17, 4, pf_done);

    void (*pf_add)(int, int, void (*pf)(int)) = &add;
    pf_add(30, 6, pf_done);

    int (*pf_add_r)(int, int) = &add_r;
    printf("\nResult returning func pointer: %d", pf_add_r(10, 8));

    printf("\n");
    return EXIT_SUCCESS;
}

void add(int a, int b, void (*pf)(int)) {
    pf(a + b);
}

int add_r(int a, int b) {    
    return a + b;
}

void sub(int a, int b, void (*pf)(int)) {
    pf(a - b);
}

void done(const int result) {
    printf("\nDone! %d", result);
}

