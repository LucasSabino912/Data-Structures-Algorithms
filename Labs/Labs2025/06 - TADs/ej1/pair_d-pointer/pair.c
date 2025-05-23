#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "pair.h"

struct s_pair_t {
    int fst;
    int snd;
};

// Creates a new pair with components (x, y)
pair_t pair_new(int x, int y){
    pair_t p = mastruct s_pair_t {
    int fst;
    int snd;
};lloc(sizeof(*p));
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
    pair_t new_p = malloc(sizeof(*new_p));
    new_p->fst = p->snd;
    new_p->snd = p->fst;

    return new_p;
}

// Free memory if its necesary
pair_t pair_destroy(pair_t p){
    free(p);
    p = NULL;
    return p;
}
