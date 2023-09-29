#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int32_t search(const char *haystack, uint32_t hsize,
                const char *needle, uint32_t nsize);

int main(int argc, char **argv) {
    {
        char haystack[] = "babcdaba";
        char needle[] = "cda";

        printf("Found at: %d\n",
                search(haystack, strlen(haystack), needle, strlen(needle)));
    }
    {
        char haystack[] = "babcdaba";
        char needle[] = "abcdaba";

        printf("Found at: %d\n",
                search(haystack, strlen(haystack), needle, strlen(needle)));
    }
    {
        char haystack[] = "babcdaba";
        char needle[] = "daba";

        printf("Found at: %d\n",
                search(haystack, strlen(haystack), needle, strlen(needle)));
    }
    {
        char haystack[] = "the quick brown fox jumps over the lazy dog";
        char needle[] = "azy do";

        printf("Found at: %d\n",
                search(haystack, strlen(haystack), needle, strlen(needle)));
    }
    return EXIT_SUCCESS;
}

int32_t search(const char *haystack, uint32_t hsize,
                const char *needle, uint32_t nsize) {
    if (hsize == 0 || nsize == 0)
        return -1;
    if (!haystack || !needle)
        return -1;
    if (nsize > hsize)
        return -1;
    if (strncmp(haystack, needle, nsize) == 0)
        return 0;

    int32_t max_exponent = nsize - 1;
    int32_t min_exponent = 0;

    int32_t hash_needle = 0;
    int32_t hash_haystack_sliding = 0;
    for (int32_t i = max_exponent; i >= min_exponent; i--) {
        hash_needle += (pow(10, i) * needle[nsize - i - 1]);
        hash_haystack_sliding += (pow(10, i) * haystack[nsize - i - 1]);
    }

    int32_t max_multiplier = pow(10, max_exponent);
    int32_t min_multiplier = pow(10, min_exponent);
    int32_t start = 0;
    int32_t i = 0;
    for (i = nsize; i < hsize; i++) {
        start = i - nsize;
        if (hash_haystack_sliding == hash_needle) {
            if (strncmp(haystack + start, needle, nsize) == 0)
                return start;
        }
        char incoming_char = haystack[i];
        char outgoing_char = haystack[start];
        int32_t hash_incoming_char = incoming_char * min_multiplier;
        int32_t hash_outgoing_char = outgoing_char * max_multiplier;

        hash_haystack_sliding -= hash_outgoing_char;
        hash_haystack_sliding *= 10;
        hash_haystack_sliding += hash_incoming_char;
    }
    
    start = i - nsize;
    if (hash_haystack_sliding == hash_needle) {
        if (strncmp(haystack + start, needle, nsize) == 0)
            return start;
    }
    return -1;
}

