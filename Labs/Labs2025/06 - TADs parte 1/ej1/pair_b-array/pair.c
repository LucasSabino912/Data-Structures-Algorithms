#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pair.h"


pair_t pair_new(int x, int y){
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;

    return p;
}

int pair_first(pair_t p){
    return p.values[0];
}

int pair_second(pair_t p){
    return p.values[1];
}

pair_t pair_swapped(pair_t p){
    pair_t aux;
    aux.values[0] = p.values[1];
    aux.values[1] = p.values[0];

    return aux;
}

pair_t pair_destroy(pair_t p){
    p.values[0] = 0;
    p.values[1] = 0;

    return p;
}
