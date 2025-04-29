#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int length) {
    bool exist = false;
    int i = 1;

    if(length == 1){
        exist = true;
    }

    while (i < length - 1 && !exist) {
        if (a[i-1] < a[i] && a[i] > a[i+1]) {
            exist = true;
        } else {
            i++;
        }
    }

    return exist;
}


/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
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
int cima(int a[], int length) {
    int pos_cima = 0, i = 0;

    // Sabemos que el arreglo tiene cima, entonces solo busco hasta encotrar
    while (i <= length - 1 && a[i] < a[i+1]){
        pos_cima = i+1;
        i++;
    }

    return pos_cima;
}
