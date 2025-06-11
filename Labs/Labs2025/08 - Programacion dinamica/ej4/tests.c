#include <stdio.h>
#include <limits.h>
#include "auto.h"#include <stdio.h>
#include <limits.h>
#include "auto.h"

#define MAX_STATIONS 100
#define N_TESTCASES 5

// Estructura para representar un caso de test
struct testcase {
    int n;                     // cantidad de estaciones (0..n)
    int t1[MAX_STATIONS];      // tiempo de cambio de línea 1 a 2
    int t2[MAX_STATIONS];      // tiempo de cambio de línea 2 a 1
    int a1[MAX_STATIONS];      // tiempo en línea 1
    int a2[MAX_STATIONS];      // tiempo en línea 2
    int expected;              // costo mínimo esperado
};

int main() {
    struct testcase tests[N_TESTCASES] = {
        // Caso 1: solo una estación, elegir mínimo
        {0, {}, {}, {5}, {3}, 3},

        // Caso 2: dos estaciones, sin transferencias convenientes
        {1, {10}, {10}, {4, 5}, {6, 7}, 4 + 5},

        // Caso 3: transferencia desde línea 2 a línea 1 es mejor
        {1, {2}, {1}, {8, 5}, {3, 6}, 3 + 1 + 5}, // línea 2 → línea 1

        // Caso 4: siempre conviene quedarse en línea 2
        {2, {5, 5}, {5, 5}, {10, 10, 10}, {1, 1, 1}, 1 + 1 + 1},

        // Caso 5: combinación óptima implica cambiar de línea
        {2, {4, 2}, {2, 4}, {2, 5, 3}, {1, 100, 1}, 1 + 2 + 5 + 3}, // línea 2 → línea 1 en i=1
    };

    printf("TESTING automoviles\n");

    for (int i = 0; i < N_TESTCASES; i++) {
        printf("Test case %d: ", i + 1);

        int result = automoviles(
            tests[i].n,
            tests[i].t1,
            tests[i].t2,
            tests[i].a1,
            tests[i].a2,
        );

        if (result == tests[i].expected) {
            printf("OK\n");
        } else {
            printf("FAILED: got %d, expected %d\n", result, tests[i].expected);
        }
    }

    return 0;
}


#define MAX_STATIONS 100
#define N_TESTCASES 5

// Estructura para representar un caso de test
struct testcase {
    int n;                     // cantidad de estaciones (0..n)
    int t1[MAX_STATIONS];      // tiempo de cambio de línea 1 a 2
    int t2[MAX_STATIONS];      // tiempo de cambio de línea 2 a 1
    int a1[MAX_STATIONS];      // tiempo en línea 1
    int a2[MAX_STATIONS];      // tiempo en línea 2
    int expected;              // costo mínimo esperado
};

int main() {
    struct testcase tests[N_TESTCASES] = {
        // Caso 1: solo una estación, elegir mínimo
        {0, {}, {}, {5}, {3}, 3},

        // Caso 2: dos estaciones, sin transferencias convenientes
        {1, {10}, {10}, {4, 5}, {6, 7}, 4 + 5},

        // Caso 3: transferencia desde línea 2 a línea 1 es mejor
        {1, {2}, {1}, {8, 5}, {3, 6}, 3 + 1 + 5}, // línea 2 → línea 1

        // Caso 4: siempre conviene quedarse en línea 2
        {2, {5, 5}, {5, 5}, {10, 10, 10}, {1, 1, 1}, 1 + 1 + 1},

        // Caso 5: combinación óptima implica cambiar de línea
        {2, {4, 2}, {2, 4}, {2, 5, 3}, {1, 100, 1}, 1 + 2 + 5 + 3}, // línea 2 → línea 1 en i=1
    };

    printf("TESTING automoviles\n");

    for (int i = 0; i < N_TESTCASES; i++) {
        printf("Test case %d: ", i + 1);

        int result = automoviles(
            tests[i].n,
            tests[i].t1,
            tests[i].t2,
            tests[i].a1,
            tests[i].a2
        );

        if (result == tests[i].expected) {
            printf("OK\n");
        } else {
            printf("FAILED: got %d, expected %d\n", result, tests[i].expected);
        }
    }

    return 0;
}
