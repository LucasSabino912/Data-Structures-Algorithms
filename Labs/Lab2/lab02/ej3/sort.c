#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    int pivot = a[der];
    int i = (izq - 1);

    for(unsigned int j = izq; j <= der - 1; j++){
        if(a[j] <= pivot){
            i++;
            swap(a, a[i], a[j]);
        }
    }
    swap(a, a[i + 1], a[der]);
    return(i + 1);
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if(izq < der){
        unsigned int pivot = partition(a, izq, der);
        quick_sort_rec(a, izq, pivot - 1);
        quick_sort_rec(a, pivot + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
    assert(array_is_sorted(a, length));
}

