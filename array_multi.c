#include <stdio.h>

int main() {
    int numbers[3][3];

    printf("%d\n", numbers[0][0]);

    int rows = sizeof(numbers) / sizeof(numbers[0]);
    int cols = sizeof(numbers[0]) / sizeof(numbers[0][0]);

    printf("%d, %d\n", rows, cols);

    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < cols; j ++) {
            printf("%d\t", numbers[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}

