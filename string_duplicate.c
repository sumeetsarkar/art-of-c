#include <stdio.h>
#include <stdlib.h>

int str_len(char *str);
char *str_duplicate(char *src);

int main(int argc, char **argv) {
    char *src = "Hello!";
    char *dup = str_duplicate(src);

    printf("Src: %s, Dup: %s", src, dup);
    printf("\n");
    return EXIT_SUCCESS;
}

int str_len(char *str) {    
    int len = 0;
    if (str != NULL) {
        while (str[len] != '\0') {
            len += 1;
        }
    }
    return len;
}

char *str_duplicate(char *src) {
    int len = str_len(src);
    char *dup = malloc(len + 1);
    
    if (dup == NULL)
        return NULL;

    int i = 0;
    while (i < len) {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

