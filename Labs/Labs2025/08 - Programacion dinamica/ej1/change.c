#include <stdio.h>
#include <limits.h>
#include "change.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

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

/*
    int d[MAX_COINS];  // denominaciones
    int n;             // cantidad de denominaciones
    int k;             // monto a pagar
    int result;        // resultado esperado: cantidad mínima de monedas
*/

int change(int d[], int n, int k) {
    int a[n+1][k+1];

    for (int i = 0; i <= n; i++) a[i][0] = 0;        // Con 0 monto -> 0 monedas
    for (int j = 1; j <= k; j++) a[0][j] = INT_MAX;  // Sin monedas no puedo formar monto > 0

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j < d[i - 1] || a[i][j - d[i - 1]] == INT_MAX){
                a[i][j] = a[i-1][j];  // No uso moneda i
            } else {
                // Uso moneda i al menos una vez, por eso reviso a[i][j - d[i-1]]
                a[i][j] = MIN(a[i-1][j], 1 + a[i][j - d[i - 1]]);
            }
        }
    }

    print_table(n + 1, k + 1, a);  // Imprimir la tabla completa

    return a[n][k];
}