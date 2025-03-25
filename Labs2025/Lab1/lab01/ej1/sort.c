#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    unsigned int j = length;
    while(j > 1 && a[j] < a[j-1]){
        swap(a, i, j);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
    }
}
