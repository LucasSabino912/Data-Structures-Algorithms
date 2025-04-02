#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
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

void swap(int a[], unsigned int x, unsigned int y){
    unsigned int tmp;
    tmp = a[x];
    a[x] = a[y];
    a[y] = tmp; 
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (der > izq){
        unsigned int piv = partition(a, izq, der);
        quick_sort_rec(a, izq, piv-1);
        quick_sort_rec(a, piv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

