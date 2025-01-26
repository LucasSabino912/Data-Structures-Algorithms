#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

/* List as a pointer to structs to guarantee encapsulation */
typedef struct node * list;
typedef int list_elem;

/* Constructors */

// Crea una lista vacia
list empty_list(void);

// Agrega el elemento e al comienzo de la lista
list addl(list l, list_elem e);

/* Destroy */

// Libera memoria en caso de que sea necesario
list destroy_list(list l);

/* Operations */
// Devuelve true si es vacia
bool is_empty(list l);

// Devuelve el primer elemento de la lista l (PRE: !is_empty(l))
list_elem head(list l);

// Elimina el primer elemento de l (PRE: !is_empty(l))
list tail(list l);

// Agrega un elemento al final de l (PRE: !is_empty(l))
list addr(list l, list_elem e);

// Devuelve el tamaño de la lista
int list_length(list l);

// Pone l2 al final de l
list concat(list l, list l2);

// Devuelve el n-esimo elemento
list_elem index(list l, unsigned int n);

// Deja en l los primeros n elementos 
list take(list l, unsigned int n);

// Elimina los primeros n elementos 
list drop(list l, unsigned int n);

// Copia todos los elementos de l en otra lista
list copy_list(list l, list lc);

#endif