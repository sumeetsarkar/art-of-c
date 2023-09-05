#include <stdio.h>
#include <stdlib.h>

int quickselect(int *arr, int size, int k);
int __quickselect(int *arr, int low, int high, int k);
int __partition(int *arr, int low, int high);
void print_arr(int *arr, int size);

int main(int argc, char **argv) {
    int nums1[] = { 83, 36, 74, 50, 28, 11, 29 };
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    print_arr(nums1, len1);

    for (int i = 0; i < len1; i++) {
        int find_smallest = i + 1;
        printf("\nFind smallest %d: %d", find_smallest, quickselect(nums1, len1, find_smallest));
    }

    printf("\n");
    return EXIT_SUCCESS;
}

int quickselect(int *arr, int size, int k) {
    if (k < 1 || k > size) {
        return -1;
    }
    return __quickselect(arr, 0, size - 1, k - 1);
}

int __quickselect(int *arr, int low, int high, int k) {
    int p = __partition(arr, low, high);
    if (p == k)
        return arr[p];
    else if (p < k)
        return __quickselect(arr, p + 1, high, k);
    else
        return __quickselect(arr, low, p - 1, k);
}

int __partition(int *arr, int low, int high) {
    int p_index = low;
    int pivot = arr[high];

    while (low < high) {
        if (arr[low] < pivot) {
            int swap = arr[low];
            arr[low] = arr[p_index];
            arr[p_index] = swap;
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

