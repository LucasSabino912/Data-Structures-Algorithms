#include <stdio.h>
#include <stdbool.h>
#include "auto.h"

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int automoviles(int n, int t1[], int t2[], int a1[], int a2[]) {
    int dp[n + 1][2]; // dp[i][0] para línea 1, dp[i][1] para línea 2

    // Caso base: primera estación
    dp[0][0] = a1[0];
    dp[0][1] = a2[0];

    for (int i = 1; i <= n; i++) {
        // Costo mínimo para llegar a la estación i por la línea 1
        dp[i][0] = MIN(
            dp[i - 1][0] + a1[i],            // seguir en línea 1
            dp[i - 1][1] + t2[i - 1] + a1[i] // cambiar desde línea 2
        );

        // Costo mínimo para llegar a la estación i por la línea 2
        dp[i][1] = MIN(
            dp[i - 1][1] + a2[i],            // seguir en línea 2
            dp[i - 1][0] + t1[i - 1] + a2[i] // cambiar desde línea 1
        );
    }

    return MIN(dp[n][0], dp[n][1]);
}