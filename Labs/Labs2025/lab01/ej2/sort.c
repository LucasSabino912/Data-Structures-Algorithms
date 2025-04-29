#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


// Quick_sort_rec me parte en subarrays 
// Partition parte el arreglo y me deja el piv en el medio del arreglo
static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv = 0;
    if (der > izq){
        piv = partition(a, izq, der);
        quick_sort_rec(a, izq, piv-1);
        quick_sort_rec(a, piv - 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

