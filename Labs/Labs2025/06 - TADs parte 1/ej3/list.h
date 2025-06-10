#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *list;
typedef int list_elem;

// Crea una nueva lista vacía
list empty_list(void);

// Agrega el elemento e al comienzo de la lista
list addl(list l, list_elem e);

// Chequea si una lista es vacía
bool is_empty(list l);

// Devuelve el primer elemento de la lista
// PRE: !is_empty(l)
list_elem head(list l);

// Elimina el primer elemento de la lista
// PRE: !is_empty(l)
list tail(list l);

// Agrega un elemento al final de la lista
list addr(list l, list_elem e);

// Devuelve la longitud de la lista
unsigned int length(list l);

// Agrega l2 al final de l1
list concat(list l1, list l2);

// Devuelve el n-ésimo elemento de la lista
list_elem index(list l, unsigned int n);

// Deja solo los primeros n elementos en l
list take(list l, unsigned int n);

// Elimina los primeros n elementos de l
list drop(list l, unsigned int n);

// Retorna una copia de la lista l1
list copy_list(list l1);

// Libera memoria en caso de que sea necesario
void destroy_list(list l);

#endif
