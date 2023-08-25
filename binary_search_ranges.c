#include <stdio.h>
#include <stdlib.h>

int binary_search_left(int *nums, int size, int target);
int binary_search_right(int *nums, int size, int target);
int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main(int argc, char **argv) {
    int nums[] = { 5, 7, 7, 8, 8, 10 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int *res;
    int res_size; // ignore

    res = searchRange(nums, size, 8, &res_size);
    printf("\n[%d, %d]", res[0], res[1]);
    free(res);

    res = searchRange(nums, size, 6, &res_size);
    printf("\n[%d, %d]", res[0], res[1]);
    free(res);

    res = searchRange(nums, size, 0, &res_size);
    printf("\n[%d, %d]", res[0], res[1]);
    free(res);

    int nums1[] = {};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);

    res = searchRange(nums1, size1, 0, &res_size);
    printf("\n[%d, %d]", res[0], res[1]);
    free(res);

    int nums2[] = { 1 };
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    res = searchRange(nums2, size2, 1, &res_size);
    printf("\n[%d, %d]", res[0], res[1]);
    free(res);

    int nums3[] = { 2, 2 };
    int size3 = sizeof(nums3) / sizeof(nums3[0]);

    res = searchRange(nums3, size3, 3, &res_size);
    printf("\n[%d, %d]", res[0], res[1]);
    free(res);

    res = searchRange(nums3, size3, 2, &res_size);
    printf("\n[%d, %d]", res[0], res[1]);
    free(res);

    printf("\n");
    return EXIT_SUCCESS;
}

/**
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *res = malloc(sizeof(int) * (*returnSize));
    res[0] = -1;
    res[1] = -1;

    res[0] = binary_search_left(nums, numsSize, target);
    if (res[0] == -1) {
        res[1] = -1;
    } else {
        res[1] = binary_search_right(nums, numsSize, target);
    }
    return res;
}

int binary_search_left(int *nums, int size, int target) {
    int l = 0, r = size;
    if (size < 1) {
        return -1;
    }

    while (l < r) {
        int m = l + ((r - l) / 2);

        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return nums[l] == target ? l : -1;
}

int binary_search_right(int *nums, int size, int target) {
    int l = 0, r = size;
    if (size < 1) {
        return -1;
    }

    while (l < r) {
        int m = l + ((r - l) / 2);

        if (target < nums[m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (nums[l - 1] == target)
        return l - 1;
    return -1;
}

