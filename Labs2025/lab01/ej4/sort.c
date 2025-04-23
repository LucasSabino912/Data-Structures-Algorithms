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
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


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


// La función partition se encarga de dividir el arreglo en dos partes, dejando un pivote en su posición final ordenada. 
// Todo lo que queda a su izquierda es menor o igual al pivote, y todo lo que queda a su derecha es mayor.
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int i = 0, j = 0, piv = 0;
    piv = izq;
    i = izq + 1;
    j = der;

    while(i <= j){
        if (a[i] <= a[piv]){
            i++;
        } else if (a[i] >= a[piv]){
            j--;
        } else if(a[i] > a[piv] && a[j] < a[piv]){
            swap(a, i, j);
            i++;
            j--;
        }
    }

    swap(a, piv, j);
    piv = j;

    return piv;
}

// Ordena el arreglo llamando a partition para dividirlo y después aplicar QuickSort recursivamente a cada mitad
static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv = 0;
    if (der > izq){
        piv = partition(a, izq, der);
        quick_sort_rec(a, izq, piv-1);
        quick_sort_rec(a, piv - 1, der);
    }
}



// quick_sort ordena un arreglo a[] de enteros de menor a mayor. 
// Para hacerlo, llama recursivamente a quick_sort_rec, que utiliza partition para dividir el arreglo.
void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
