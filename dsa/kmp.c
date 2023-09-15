#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("<prog> <needle> <haystack>\n");
        return EXIT_FAILURE;
    }
    char *needle = argv[1];
    char *haystack = argv[2];

    uint32_t len_needle = strnlen(needle, 128);
    uint32_t lps[len_needle + 1];

    for (uint32_t i = 0; i < len_needle + 1; i++)
        lps[i] = 0;

    uint32_t l = 0, r = 1;

    while (l < r && r < (len_needle + 1)) {
        if (needle[l] == needle[r]) {
            lps[r + 1] = lps[r] + 1;
            l += 1;
        } else {
            l = 0;
        }
        r += 1;
    }

    for (uint32_t i = 0; i < len_needle + 1; i++)
        printf("%d", lps[i]);

    printf("\n");
    printf(" %s\n", needle);
    printf(" %s\n", haystack);

    // search
    uint32_t len_haystack = strnlen(haystack, 128);
    uint32_t i = 0;
    uint32_t j = 0;
    int32_t found_index = -1;

    while (i < len_haystack) {
        if (haystack[i] == needle[j]) {
            i += 1;
            j += 1;
        } else {
            j = lps[j];
            if (j == 0) {
                i += 1;
            }
        }
        if (j == len_needle) {
            found_index = i - len_needle;
            break;
        }
    }

    if (found_index >= 0)
        printf("Match found at %d\n", found_index);

    return EXIT_SUCCESS;
}

