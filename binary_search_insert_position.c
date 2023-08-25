#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int size, int target);

int main(int argc, char **argv) {
    int nums[] = { 1, 3, 5, 6 };
    int len = sizeof(nums) / sizeof(nums[0]);

    printf("\n%d: %d", 5, searchInsert(nums, len, 5));
    printf("\n%d: %d", 2, searchInsert(nums, len, 2));
    printf("\n%d: %d", 7, searchInsert(nums, len, 7));
    printf("\n%d: %d", 0, searchInsert(nums, len, 0));
    return EXIT_SUCCESS;
}

// bisect_left
int searchInsert(int* nums, int size, int target) {
    int l = 0, r = size;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

