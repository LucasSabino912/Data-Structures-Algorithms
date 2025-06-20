#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

#include "change.h"

#define MAX_COINS 10
#define N_TESTCASES 4

int main() {
    // representación de un solo caso de test
    struct testcase {
        int d[MAX_COINS];  // denominaciones
        int n;             // cantidad de denominaciones
        int k;             // monto a pagar
        int result;        // resultado esperado: cantidad mínima de monedas
    };

    // casos de test (uno por línea): { d, n, k, result }
    struct testcase tests[N_TESTCASES] = {
        { {4, 2, 7}, 3, 16, 3 },   // 7 + 7 + 2 = 16 → 3 monedas
        { {1, 3, 4}, 3, 6, 2 },    // 3 + 3 = 6 → 2 monedas
        { {5, 10}, 2, 3, INT_MAX },// No se puede formar 3 → devuelve infinito
        { {1, 2, 5}, 3, 11, 3 },   // 5 + 5 + 1 = 11 → 3 monedas
    };


    int result;

    printf("TESTING change\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        // TEST! llamamos la función a change
        result = change(tests[i].d, tests[i].n, tests[i].k);

        // comparamos resultado obtenido con resultado esperado
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED: got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
