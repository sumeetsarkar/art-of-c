#include <stdio.h>

void update_and_disp();
void update_and_disp_static();
void test_func();
static void test_func_static();

int main(int argc, char **argv) {
    update_and_disp();
    update_and_disp();
    update_and_disp();

    update_and_disp_static();
    update_and_disp_static();
    update_and_disp_static();

    test_func();
    test_func_static();

    printf("\n");
}

void update_and_disp() {
    int count = 0;
    printf("\ncount: %d", count);
    count += 1;
}

void update_and_disp_static() {
    static int count = 0;
    printf("\nstatic count: %d", count);
    count += 1;
}

void test_func() {
    printf("\nRegular Function"); 
}

static void test_func_static() {
    //File scoped
    printf("\nStatic Function"); 
}

