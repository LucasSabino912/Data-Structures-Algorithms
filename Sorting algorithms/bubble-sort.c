#include <stdio.h>

// Function to swap two elements
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to implement bubble sort
void bubble_sort(int arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n-1; i++) {
        swapped = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        // If no two elements were swapped in the inner loop, break
        if (swapped == 0)
            break;
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, n);
    printf("Sorted array: \n");
    print_array(arr, n);
    return 0;
}

