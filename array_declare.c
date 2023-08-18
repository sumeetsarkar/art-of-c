#include <stdio.h>

#define SIZE 10
int global_arr[SIZE]; // allowed

int n = 100;
// int global_var_len_arr[n]; // x error: not allowed

const int n2 = 200;
int global_var_len_arr2[n2]; // ! warn: var len arr folded to constant array
                             // as an extention

int main(int argc, char **argv) {
    int arr_var_len[argc]; // allowed
    int n = 100;
    int arr_var_len2[n]; // allowed

    int x = 0;
    printf("\nEnter length of arr:");
    scanf("\n%d", &x);
    int arr_var_len3[x];
    printf("\nsize of arr_var_len3: %zu", sizeof(arr_var_len3));
    printf("\nlength of arr_var_len3: %zu", sizeof(arr_var_len3)/ sizeof(arr_var_len3[0]));
    printf("\n\n");

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

