/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return x->rank > y->rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static void swap(player_t a[], unsigned int x, unsigned int y){
    player_t tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

static void insert(player_t a[], unsigned int i) {
    while (i > 0 && goes_before(a[i], a[i-1])){
        swap(a, i-1, i);
        i--;
    }
    
}

// Ordenar por puesto en el ranking usando el insertion sort
void sort(player_t a[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++){
        assert(array_is_sorted(a, length));
        insert(a, i);
    }
    
}
