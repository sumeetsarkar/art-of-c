#include <stdio.h>
#include <stdlib.h>

int bisect_left(int *arr, int size, int target);
int bisect_right(int *arr, int size, int target);
void print_arr(int *arr, int size);

int main(int argc, char **argv) {
    int nums1[] = { 1, 1, 3, 4, 4, 4, 7, 9, 9, 12 };
    int size1 = sizeof(nums1) / sizeof(nums1[0]);

    print_arr(nums1, size1);

    printf("\nbisect_left %d: %d", 0, bisect_left(nums1, size1, 0));
    printf("\nbisect_left %d: %d", 1, bisect_left(nums1, size1, 1));
    printf("\nbisect_left %d: %d", 2, bisect_left(nums1, size1, 2));
    printf("\nbisect_left %d: %d", 4, bisect_left(nums1, size1, 4));
    printf("\nbisect_left %d: %d", 6, bisect_left(nums1, size1, 6));
    printf("\nbisect_left %d: %d", 9, bisect_left(nums1, size1, 9));
    printf("\nbisect_left %d: %d", 13, bisect_left(nums1, size1, 13));

    printf("\n");
    printf("\nbisect_right %d: %d", 0, bisect_right(nums1, size1, 0));
    printf("\nbisect_right %d: %d", 4, bisect_right(nums1, size1, 4));
    printf("\nbisect_right %d: %d", 9, bisect_right(nums1, size1, 9));
    printf("\nbisect_right %d: %d", 13, bisect_right(nums1, size1, 13));

    printf("\n");
    return EXIT_SUCCESS;
}

int bisect_left(int *arr, int size, int target) {
    int ret_val = -1;
    if (arr != NULL && size > 0) {
        int low = 0, high = size;

        while (low < high) {
            int mid = low + ((high - low) / 2);
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        ret_val = low;
    }
    return ret_val;
}

int bisect_right(int *arr, int size, int target) {
    int ret_val = -1;
    if (arr != NULL && size > 0) {
        int low = 0, high = size;

        while (low < high) {
            int mid = low + ((high - low) / 2);
            if (target < arr[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        ret_val = low;
    }
    return ret_val;
}

void print_arr(int *arr, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", i);
    }
}

