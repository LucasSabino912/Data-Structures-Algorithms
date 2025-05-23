#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pair.h"

struct s_pair_t {
    int values[2];
};

// Creates a new pair with components (x, y)
pair_t pair_new(int x, int y){
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;

    return p;
}

// Returns the first component of p
int pair_first(pair_t p){
    return p.values[0];
}

// Returns the second component of p
int pair_second(pair_t p){
    return p.values[1];
}

// Return a NEW pair with the components of p reversed
pair_t pair_swapped(pair_t p){
    pair_t new_p;
    new_p.values[0] = p.values[1];
    new_p.values[1] = p.values[0];

    return new_p;
}

// Free memory if its necesary
pair_t pair_destroy(pair_t p){
    p.values[0] = 0;
    p.values[1] = 1;

    return p;
}
