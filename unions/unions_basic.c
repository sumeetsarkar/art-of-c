#include <stdio.h>
#include <stdlib.h>

struct mystr {
    int x;
    char y;
    float z;
};

union myunion {
    int x;
    char y;
    float z;
};

int main(int argc, char **argv) {

    struct mystr s1;
    s1.x = 10;
    s1.y = 'a';
    s1.z = 9.43;

    printf("s1.x = %d\n", s1.x);
    printf("s1.y = %c\n", s1.y);
    printf("s1.z = %f\n", s1.z);

    // The best way to understand unions is to contrast it against a struct.
    // The member variables inside of a union all point to SAME memory location
    // unlike how a structs encapsulates different members of same/different
    // types together, all having their OWN memory location.

    union myunion u1;
    u1.x = 10;
    u1.y = 'a';
    u1.z = 9.43;

    // Updating x, y, z all update the SAME memory location
    printf("u1.x = %d\n", u1.x);
    printf("u1.y = %c\n", u1.y);
    printf("u1.z = %f\n", u1.z);

    // but what might be the purpose of such a language feature?
    // check one such example in the next file unions_in_struct.c

    return EXIT_SUCCESS;
}

