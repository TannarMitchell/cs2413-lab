#include <stdlib.h>

/*
Function: findKthLargest
Finds the k-th largest element in the array nums of size numsSize.
*/
int cmpDesc(const void* a, const void* b) {
    return *(int*)b - *(int*)a; // descending order
}

int findKthLargest(int* nums, int numsSize, int k) {
    // Sort the array in descending order
    qsort(nums, numsSize, sizeof(int), cmpDesc);
    // Return the k-th largest element (arrays are 0-indexed)
    return nums[k - 1];
}
