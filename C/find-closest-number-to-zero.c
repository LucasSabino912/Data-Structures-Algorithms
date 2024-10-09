// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/find-closest-number-to-zero/

    Given an integer array nums of size n, return the number with the value closest to 0 in nums. 
    If there are multiple answers, return the number with the largest value.
*/

#include <stdio.h>
#include <math.h>

// Define my own absolute function
int myAbs(int n){
    return n < 0 ? -n : n;
}

int findClosestNumber(int* nums, int numsSize) {
    int closest = nums[0];
    for (int i = 0; i < numsSize; i++){
        // Immediate return 0 if we get 0 as number in the array
        if(nums[i] == 0){
            return 0;

        }
        // Check for the absolute minimum element 
        if(myAbs(nums[i]) < myAbs(closest)){
            closest = nums[i];
        }
        // If we have the same difference, always consider the positive 
        else if ((myAbs(nums[i]) == myAbs(closest)) && nums[i] > closest){
            closest = nums[i];
        }
    }
    return closest;
}
