#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */

// Para que sea DyV y de orden O(log n) hago una busqueda binaria
int cima_log(int a[], int length) {
    int izq = 0;
    int der = length - 1;

    while (izq < der) {
        int medio = (izq + der) / 2;

        if (a[medio] < a[medio + 1]) {
            // Subida: la cima está a la derecha
            izq = medio + 1;
        } else {
            // Bajada: la cima está en medio o a la izquierda
            der = medio;
        }
    }

    return izq;  // izq == der en este punto, que es la posición de la cima
}
/*
    Si estoy en un punto de subida (a[m] < a[m+1]), la cima debe estar a la derecha.

    Si estoy en un punto de bajada (a[m] > a[m+1]), entonces la cima está en m o antes.
*/