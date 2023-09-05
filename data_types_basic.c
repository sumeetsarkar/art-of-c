#include <stdio.h>

// macros to define bool values
#define FALSE = 0;
#define TRUE = 1;

int main() {
    // integers - signed whole numbers
    
    short s = 0;
    int i = 0;
    long l = 9;
    long long ll = 999;
    long int li = -100;
    char c = 97;
    char ch = 'a';

    printf("short s = %d\n", s);
    printf("int i = %d\n", i);
    printf("long l = %ld\n", l);
    printf("long long ll = %lld\n", ll);
    printf("long int li = %ld\n", li);
    printf("char c = %d\n", c);
    printf("char c = %c\n", c);
    printf("char ch = %d\n", ch);
    printf("char ch = %c\n", ch);
    printf("\n");

    // unsigned integers - whole numbers which can be only positive
    unsigned short us = 38528;
    unsigned int ui = 13;
    unsigned long ul = 9999999999999;

    printf("unsigned short us = %u\n", us);
    printf("unsigned int ui = %u\n", ui);
    printf("unsigned long ul = %lu\n", ul);
    printf("\n");

    // floating point  numbers - real numbers
    float f = 3.14;
    double d = -6.23;

    printf("float f = %f\n", f);
    printf("double d = %f\n", d);
    printf("\n");

    return 0;
}

