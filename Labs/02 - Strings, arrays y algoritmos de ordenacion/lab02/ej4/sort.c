#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}

static void insert(int a[], unsigned int i) {
    while (i > 0 && goes_before(a[i], a[i-1])){
        swap(a, i-1, i);
        i--;
    }
}
void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}

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
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
