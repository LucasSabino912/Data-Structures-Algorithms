#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

struct node {
    data elem;
    list next;
};

list empty_list(void){
    return NULL;
}

list addl(list l, data e){
    list new = malloc(sizeof(struct node));
    if(new == NULL){
        exit(EXIT_FAILURE);
    }
    new->elem = e;
    new->next = l;
    return new;
}

bool is_empty(list l){
    return l == NULL;
}

data head(list l){
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l){
    assert(!is_empty(l));
    return l->next;
}

unsigned int list_length(list l){
    unsigned int i = 0;
    while (l != NULL) {
        i++;
        l = l->next;
    }
    return i;
}

list addr(list l, data e){
    list new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        exit(EXIT_FAILURE);
    }
    new_node->elem = e;
    new_node->next = NULL;

    if (is_empty(l)) {
        return new_node;
    }

    list p = l;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = new_node;
    return l;
}

list destroy_list(list l){
    list tmp;
    while (l != NULL) {
        tmp = l;
        l = l->next;
        free(tmp);
    }
    return NULL;
}

