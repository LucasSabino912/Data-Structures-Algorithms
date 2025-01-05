// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/find-closest-number-to-zero/

    Given an integer array nums of size n, return the number with the value closest to 0 in nums. 
    If there are multiple answers, return the number with the largest value.
*/

int findClosestNumber(int* nums, int numsSize) {
    int i = 0;
    int closest = nums[i];
    while(i < numsSize){
        if((absolute(nums[i]) < absolute(closest)) || ((absolute(nums[i]) == absolute(closest) && (nums[i] > closest)))){
            closest = nums[i];
        }
        i++;
    }

    return closest;
}

int absolute(int n){
    return (n < 0) ? -n : n;
}
