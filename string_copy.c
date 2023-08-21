#include <stdio.h>

#define SIZE 32

char * string_copy(char *dest, const char *src);

int main(int argc, char **argv) {
    char actual[SIZE];
    char copied[SIZE + 1];

    printf("Enter a string: ");
    scanf("%s", actual);

    string_copy(copied, actual);

    printf("Actual: %s\n", actual);
    printf("Copied: %s\n", copied);
    return 0;
}

char * string_copy(char *dest, const char *src) {
    if (src != NULL && dest != NULL) {
       while (*src != '\0') {
           *dest = *src;
           src ++;
           dest ++;
       }
    }
    return dest;
}

