#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};

list empty(){
    list l = malloc(sizeof(*l));
    l->size = 0;

    return l;
}

// Adds element `e` to the left of list `l`.
list addl(elem e, list l) {
    assert(l->size < MAX_LENGTH); // verificar espacio

    // mover los elementos una posición a la derecha
    for (int i = l->size; i > 0; i--) {
        l->elems[i] = l->elems[i - 1];
    }

    l->elems[0] = e;
    l->size++;
    return l;
}

//
// Operations
//

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l){
    return l->size == 0;
}

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l){
    assert(!is_empty(l));
    return l->elems[0];
}

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l){
    assert(!is_empty(l));
    l->size--;
    return l;
}

/**
 * @brief  Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e){
    l->size++;
    l->elems[l->size - 1] = e;

    return l;
}

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l){
    return l->size;
}

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0){
    int i = l->size;
    l->size = l->size + l0->size;
    while(i < l->size){
        l->elems[i] = l0->elems[i];
    }

    return l;
}

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n){
    return l->elems[n];
}

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n){
    l->size = l->size - n;
    return l;
}

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n){
    int i = 0;
    while(i <= n || n < l->size){
        l->elems[i] = l->elems[n];
        i++;
        n++;  
    }

    return l;
}

/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l){
    list copy = malloc(sizeof(*copy));
    int i = 0;
    while(i < l->size){
        copy->elems[i] = l->elems[i];
        i++;
    }

    return copy;
}

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l){
    free(l);
}
