#include <stdio.h>

void swap(int* nums, int a, int b){
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}


void insert(int* nums, int i){
	int j = i;
	while(j > 0 && nums[j] < nums[j-1]){
		swap(nums, j-1, j);
		j--;
	}
}

void insertion_sort(int* nums, int numsSize){
	for(int i = 1; i < numsSize; i++){
		insert(nums, i);
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

    insertion_sort(nums, numsSize);

    printf("Array ordenado: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}



