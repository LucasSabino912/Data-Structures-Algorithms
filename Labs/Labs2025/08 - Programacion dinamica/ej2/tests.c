#include <stdbool.h>
#include <stdio.h>
#include "knapsack.h"

#define MAX_OBJECTS 10
#define N_TESTCASES 4

int main() {
    // representación de un solo caso de test
    struct testcase {
        int values[MAX_OBJECTS];   // valores de los objetos
        int weights[MAX_OBJECTS];  // pesos de los objetos
        int n;                     // cantidad de objetos
        int W;                     // capacidad de la mochila
        int result;                // resultado esperado: máximo valor posible
    };

    // casos de test (uno por línea): { values, weights, n, W, result }
    struct testcase tests[N_TESTCASES] = {
        { {3, 2, 3, 2}, {8, 5, 7, 3}, 4, 16, 7 },  // Caso base que ya tenías

        // Caso 1: Capacidad justa para tomar el item más valioso
        { {10, 40, 30, 50}, {5, 4, 6, 3}, 4, 10, 90 },  
        // Elige items de valor 40 (peso 4) y 50 (peso 3) → total 90

        // Caso 2: No puede llevar nada (W=0)
        { {1, 2, 3}, {4, 5, 1}, 3, 0, 0 },  
        // Capacidad cero, resultado debe ser 0

        // Caso 3: Puede llevar todos los objetos
        { {1, 2, 3}, {1, 1, 1}, 3, 3, 6 },  
        // Todos caben: valor total 6
    };


    int result;

    printf("TESTING knapsack\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        // TEST! llamamos la función a knapsack
        result = knapsack(tests[i].values, tests[i].weights, tests[i].n, tests[i].W);

        // comparamos resultado obtenido con resultado esperado
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED: got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
