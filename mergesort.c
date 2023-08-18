#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, size_t size);
void print_arr(int *arr, size_t size);

void __merge_sort(int *arr, size_t l, size_t r);
void __merge(int *arr, size_t l, size_t m, size_t r); // TODO

int main(int argc, char **argv) {
    int arr[] = { 8, 7, 4, 1, 5, 2, 3, 6, 0, 9 };
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray size: %zu", size);
    print_arr(arr, size);
    merge_sort(arr, size);
    print_arr(arr, size);

    int arr2[] = { 22, 78, 12, 78, 0, 1, 34, 71, 64, 54, 21, 90, 81, 49 };
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nArray size: %zu", size2);
    print_arr(arr2, size2);
    merge_sort(arr2, size2);
    print_arr(arr2, size2);

    printf("\n");
    return EXIT_SUCCESS;
}

void merge_sort(int *arr, size_t size) {
    __merge_sort(arr, 0, size - 1);
}

void __merge_sort(int *arr, size_t l, size_t r) {
    if (l < r) {
        size_t mid = l + (r - l) / 2;
        __merge_sort(arr, l, mid);
        __merge_sort(arr, mid + 1, r); 
        __merge(arr, l, mid, r);
    }
}

// not in place
void __merge(int *arr, size_t l, size_t m, size_t r) {
    size_t nl = (m - l) + 1;
    size_t nr = (r - (m + 1)) + 1; // simplified will be (r - m)

    int left[nl];
    int right[nr];

    // copying array parts to temporary arrays
    for (size_t i = 0; i < nl; i++) 
        left[i] = arr[l + i];

    for (size_t i = 0; i < nl; i++) 
        right[i] = arr[m + 1 + i];

    size_t i = 0, j = 0;
    size_t k = l;

    while (i < nl && j < nr) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < nr) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void print_arr(int *arr, size_t size) {
    printf("\nArray..\t");

    for (size_t i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
}

