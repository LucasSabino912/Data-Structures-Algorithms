#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

// Definición de nodo de lista enlazada
struct _list {
    elem elem;
    list next;
};

// Crea una nueva lista vacía (es simplemente NULL)
list empty(void){
    return NULL;
}

// Verifica si la lista está vacía
bool is_empty(list l){
    return l == NULL;
}

// Agrega un elemento al comienzo de la lista
list addl(elem e, list l){
    list node = malloc(sizeof(*node));
    assert(node != NULL);
    node->elem = e;
    node->next = l;
    return node;
}

// Agrega un elemento al final de la lista
list addr(list l, elem e){
    list node = malloc(sizeof(*node));
    assert(node != NULL);
    node->elem = e;
    node->next = NULL;

    if (l == NULL) {
        // Si la lista estaba vacía, el nuevo nodo es el único
        return node;
    }

    list current = l; // Current apunta a l
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;

    return l;
}

// Devuelve el primer elemento de la lista
// PRE: !is_empty(l)
elem head(list l){
    assert(l != NULL);
    return l->elem;
}

// Elimina el primer nodo de la lista y devuelve el resto
// PRE: !is_empty(l)
list tail(list l){
    assert(l != NULL);
    list next = l->next;
    free(l);
    return next;
}

// Devuelve la longitud de la lista
int length(list l){
    int length = 0;
    while (l != NULL) {
        length++;
        l = l->next;
    }
    return length;
}

// Concatena l2 al final de l1 (no copia los nodos, solo los conecta)
list concat(list l1, list l2){
    if (l1 == NULL) {
        return l2;
    }

    list head = l1;
    while (l1->next != NULL) {
        l1 = l1->next;
    }
    l1->next = l2;
    return head;
}

// Devuelve el n-ésimo elemento (comenzando en 0)
// PRE: n < length(l)
elem index(list l, int n){
    int i = 0;
    while (l != NULL && i < n) {
        l = l->next;
        i++;
    }
    assert(l != NULL);  // n debe ser válido
    return l->elem;
}

// Deja solo los primeros n elementos, liberando el resto
list take(list l, int n){
    if (n == 0) {
        destroy_list(l);
        return NULL;
    }

    list head = l;
    int i = 1;
    while (l != NULL && i < n) {
        l = l->next;
        i++;
    }

    if (l != NULL) {
        list to_free = l->next;
        l->next = NULL;

        destroy_list(to_free);  // Libera el resto
    }

    return head;
}

// Elimina los primeros n nodos de la lista y devuelve el resto
list drop(list l, int n){
    int i = 0;
    while (l != NULL && i < n) {
        list tmp = l;
        l = l->next;
        free(tmp);
        i++;
    }
    return l;
}

// Retorna una copia independiente de la lista
list copy_list(list l1){
    if (l1 == NULL) return NULL;

    list copy = malloc(sizeof(*copy));
    assert(copy != NULL);
    copy->elem = l1->elem;
    copy->next = NULL;

    list curr_copy = copy;
    l1 = l1->next;

    while (l1 != NULL) {
        curr_copy->next = malloc(sizeof(*curr_copy));
        assert(curr_copy->next != NULL);
        curr_copy = curr_copy->next;
        curr_copy->elem = l1->elem;
        curr_copy->next = NULL;
        l1 = l1->next;
    }

    return copy;
}

// Libera toda la memoria ocupada por la lista
void destroy_list(list l) {
    while (l != NULL) {
        list tmp = l;
        l = l->next;
        free(tmp);
    }
}
