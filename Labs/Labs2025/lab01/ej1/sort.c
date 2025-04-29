#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* 
insertion_sort recorre el arreglo desde la segunda posición (i = 1) hasta el final, 
e inserta cada elemento en la posición correcta dentro del subarreglo ordenado que va creciendo a la izquierda 
*/

static void insert(int a[], unsigned int i, unsigned int length) {
    unsigned int j = 0;
    j = i;
    while(j > 1 && goes_before(a[j], a[j-1])){
        swap(a, j-1, j);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
    }
}
