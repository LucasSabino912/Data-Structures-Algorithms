#include <stdio.h>

int binary_search(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calcula el punto medio

        // Verifica si el elemento está en el medio
        if (arr[mid] == key)
            return mid;

        // Si el elemento es menor que el medio, se ignora la mitad derecha
        if (arr[mid] > key)
            high = mid - 1;
        // Si el elemento es mayor que el medio, se ignora la mitad izquierda
        else
            low = mid + 1;
    }

    // Si el elemento no está presente
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binary_search(arr, n, key);
    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");
    return 0;
}

