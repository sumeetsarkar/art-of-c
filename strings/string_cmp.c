#include <stdio.h>

#define SIZE 32

int string_cmp(const char *s1, const char *s2);

int main(int argc, char **argv) {
    char word1[SIZE], word2[SIZE];

    printf("Enter word 1: ");
    scanf("%s", word1);

    printf("Enter word 2: ");
    scanf("%s", word2);

    int result = string_cmp(word1, word2);
    
    switch (result) {
        case 0: printf("Words are the same\n");
                break;
        case 1: printf("Word2 is lexicographically smaller\n");
                break;
        case -1: printf("Word1 is lexicographically smaller\n");
                break;
    }

    return 0;
}

int string_cmp(const char *s1, const char *s2) {
    int result = 0;

    if (s1 != NULL && s2 != NULL) {
        while (1) {
            if (*s1 == '\0' && *s2 != '\0') {
                result = -1;
                break;
            }
            if (*s1 != '\0' && *s2 == '\0') {
                result = 1;
                break;
            }
            if (*s1 == '\0' && *s2 == '\0') {
                break;
            }
            if (*s1 != *s2) {
                result = *s1 - *s2 < 0 ? -1 : 1;
                break;
            }

            s1 ++;
            s2 ++;
        }
    }
    return result;
}

