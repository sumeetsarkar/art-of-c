#include <stdio.h>
#include <stdlib.h>

void quicksort(int *arr, int size);
void __quicksort(int *arr, int low, int high);
int __partition(int *arr, int low, int high);
void print_arr(int *arr, int size);

int main(int argc, char **argv) {
    int nums1[] = { 83, 36, 74, 50, 28, 11, 29 };
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    print_arr(nums1, len1);

    quicksort(nums1, len1);
    printf("\nSorted");
    print_arr(nums1, len1);

    printf("\n");
    return EXIT_SUCCESS;
}

void quicksort(int *arr, int size) {
    return __quicksort(arr, 0, size - 1); 
}

void __quicksort(int *arr, int low, int high) {
    if (low < high) {
        int p = __partition(arr, low, high);
        __quicksort(arr, low, p - 1);
        __quicksort(arr, p + 1, high);
    }
}

int __partition(int *arr, int low, int high) {
    int p_index = low;
    int pivot = arr[high];
    
    while (low < high) {
        if (arr[low] <= pivot) {
            int swap = arr[p_index];
            arr[p_index] = arr[low];
            arr[low] = swap;
            p_index += 1;
        }
        low += 1;
    }
    arr[high] = arr[p_index];
    arr[p_index] = pivot;
    return p_index;
}

void print_arr(int *arr, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

