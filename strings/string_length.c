#include <stdio.h>

size_t string_length(const char *str);

int main(int argc, char **argv) {
    char name[32];

    printf("Enter a string: ");
    scanf("%s", name);

    printf("length: %ld\n", string_length(name));

    printf("length: %ld\n", string_length(NULL));
    printf("length: %ld\n", string_length("Mr. John Doe"));
    return 0;
}

size_t string_length(const char *str) {
    size_t len = 0;

    if (str != NULL) {
        while (str[len] != '\0')
            len ++;
    }

    return len;
}

