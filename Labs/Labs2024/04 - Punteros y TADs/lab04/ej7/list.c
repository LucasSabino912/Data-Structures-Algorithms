#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

struct node {
    list_elem elem;
    list next;
};

/* Constructors */

// Crea una lista vacia
list empty_list(void){
    return NULL;
}

// Agrega el elemento e al comienzo de la lista
list addl(list l, list_elem e){
    list new = malloc(sizeof(struct node));
    if(new == NULL){
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }

    new->elem = e;
    new->next = l;

    return new;
}

/* Destroy */

// Libera memoria en caso de que sea necesario
list destroy_list(list l){
    list aux;
    while (l != NULL){
        aux = l;
        l = l->next;
        free(aux);
    }

    return NULL;
}

/* Operations */
// Devuelve true si es vacia
bool is_empty(list l){
    return l == NULL;
}

// Devuelve el primer elemento de la lista l (PRE: !is_empty(l))
list_elem head(list l){
    assert(!is_empty(l));
    return l->elem;
}

// Agrega un elemento al final de l (PRE: !is_empty(l))
list addr(list l, list_elem e){
    list p, q;
    q = malloc(sizeof(struct node));
    q->elem = e;
    q->next = NULL;
    if(is_empty(l)){
        return q;
    }
    p = l;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = q;
    
    return l;
}

list tail(list l){
    assert(!is_empty(l));
    list tail = l->next;
    free(l);
    return tail;
}

// Devuelve el tamaño de la lista
int list_length(list l){
    list p;
    unsigned int length = 0;
    p = l;
    while(p != NULL){
        p = p->next;
        length++;
    }
    return length;
}

// Pone l2 al final de l
list concat(list l, list l2){
    list aux;
    aux = l;
    if(!is_empty(l)){
        return l2;
    }
    while (aux->next != NULL){
        aux = aux->next;
    }
    aux->next = l2;
    return l;
}

// Devuelve el n-esimo elemento
list_elem index(list l, unsigned int n){
    unsigned int i = 0;
    while (i < n){
        l = l->next;
        i++;
    }
    return l->elem;
}

// Deja en l los primeros n elementos 
list take(list l, unsigned int n){
    unsigned int i = 0;
    while(i < n){
        l = l->next;
        i++;
    }
    l->next = destroy_list(l->next);
    return l;
}

// Elimina los primeros n elementos 
list drop(list l, unsigned int n){
    unsigned int i = 0;
    list aux;
    while(i < n){
        aux = l;
        l = l->next;
        free(aux);
        i++;
    }
    return l;
}

// Copia todos los elementos de l en otra lista
list copy_list(list l, list lc){
        while (l != NULL){
        lc = addr(lc, l->elem);
        l = l->next;
    }
    
    return lc;
}
