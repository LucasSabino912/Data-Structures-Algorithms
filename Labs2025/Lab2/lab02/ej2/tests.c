#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();
    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[] = {
        { {1}, 1, false },
        { {1, 2}, 2, false },
        { {1, 2, 3, 2, 1}, 5, true },        // caso con cima
        { {1, 3, 5, 7, 4, 2}, 6, true },     // otra cima
        { {1, 2, 3, 4, 5}, 5, false },       // solo creciente
        { {5, 4, 3, 2, 1}, 5, false },       // solo decreciente
        { {1, 3, 3, 2}, 4, false },          // no estrictamente creciente
        { {1, 2, 3, 2, 2}, 5, false },       // no estrictamente decreciente
        { {1, 2, 1}, 3, true },
        { {5, 10, 20, 15, 10, 5}, 6, true }
    };

    int n_tests = sizeof(tests) / sizeof(tests[0]);
    printf("TESTING tiene_cima\n");

    for (int i = 0; i < n_tests; i++) {
        bool result = tiene_cima(tests[i].a, tests[i].length);
        printf("Test case %i: ", i + 1);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED (got %d, expected %d)\n", result, tests[i].result);
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[] = {
        { {1, 2, 3, 2, 1}, 5, 2 },
        { {1, 3, 5, 7, 4, 2}, 6, 3 },
        { {1, 2, 1}, 3, 1 },
        { {5, 10, 20, 15, 10, 5}, 6, 2 },
        { {1, 4, 3, 2}, 4, 1 },
        { {0, 1, 2, 3, 4, 3, 2}, 7, 4 },
        { {2, 4, 6, 5, 3}, 5, 2 },
        { {3, 6, 9, 8, 4}, 5, 2 },
        { {7, 8, 9, 8, 6}, 5, 2 },
        { {1, 100, 2}, 3, 1 }
    };

    int n_tests = sizeof(tests) / sizeof(tests[0]);
    printf("TESTING cima\n");

    for (int i = 0; i < n_tests; i++) {
        int result = cima(tests[i].a, tests[i].length);
        printf("Test case %i: ", i + 1);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED (got %d, expected %d)\n", result, tests[i].result);
        }
    }
}
