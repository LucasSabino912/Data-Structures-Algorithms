#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 10

int main() {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

struct testcase tests[N_TESTCASES_CIMA] = {
    { {8}, 1, 8 },                          // Caso 1: Un solo elemento
    { {1, 3, 5, 4, 2}, 5, 5 },              // Caso 2: Cima en el medio
    { {1, 2, 3, 4, 5, 0}, 6, 5 },           // Caso 3: Cima casi al final
    { {1, 5, 3}, 3, 5 },                    // Caso 4: Cima en el centro
    { {0, 1, 3, 7, 6, 2}, 6, 7 },           // Caso 5: Cima en el medio con más elementos
    { {1, 2, 3, 2, 1}, 5, 3 },              // Caso 6: Simétrico con cima clara en el medio
    { {5, 9, 14, 13, 10, 8}, 6, 14 },        // Caso 7: Valores grandes con caída pronunciada
    { {1, 4, 7, 9, 6, 3, 0}, 7, 9 },        // Caso 8: Arreglo más largo
    { {10, 15, 20, 18, 13, 7, 1}, 7, 20 },   // Caso 9: Pico más pronunciado
    { {3, 6, 9, 12, 15, 11, 5}, 7, 15 }      // Caso 10: Cima más tardía
};

    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
