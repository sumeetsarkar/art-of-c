#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    const int START = 2;
    const int LIMIT = 101;
    int primes[LIMIT];
    for (int i = 0; i < LIMIT; i++)
        primes[i] = 1;

    for (int i = START; i < LIMIT; i++) {
        if (primes[i] == 0)
            continue;
        for (int j = 2; j < LIMIT; j++) {
            int mul_val = i * j;
            if (mul_val >= LIMIT)
                break;
            primes[mul_val] = 0;
        }
    }
    int count = 0;
    for (int i = START; i < LIMIT; i++) {
        if (primes[i]) {
            printf("%d, ", i);
            count += 1;
        }
    }
    printf("\nprime numbers in between %d and %d = %d", START - 1, LIMIT - 1, count);
    return EXIT_SUCCESS;
}

