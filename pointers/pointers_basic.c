#include <stdio.h>

int main(int argc, char **argv) {
    int a = 10; // allocated in stack

    int *p; // a special pointer variable capable to store a memory address
            // allocated in stack
    
    p = &a; // assign address of variable a to the pointer variable
            // use & to get the address of a variable
    
    printf("a: %d\n", a); // print value of variable a
    printf("p: %p\n", p); // print memory address of variable a

    printf("*p: %d\n", *p); // defreference the pointer using * and then
                            // access the value at the memory address pointing
                            // to variable a

    a += 1; // increment the value of variable a
    printf("a: %d\n", a);
    printf("*p: %d\n", *p);

    *p += 1; // increment to the value of variable a by accessing it using the
             // pointer variable.
    printf("a: %d\n", a);
    printf("*p: %d\n", *p);
}

