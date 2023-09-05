#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int len, int value);

int main(int argc, char **argv) {
    int arr[] = { 12, 18, 24, 36, 48, 54, 96 };
    int len = sizeof(arr)/ sizeof(arr[0]);

    int find_value = 24;
    printf("\nFind value: %d, Found at: %d", find_value, binary_search(arr, len, find_value));

    find_value = 54;
    printf("\nFind value: %d, Found at: %d", find_value, binary_search(arr, len, find_value));

    for (int i = 0; i < len; i++) {
        printf("\nFind value: %d, Found at: %d", arr[i], binary_search(arr, len, arr[i]));
    }

    // Not present check
    find_value = 0;
    printf("\nFind value: %d, Found at: %d", find_value, binary_search(arr, len, find_value));

    find_value = 120;
    printf("\nFind value: %d, Found at: %d", find_value, binary_search(arr, len, find_value));

    int arr2[] = {};
    int len2 = sizeof(arr2)/ sizeof(arr2[0]);
    find_value = 1;
    printf("\nFind value: %d, Found at: %d", find_value, binary_search(arr2, len2, find_value));

    int arr3[] = { 1 };
    int len3 = sizeof(arr3)/ sizeof(arr3[0]);
    find_value = 1;
    printf("\nFind value: %d, Found at: %d", find_value, binary_search(arr3, len3, find_value));

    find_value = 0;
    printf("\nFind value: %d, Found at: %d", find_value, binary_search(arr3, len3, find_value));

    printf("\n");
    return EXIT_SUCCESS;
}

int binary_search(int *arr, int len, int value) {
    int l = 0, r = len;
    
    while (l < r) {
        int m = l + ((r - l) / 2);

        if (arr[m] < value) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return arr[l] == value ? l : -1;
}

