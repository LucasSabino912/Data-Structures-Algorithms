#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

// Creates a new pair with components (x, y)
pair_t pair_new(int x, int y){
    pair_t pair;
    pair.fst = x;
    pair.snd = y;

    return pair;
}

// Returns the first component of p
int pair_first(pair_t p){
    return p.fst;
}

// Returns the second component of p
int pair_second(pair_t p){
    return p.snd;
}

// Return a NEW pair with the components of p reversed
pair_t pair_swapped(pair_t p){
    pair_t swapped;
    swapped.fst = p.snd;
    swapped.snd = p.fst;

    return swapped;
}

// Free memory if its necesary
pair_t pair_destroy(pair_t p){
    return p;
}