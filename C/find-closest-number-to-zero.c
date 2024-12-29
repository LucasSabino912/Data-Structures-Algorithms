// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/find-closest-number-to-zero/

    Given an integer array nums of size n, return the number with the value closest to 0 in nums. 
    If there are multiple answers, return the number with the largest value.
*/

#include <stdio.h>
#include <math.h>

int findClosestNumber(int* nums, int numsSize) {
    int closest = nums[0];
    for (int i = 0; i < numsSize; i++){
        if((abs(nums[i]) < abs(closest)) || ((abs(closest) == abs(nums[i]) && (nums[i] >= closest)))){
            closest = nums[i];
        }  
    }
    return closest;
}

int abs(int n){
    return (n < 0) ? -n : n;
}
