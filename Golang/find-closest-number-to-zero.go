// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/find-closest-number-to-zero/

    Given an integer array nums of size n, return the number with the value closest to 0 in nums. 
    If there are multiple answers, return the number with the largest value.
*/

func findClosestNumber(nums []int) int {
    closest := nums[0]
    myAbs := func (n int) int {
        if n < 0 {
            return -n
        }
        return n
    } 

    for _,i := range nums[1:] {
        if i == 0 {
            return 0
        }
        if myAbs(i) <= myAbs(closest){
            if myAbs(i) == myAbs(closest) && i >= closest{
                closest = i
            } else if myAbs(i) < myAbs(closest){
                closest = i
            }
        }
    }
    return closest
}