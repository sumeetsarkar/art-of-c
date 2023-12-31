#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // memory: allocated on stack
    char str1[] = "John Doe";
    printf("str1: %s\n", str1);

    str1[0] = 'a';
    printf("str1: %s\n", str1);
    
    // memory: allocated on heap with a pointer str2 on stack
    char *str2 = malloc(16 * sizeof(char));
    strncpy(str2, "Clive John", 16);
    printf("str2: %s\n", str2);

    str2[0] = 'a';
    printf("str2: %s\n", str2);

    // memory: undefined
    char *str3 = "Blake harden";
    printf("str3: %s\n", str3);
    // following will cause a segmentation fault/ bus error
    // str3[0] = 'a';

    // strndup mallocs new string with strlen + 1
    // memcpy the string and returns a pointer to it, hence
    // memory: allocated on heap with a pointer str4 on stack
    char *str4 = strndup("Bob", 3);
    printf("str4: %s\n", str4);

    str4[0] = 'a';
    printf("str4: %s\n", str4);

    return EXIT_SUCCESS;
}

