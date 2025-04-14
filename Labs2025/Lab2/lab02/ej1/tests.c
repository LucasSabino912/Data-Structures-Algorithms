#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

#define MAX_LENGTH 5
#define N_TESTCASES 10

/*
Casos de test: 
- Arreglo de un elememto (k = 0 obligatoriamente) 
- Arreglo de dos elementos ordenados, con k = 0
- Arreglo de dos elementos ordenados, con k = 1
- Arreglo de dos elementos desordenados, con k = 0
- Arreglo de dos elementos desordenados, con k = 1
- El arreglo del ejemlo {8, -2, 9, 0, 13} conn todos los k posibles
*/

struct testcase {
    int a[MAX_LENGTH];
    int length;
    int k;
    int result;
};

int main() {
    struct testcase tests[N_TESTCASES] = {
        // arreglo, largo, k, resultado esperado
        
        // Caso 1: Arreglo de un elemento
        { {8}, 1, 0, 8 },

        // Caso 2: Arreglo de dos elementos ordenados (k = 0)
        { {3, 8}, 2, 0, 3 },

        // Caso 3: arreglo de dos elementos ordenados (k = 1)
        { {7, 9}, 2, 1, 9 },

        // Caso 4: Arreglo de dos elemento desordenados (k = 0)
        { {2, 1}, 2, 0, 1 },

        // Caso 5: Arreglo de dos elmentos desordenados (k = 1)
        { {4, 2}, 2, 1, 4 },
        
        // Caso 6: El ejemplo con todos los k posibles
        { {8, -2, 9, 0, 13}, 5, 0, -2 },
        { {8, -2, 9, 0, 13}, 5, 1, 0  },
        { {8, -2, 9, 0, 13}, 5, 2, 8  },
        { {8, -2, 9, 0, 13}, 5, 3, 9  },
        { {8, -2, 9, 0, 13}, 5, 4, 13 },    
        
            
    };
    int result;

    printf("TESTING k_esimo\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = k_esimo(tests[i].a, tests[i].length, tests[i].k);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }
    }

    return 0;
}
