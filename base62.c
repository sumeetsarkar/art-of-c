#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0
#define MAX_LEN 8

const char *CHARSET =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
const uint8_t BASE = 62;
const char *FLAG_ENCODE = "-e";
const char *FLAG_DECODE = "-d";
const int8_t OFFSET_ASCII_CHARSET_ALPHA_UC = -65;
const int8_t OFFSET_ASCII_CHARSET_ALPHA_LC = -97 + 26;
const int8_t OFFSET_ASCII_CHARSET_NUMBER = -48 + 26 + 26;

void base62_encode(char *input, uint32_t size, char *encoded);
uint64_t base62_decode(char *input, uint32_t size);
int validate_args(int argc, char **argv);
void print_usage(void);

int main(int argc, char **argv) {
    if (validate_args(argc, argv) > 0) {
        print_usage();
        return EXIT_FAILURE;
    }
    char *flag = argv[1];
    char *input = argv[2];

    uint32_t size = strnlen(input, MAX_LEN);
    if (DEBUG)
        printf("size=%d\n", size);

    if (size == 0)
        return EXIT_FAILURE;

    if (size == MAX_LEN && input[size] != 0)
        return EXIT_FAILURE;

    if (strncmp(flag, FLAG_ENCODE, 2) == 0) {
        char *encoded = malloc((size + 1) * sizeof(char));
        base62_encode(input, size, encoded);
        printf("%s\n", encoded);
        free(encoded);

    } else if (strncmp(flag, FLAG_DECODE, 2) == 0) {
        uint64_t decoded = base62_decode(input, size);
        printf("%llu\n", decoded);
    }

    return EXIT_SUCCESS;
}

void base62_encode(char *input, uint32_t size, char *encoded) {
    if (!input || !encoded)
        exit(EXIT_FAILURE);

    for (uint32_t i = 0; i < size; i++)
        if (!isdigit(input[i]))
            exit(EXIT_FAILURE);

    uint64_t num = atoll(input);
    uint32_t i = 0;
    do {
        uint8_t r = num % BASE;
        num = num / BASE;

        if (DEBUG)
            printf("%d [%c] %llu\n", r, CHARSET[r], num);

        encoded[i] = CHARSET[r];
        i += 1;
    } while (num);
    encoded[i] = 0x00;
    /*printf("encoded=%s\n", encoded);*/

    uint32_t len = strnlen(encoded, MAX_LEN);
    for (uint32_t j = 0; j < len/2; j++) {
        char swap = encoded[j];
        encoded[j] = encoded[len - j - 1];
        encoded[len - j - 1] = swap;
    }
}

uint64_t base62_decode(char *input, uint32_t size) {
    if (!input)
        exit(EXIT_FAILURE);

    for (uint32_t i = 0; i < size; i++)
        if (!isalnum(input[i]))
            exit(EXIT_FAILURE);

    uint64_t decoded = 0;
    for (uint32_t i = 0; i < size; i++) {
        char c = input[i];
        uint8_t index = 0;
        uint8_t exponent = size - i - 1;
        if (isalpha(c)) {
            if (islower(c)) {
                index = c + OFFSET_ASCII_CHARSET_ALPHA_LC;
            } else {
                index = c + OFFSET_ASCII_CHARSET_ALPHA_UC;
            }
        } else {
            index = c + OFFSET_ASCII_CHARSET_NUMBER;
        }
        if (DEBUG)
            printf("pow=%d [%c] %d\n", exponent, c, index);
        decoded = decoded + (powl(BASE, exponent) * index);
    }
    return decoded;
}

int validate_args(int argc, char **argv) {
    if (argc < 3)
        return 1;
    char *flag = argv[1];
    if (strncmp(flag, FLAG_ENCODE, 2) == 0
        || strncmp(flag, FLAG_DECODE, 2) == 0) {
        return 0;
    }
    return 1;
}

void print_usage(void) {
    printf("Usage: <prog> -[e|d] <input_text>\n");
    printf("Limitation: works only numbers\n");
}

