#include <limits.h>
#include <stdio.h>

#include "pan.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX_OBJECTS 10
#define N_TESTCASES 4

// Estructura para representar un caso de test
struct testcase {
    int n;                  // cantidad de productos
    int H;                  // cantidad total de harina disponible
    int importes[MAX_OBJECTS]; // ganancias por producto
    int harina[MAX_OBJECTS];   // harina que consume cada producto
    int result;             // resultado esperado
};

int main() {
    // Casos de prueba
    struct testcase tests[N_TESTCASES] = {
        // Caso 1: ejemplo clásico, elegir galletas + pan (3+4 = 7)
        {3, 5, {3, 4, 5}, {2, 3, 4}, 7},

        // Caso 2: solo entra uno de los productos
        {2, 2, {10, 20}, {2, 3}, 10},

        // Caso 3: capacidad exacta para tomar todo
        {3, 9, {4, 5, 6}, {3, 3, 3}, 15},

        // Caso 4: no se puede elegir ninguno (harina insuficiente)
        {2, 1, {100, 200}, {2, 3}, 0},
    };

    int result;

    printf("TESTING panaderia\n");

    for (int i = 0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i + 1);

        // Llamamos a la función panaderia
        result = panaderia(tests[i].n, tests[i].H, tests[i].importes, tests[i].harina);

        // Verificamos el resultado
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED: got %d, expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
