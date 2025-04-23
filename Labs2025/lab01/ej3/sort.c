#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*
 - Compiling:

  gcc -Wall -Wextra -pedantic -std=c99 -c main.c
  gcc -Wall -Wextra -pedantic -std=c99 main.o -o main
  ./main

 - Agrego -no-pie para compilar los .o de antes 


*/



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

