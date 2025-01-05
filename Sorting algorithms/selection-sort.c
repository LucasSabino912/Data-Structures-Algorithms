#include <stdio.h>

void swap(int* nums, int a, int b){
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

int min_pos_from(int* nums, int i, int numsSize){
	int min = i;
	for(int j = i+1; j < numsSize; j++){
		if(nums[j] < nums[min]){
			min = j;
		}
	}
	return min;
}

void selection_sort (int* nums, int numsSize){
	int min = 0;
	for(int i = 0; i < numsSize - 1; i++){
		min = min_pos_from(nums, i, numsSize);
		swap(nums, i, min);	
	}
}

int main() {
    int nums[] = {64, 34, 25, 12, 22, 11, 90};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Array original: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    selection_sort(nums, numsSize);

    printf("Array ordenado: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

