#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node * list;
typedef int data;

// Crea una lista vacia
list empty_list(void);

// Agrega un elemento al comienzo de la lista
list addl(list l, data e);

// Devuelve true si la lista es vacia
bool is_empty(list l);

// Devuelve el primer elemento de la lista l (PRE: !is_empty(l))
data head(list l);

// Elimina el primer elemento de la lista l (PRE: !is_empty(l))
list tail(list l);

// Agrega un elemento al final de la lista l (PRE: !is_empty(l))
list addr(list l, data e);

// Devuelve el tamaño de la lista l
unsigned int list_length(list l);

// Pone l2 al final de l
list concat(list l, list l2);

// Deja en l los primeros n elementos
list take(list l, unsigned int n);

// Devuelve el n-esimo elemento
data index(list l, unsigned int n);

// Elimina los primeros n elementos de l
list drop(list l, unsigned int n);

// Copia los elementos de l a una lista auxiliar
list copy_list(list l, list lc);

// Libera memoria en caso de que sea necesario
list destroy_list(list l);

#endif 