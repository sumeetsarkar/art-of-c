#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int max_subarray_sum(int *arr, int len);

int main(int argc, char **argv) {
    int arr1[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("\nMax subarray sub: %i", max_subarray_sum(arr1, len1));

    int arr2[] = { 1 };
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("\nMax subarray sub: %i", max_subarray_sum(arr2, len2));

    int arr3[] = { 5, 4, -1, 7, 8 };
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("\nMax subarray sub: %i", max_subarray_sum(arr3, len3));

    int arr4[] = {};
    int len4 = sizeof(arr4) / sizeof(arr4[0]);
    printf("\nMax subarray sub: %i", max_subarray_sum(arr4, len4));

    int arr5[] = { -1 };
    int len5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("\nMax subarray sub: %i", max_subarray_sum(arr5, len5));

    printf("\n");
    return EXIT_SUCCESS;
}

int max_subarray_sum(int *arr, int n) {
    // kadane's algorithm
    int running_sum = -(pow(10, 4) + 1);
    int max_sum = -(pow(10, 4) + 1);
    int i = 0;

    while (i < n) {
        running_sum = arr[i] > running_sum + arr[i] ? arr[i] : running_sum + arr[i];
        max_sum = max_sum > running_sum ? max_sum : running_sum;
        i += 1;
    }
    return n > 0 ? max_sum : 0;
}

