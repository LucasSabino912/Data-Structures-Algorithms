#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

// Creates a new pair with components (x, y)
pair_t pair_new(int x, int y){
    pair_t p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;

    return p;
}

// Returns the first component of p
int pair_first(pair_t p){
    return p->fst;
}

// Returns the first component of p
int pair_second(pair_t p){
    return p->snd;
}

// Return a NEW pair with the components of p reversed
pair_t pair_swapped(pair_t p){
    pair_t swapped = malloc(sizeof(struct s_pair_t));
    swapped->fst = p->snd;
    swapped->snd = p->fst;

    return swapped;
}

// Free memory if its necessary
pair_t pair_destroy(pair_t p){
    free(p);
    return NULL;
}
