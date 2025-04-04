#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int i = 0, j = 0, piv = izq;
    i = izq++;
    j = der;
    while(i <= j){
        if(goes_before(a[i], a[piv]) || a[i] == a[piv]){
            i++;
        } else if (goes_before(a[piv], a[j]) || a[j] == a[piv]){
            j--;
        } else if (goes_before(a[piv], a[i]) && goes_before(a[j], a[piv])){
            swap(a,i,j);
            i++;
        }
    }
    swap(a,piv,j);
    piv = j;

    return piv;
}



static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    if (der > izq){
        unsigned int piv = partition(a, izq, der);
        quick_sort_rec(a, izq, piv-1);
        quick_sort_rec(a, piv + 1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


