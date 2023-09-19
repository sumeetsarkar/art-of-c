#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t fill_num_to_char_arr(char *bin, uint32_t size, uint32_t pos, uint32_t num);

int main(int argc, char **argv) {

    if (argc < 2) {
        printf("Usage <prog> <your-string>\n");
        return EXIT_FAILURE;
    }

    // Example:
    // AAAAAAFDDCCCCCCCAEEEEEEEEEEEEEEEEE
    // 6A1F2D7C1A17E

    char *str = argv[1];
    uint32_t len = strnlen(str, 128);
    uint32_t len_result = len * 2;
    char result[len_result];

    uint32_t j = 0;
    uint32_t count = 1;

    for (uint32_t i = 1; i < len; i++) {
        char c = str[i];
        char prev_c = str[i - 1];
        if (c != prev_c) {
            printf("%d%c", count, prev_c);
            j = fill_num_to_char_arr(result, len_result, j, count);
            result[j] = prev_c;
            j += 1;
            count = 1;
        } else {
            count += 1;
        }
    }
    printf("%d%c\n", count, str[len - 1]);
    j = fill_num_to_char_arr(result, len_result, j, count);
    result[j] = str[len - 1];
    result[j + 1] = 0x00;
    printf("%s\n", result);

    return EXIT_SUCCESS;
}

uint32_t fill_num_to_char_arr(char *bin, uint32_t size, uint32_t pos, uint32_t num) {
    int32_t size_available = size - pos;
    if (size_available <= 0) {
        perror("rle bin overflow - no more space");
        exit(EXIT_FAILURE);
    }
    char dec_result[10] = {0x00};
    uint32_t dec_size = 0;
    do {
        uint32_t r = num % 10;
        num = num / 10;
        dec_result[dec_size] = r + 48;
        dec_size += 1;
    } while (num);

    if (dec_size > size_available) {
        perror("rle bin overflow - cannot fit computed count");
        exit(EXIT_FAILURE);
    }
    for (int32_t i = dec_size - 1; i >= 0; i--) {
        bin[pos] = dec_result[i];
        pos += 1;
    }
    return pos;
}

