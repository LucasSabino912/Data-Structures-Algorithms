// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/product-of-array-except-self/

    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.
*/

func productExceptSelf(nums []int) []int {
	prod := make([]int, len(nums))
	value := 1

	for i, v := range nums {
		prod[i] = value
		value *= v
	}

	value = 1
	for i := len(prod) - 1; i >= 0; i-- {
		prod[i] *= value
		value *= nums[i]
	}

	return prod
}
