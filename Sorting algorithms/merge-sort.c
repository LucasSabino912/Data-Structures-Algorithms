#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int lft, int mid, int rgt) {
    int i, j, k;
    int n1 = mid - lft + 1;
    int n2 = rgt - mid;
    int* tmpL = (int*)malloc(n1 * sizeof(int));
    int* tmpR = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays tmpL[] and tmpR[]
    for (i = 0; i < n1; i++)
        tmpL[i] = a[lft + i];
    for (j = 0; j < n2; j++)
        tmpR[j] = a[mid + 1 + j];

    // Merge the temporary arrays back into a[lft..rgt]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = lft; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (tmpL[i] <= tmpR[j]) {
            a[k] = tmpL[i];
            i++;
        } else {
            a[k] = tmpR[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of tmpL[], if any
    while (i < n1) {
        a[k] = tmpL[i];
        i++;
        k++;
    }

    // Copy the remaining elements of tmpR[], if any
    while (j < n2) {
        a[k] = tmpR[j];
        j++;
        k++;
    }

    free(tmpL);
    free(tmpR);
}

void merge_sort_rec(int* a, int lft, int rgt) {
    if (lft < rgt) {
        int mid = lft + (rgt - lft) / 2;

        // Recursively sort the two halves
        merge_sort_rec(a, lft, mid);
        merge_sort_rec(a, mid + 1, rgt);

        // Merge the sorted halves
        merge(a, lft, mid, rgt);
    }
}

void merge_sort(int* a, int n) {
    merge_sort_rec(a, 0, n - 1);
}

// Example usage
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, arr_size);

    printf("Sorted array is \n");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

