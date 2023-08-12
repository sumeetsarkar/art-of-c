#include <stdio.h>

int main() {
    int num[] = { 11, 22, 33, 44, 55 };
    int num2[1] = { 10, 20, 30, 40, 50 };

    printf("%d\t", num[1]);
    printf("%d\t", num[5]); // garbage
    printf("%d\n", num[6]); // garbage

    printf("%d\t", num2[0]);
    printf("%d\t", num2[1]); // garbage
    printf("%d\n", num2[2]); // garbage
    
    int mul_numbers[][6] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}
    };

    printf("%d\t", mul_numbers[0][4]);
    // not initialized, zero
    printf("%d\t", mul_numbers[0][5]);

    // even though out of bounds,
    // interestingly it prints the row 1 items
    printf("%d\t", mul_numbers[0][6]); // row 1 col 0
    printf("%d\n", mul_numbers[0][7]); // row 1 col 1

    printf("%d\t", mul_numbers[1][4]);
    // not initialized, zero
    printf("%d\t", mul_numbers[1][5]);

    // at least in the clang compiler and runtime
    // these out of bounds indexes were reading the
    // above declared array num and outputs
    printf("%d\t", mul_numbers[1][6]); // num[0] 11
    printf("%d\t", mul_numbers[1][7]); // num[1] 22
    printf("%d\n", mul_numbers[1][8]); // num[2] 33

    // altering num[2]?
    mul_numbers[1][8] = 100;

    // yes it did!
    printf("%d\t", num[2]);
    printf("\n");

    for (int i = 0; i < 5; i ++) {
        printf("%d\t", num[i]);
    }
    // outputs
    // 11, 22, 100, 44, 55
    
    // okay so we are overstepping the bounds of other variables now, huh?
    // c is gonna be interesting
    
    printf("\n");
    return 0;
}

