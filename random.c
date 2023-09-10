#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void random_name_generator(char *str, uint32_t size);

int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc < 3) {
        printf("Usage <prog> <string-length> <count>\n");
        return EXIT_FAILURE;
    }

    uint32_t size = atoi(argv[1]);
    uint32_t count = atoi(argv[2]);

    int i = 0;
    while (i < count) {
        char *r1 = malloc(sizeof(*r1) * size);
        random_name_generator(r1, size);

        printf("%s\n", r1);
        free(r1);
        r1 = NULL;
        i += 1;
    }

    return EXIT_SUCCESS;
}

void random_name_generator(char *str, uint32_t size) {
    if (size && str) {
        const char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        const int8_t charset_size = strlen(charset);
        int8_t i = 0;
        for (i = 0; i < size - 1; i++) {
            int8_t index = rand() % charset_size;
            str[i] = charset[index];
        }
        str[i] = 0;
    }
}

