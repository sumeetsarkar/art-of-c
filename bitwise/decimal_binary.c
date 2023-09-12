#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

uint32_t ubin_to_dec(const char *bit_rep);
char *udec_to_bin(uint32_t dec);

void test_ubin_to_dec(void);
void test_udec_to_bin(void);

int main(int argc, char **argv) {
    test_ubin_to_dec();
    test_udec_to_bin();
    return EXIT_SUCCESS;
}

void test_ubin_to_dec(void) {
    assert(ubin_to_dec("0") == 0);
    assert(ubin_to_dec("1") == 1);
    assert(ubin_to_dec("") == 0);
    assert(ubin_to_dec("10") == 2);
    assert(ubin_to_dec("1011") == 11);
    assert(ubin_to_dec("11000110") == 198);
    assert(ubin_to_dec(NULL) == 0);
    assert(ubin_to_dec("c") == 0);
    assert(ubin_to_dec("abcde") == 0);
    assert(ubin_to_dec("10101abcde") == 0);
    assert(ubin_to_dec("10101o1") == 0);
    assert(ubin_to_dec("1111111111111111111111111111111") == 2147483647);
}

void test_udec_to_bin(void) {
    uint32_t nums[] = {
        7,
        100,
        11,
        1,
        0,
        00,
        2147483647
    };
    const char values[][64] = {
        "111",
        "1100100",
        "1011",
        "1",
        "0",
        "0",
        "1111111111111111111111111111111"
    };

    uint32_t MAX_SIZE = 31;
    for (uint32_t i = 0; i < 6; i++) {
        char *bin = udec_to_bin(nums[i]);
        const char *dec = values[i];
        assert(strncmp(bin, dec, MAX_SIZE) == 0);
        free(bin);
    }
    // out of bounds
    assert(udec_to_bin(2147483648) == NULL);
}

uint32_t ubin_to_dec(const char *bit_rep) {
    uint8_t BASE = 2; 
    uint8_t MAX_STR_LEN = 31;
    uint32_t dec = 0;

    if (bit_rep == NULL) {
        return dec;
    }

    uint32_t len = strnlen(bit_rep, MAX_STR_LEN);
    for (uint32_t i = 0; i < len; i++) {
        if (!(bit_rep[i] == '1' || bit_rep[i] == '0'))
            return 0;
    }

    for (uint32_t i = 0; i < len; i++) {
        uint8_t bit = bit_rep[i] == '0' ? 0 : 1;
        dec += pow(BASE, len - i - 1) * bit;
    }
    return dec;
}

char *udec_to_bin(uint32_t dec) {
    uint8_t BASE = 2; 
    uint32_t MAX_SIZE = 31;

    char *bin = malloc(MAX_SIZE + 1);
    if (bin == NULL)
        return bin;

    if (dec == 0) {
        bin[0] = '0';
        bin[1] = '\0';
        return bin;
    }

    uint32_t i = 0;
    while (dec > 0 && i < MAX_SIZE) {
        div_t r = div(dec, BASE);
        dec = r.quot;
        bin[i] = r.rem == 0 ? '0' : '1';
        i += 1;
    }
    if (dec > 0) {
        free(bin);
        bin = NULL;
        return bin;
    }
    bin[i] = '\0';

    // str reverse
    uint32_t len = i;
    int low = 0, high = len - 1;

    while (low < len/2) {        
        char swap = bin[low];
        bin[low] = bin[high];
        bin[high] = swap;

        low += 1;
        high -= 1;
    }
    return bin;
}

