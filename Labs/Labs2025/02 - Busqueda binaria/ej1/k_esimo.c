#include <stdbool.h>
#include "k_esimo.h"

// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */
int k_esimo(int a[], int length, int k) {
    int izq = 0, der = length - 1, pos_k = 0, res = 0;

    while(izq <= der){
        // Uso partition para tirar todos los menores a k a la izquierda y los mayores a la derecha
        // No me interesa ordenar todo el arreglo pero si me interesa que k se encuentre donde deberia estar
        pos_k = partition(a, izq, der);

        if(pos_k == k){ // pos_k esta donde deberia estar
            res = a[pos_k];
            izq = der + 1; // Fuerzo la salida del bucle, si se 
        } else if (k < pos_k){ // pos_k esta mas arriba todavia del k, modifico der y hago partition de nuevo
            der = pos_k - 1;
        } else { // pos_k esta mas abajo todavia del k, modifico izq y hago partition de nuevo
            izq = pos_k + 1;
        }
    }

    return res;
}

int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
