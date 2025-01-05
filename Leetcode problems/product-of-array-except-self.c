// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/product-of-array-except-self/

    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* prod = malloc(numsSize * sizeof(int));

    if (prod == NULL) {
        exit(EXIT_FAILURE);  // Check if memory allocation was successful
    }

    // Initialize the result array with 1 for the first pass (left product)
    prod[0] = 1;

    // Calculate the product of elements to the left of each index
    for (int i = 1; i < numsSize; i++) {
        prod[i] = prod[i - 1] * nums[i - 1];
    }

    /* calculate the product of elements to the right of each index
       and multiply it with the current value in the result array */
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        prod[i] *= right;
        right *= nums[i];
    }

    return prod;

    // O(1) space complexity solution
}
