#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"

// Intercambia dos caracteres del mismo fixstring (no se modifica fstring_swap que es para strings completos)
static void fstring_char_swap(fixstring s, unsigned int i, unsigned int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

// Partition adaptado para caracteres dentro de un fixstring
static unsigned int partition(fixstring s, unsigned int izq, unsigned int der) {
    unsigned int i = izq + 1;
    unsigned int j = der;
    unsigned int piv = izq;

    while (i <= j) {
        if (s[i] <= s[piv]) {
            i++;
        } else if (s[j] > s[piv]) {
            j--;
        } else {
            fstring_char_swap(s, i, j);
            i++;
            j--;
        }
    }

    fstring_char_swap(s, piv, j);
    return j;
}

// Versión recursiva del quicksort adaptada a fixstring
static void quick_sort_rec(fixstring s, unsigned int izq, unsigned int der) {
    if (izq < der) {
        unsigned int piv = partition(s, izq, der);
        if (piv > 0) {
            quick_sort_rec(s, izq, piv - 1);
        }
        quick_sort_rec(s, piv + 1, der);
    }
}

// Ordena los caracteres dentro de un fixstring de menor a mayor
void quick_sort(fixstring s) {
    unsigned int len = fstring_length(s);
    if (len > 1) {
        quick_sort_rec(s, 0, len - 1);
    }
}
