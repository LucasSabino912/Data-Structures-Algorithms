#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

// counter_is_init(c) should be true.
counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    if (c == NULL) {
        // Manejo del error o aborta el programa.
        return NULL;
    }
    c->count = 0;
    return c;
}

unsigned int counter_count(counter c){
    assert(c != NULL);
    return c->count;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    return c->count == 0;
}
// PRECONDITION: !counter_is_init(c)
void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count--;
}

counter counter_copy(counter c) {
    assert(c != NULL);
    counter copy = counter_init();
    if (copy == NULL) {
        return NULL;
    }
    copy->count = c->count;

    return copy;
}


void counter_destroy(counter c) {
    if (c != NULL) {
        free(c);
    }
}
