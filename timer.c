#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_help(uint8_t err);

int main(int argc, char **argv) {
    if (argc < 2) {
        print_help(1);
    }

    uint32_t time_value = atoi(argv[1]);
    char *time_unit = argv[2];
    int seconds = 0;

    if (argc == 2 || (strncmp(time_unit, "s", 1) == 0)) {
        seconds = time_value;
    } else if (strncmp(time_unit, "m", 1) == 0) {
        seconds = time_value * 60;
    } else {
        print_help(1);
    }

    while (seconds > 0) {
        uint32_t h = seconds / 3600;
        uint32_t m = (seconds % 3600) / 60;
        uint32_t s = seconds % 60;

        printf("%02d:%02d:%02d\r", h, m, s);
        fflush(stdout);

        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop) {}
        seconds -= 1;
    }
    printf("\a");
    return EXIT_SUCCESS;
}

void print_help(uint8_t err) {
    printf("<prog> 10 s -> Timer for 10 seconds\n");
    printf("<prog> 10 m -> Timer for 10 minutes\n");
    printf("Defaults to seconds\n");
    if (err) {
        exit(EXIT_FAILURE);
    }
}

