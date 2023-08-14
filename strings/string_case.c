#include <stdio.h>

// a 97, z 122
// A 65, Z 90
#define CASE_DIFF 32

// Scoped to only English alphabets
char * to_upper(char *str);
char * to_lower(char *str);

int main(int argc, char **argv) {
    char name[32] = "SUMEET";

    printf("Enter a name: ");
    scanf("%s", name);

    printf("\nlowercase: %s", to_lower(name));
    printf("\nuppercase: %s", to_upper(name));
    printf("\n");
    return 0;
}

char * to_upper(char *str) {
    char *tmp = str;
    while (*tmp != '\0') {
        if (*tmp >= 97 && *tmp <= 122)
            *tmp = *tmp - CASE_DIFF;
        tmp ++;
    }
    return str;
}

char * to_lower(char *str) {
    char *tmp = str;
    while (*tmp != '\0') {
        if (*tmp >= 65 && *tmp <= 90)
            *tmp = *tmp + CASE_DIFF;
        tmp ++;
    }
    return str;
}

