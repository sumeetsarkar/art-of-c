#include <stdio.h>

#define SIZE 32

char * string_cat(char *s1, const char *s2);

int main(int argc, char **argv) {
    char s1[SIZE * 2], s2[SIZE];

    printf("Enter a first name: ");
    scanf("%s", s1);

    printf("Enter a last name: ");
    scanf("%s", s2);

    string_cat(s1, s2);
    printf("%s\n", s1);
    return 0;
}

char * string_cat(char *s1, const char *s2) {
    while (*s1 != '\0') {
        s1 ++;
    }
    while (*s2 != '\0') {
        *s1 = *s2;
        s1 ++;
        s2 ++;
    }
    *s1 = *s2;
    return s1;
}

