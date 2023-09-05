#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t str_len(char *str);
void str_rev(char *str);

int main(int argc, char **argv) {
    printf("\nEnter a string: ");

    char input[32];
    scanf("%s", input);

    printf("Length: %zu", str_len(input));

    str_rev(input);
    printf("\nReversed: %s", input);

    printf("\n");
    return EXIT_SUCCESS;
}

size_t str_len(char *str) {
    size_t len = 0;
    if (str != NULL) {
        while (*str != '\0') {
            str += 1;
            len += 1;
        }
    }
    return len;
}

void str_rev(char *str) {
    int len = str_len(str);
    int low = 0, high = len - 1;

    while (low < len/2) {        
        char swap = str[low];
        str[low] = str[high];
        str[high] = swap;

        low += 1;
        high -= 1;
    }
}

