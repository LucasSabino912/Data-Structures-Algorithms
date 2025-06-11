#include <limits.h>
#include <stdio.h>
#include "knapsack.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void print_table(int n, int k, int table[n][k]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (table[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", table[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Resuelve el problema de la mochila
 *
 * @param values valores de los objetos
 * @param weights pesos de los objetos
 * @param n cantidad de objetos
 * @param W capacidad de la mochila
 */
int knapsack(int values[], int weights[], int n, int W) {
    int a[n+1][W+1]; // 0..n objetos y 0..W capacidad

    // Caso base: no tengo objetos
    for(int j = 0; j <= W; j++) a[0][j] = 0;

    // Caso recursivo, relleno la tabla
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if (weights[i - 1] > j){
                a[i][j] = a[i-1][j];
            } else {
                a[i][j] = MAX(a[i-1][j], values[i-1] + a[i - 1][j - weights[i-1]]);
            }
        }
    }   

    print_table(n + 1,W + 1,a);
    
    return a[n][W];
}
