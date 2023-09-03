#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    printf("\natoi: %i", atoi("99"));
    printf("\natol: %li", atol("99999999999")); // check atoll
    printf("\natof: %f", atof("9998.89"));

    div_t res1 = div(9, 2);
    printf("\nDiv of 9 and 2: %i, %i", res1.quot, res1.rem);

    ldiv_t res2 = ldiv(99999999999, 22222222222);
    printf("\nDiv of 9 and 2: %li, %li", res2.quot, res2.rem);

    printf("\nAbsolute value: %i", abs(100)); // check labs
    printf("\nAbsolute value: %i", abs(-100));

    printf("\nEnv value: [path] %s", getenv("HOME"));

    char *curr_dir = ".";
    char actual_path[256 + 1];
    realpath(curr_dir, actual_path);
    printf("\nrealpath %s, %s", curr_dir, actual_path);

    system("date");
    system("clang -v");

    printf("\n");
    return EXIT_SUCCESS;
}

