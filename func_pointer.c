#include <stdio.h>
#include <stdlib.h>

void add(int a, int b, void (*pf)(int));
void sub(int a, int b, void (*pf)(int));
void done(const int result);

int main(int argc, char **argv) {

    void (*pf_done)(int) = &done;
    void (*pf_add)(int, int, void (*pf)(int)) = &add;

    add(4, 9, pf_done);
    add(21, 5, pf_done);
    sub(17, 4, pf_done);

    printf("\n");
    return EXIT_SUCCESS;
}

void add(int a, int b, void (*pf)(int)) {
    pf(a + b);
}

void sub(int a, int b, void (*pf)(int)) {
    pf(a - b);
}

void done(const int result) {
    printf("\nDone! %d", result);
}

