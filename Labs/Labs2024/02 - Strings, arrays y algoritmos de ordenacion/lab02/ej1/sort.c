#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


/* Aplico el algoritmo insert de siempre del insertion sort,
   con la diferencia que uso la funcion goes_before(), */
static void insert(int a[], unsigned int i) {
    while (i > 0 && goes_before(a[i], a[i-1])){
        swap(a, i-1, i);
        i--;
    }
    
}

/* El insertion sort de siempre con la unica diferencia que chequeo en cada iteracion
   si el algoritmo esta ordenado, esto hara que en el mejor de los casos el algoritmo
   termine antes  */

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a, length));
        insert(a, i);
    }
}
