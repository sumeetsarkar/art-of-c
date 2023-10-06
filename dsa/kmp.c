#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("<prog> <haystack> <needle>\n");
        //Eg: ./kmp "aabaaabaaac" "aabaaac"
        return EXIT_FAILURE;
    }
    char *haystack = argv[1];
    char *needle = argv[2];

    uint32_t len_needle = strnlen(needle, 128);
    uint32_t lps[len_needle];

    for (uint32_t i = 0; i < len_needle; i++)
        lps[i] = 0;

    uint32_t j = 0, i = 1;
    while (i < len_needle) {
        if (needle[i] == needle[j]) {
            lps[i] = lps[j] + 1;
            i += 1;
            j += 1;
        } else if (j > 0) {
            j = lps[j - 1];
        } else {
            i += 1;
        }
    }

    for (uint32_t i = 0; i < len_needle; i++)
        printf("%d", lps[i]);

    printf("\n");
    printf(" %s\n", needle);
    printf(" %s\n", haystack);

    // search
    uint32_t len_haystack = strnlen(haystack, 128);
    i = 0;
    j = 0;
    int32_t found_index = -1;

    while (i < len_haystack) {
        if (haystack[i] == needle[j]) {
            i += 1;
            j += 1;
        } else if (j > 0) {
            j = lps[j - 1];
        } else {
            i += 1;
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

