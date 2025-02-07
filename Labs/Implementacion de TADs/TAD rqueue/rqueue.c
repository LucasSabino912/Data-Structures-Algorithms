#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "rqueue.h"
#include "assert.h"

struct _node_t {
    // link[0] sig nodo de la izq
    // link[1] sig nodo de la der
    struct _node_t * links[2]; 
    elem_t value; // valor que se aloja en el
};

typedef struct _node_t * node_t;
typedef int orientation_t;

struct _rqueue_t {
    node_t extreme[2]; // uno apunta al primer elemento y otro al ultimo
    orientation_t orientation; // {0,1} indica si se lee de izq a der, o al reves
};

static orientation_t current(rqueue_t q) {
    return q->orientation;
}

static orientation_t inverse(rqueue_t q) {
    return 1 - q->orientation;
}

rqueue_t rqueue_empty() {
    rqueue_t q = malloc(sizeof(*q));
    
    if (!q) return NULL; // Manejo de error en caso de fallo en malloc

    q->extreme[0] = NULL; // Primer nodo vacio
    q->extreme[1] = NULL; // Segundo nodo vacio
    q->orientation = 0; // Orientacion predeterminada

    return q;
}

// extreme[0] = extreme[1] = null
bool rqueue_is_empty(rqueue_t q) {
    return (q == NULL || q->extreme[0] == NULL && q->extreme[1] == NULL);
}

static node_t create_node(elem_t e) {
    node_t z = malloc(sizeof(*z));

    if (!z) return NULL; // Manejo de errores

    z->value = e; // Inicializo el nodo con el valor e
    z->links[0] = NULL;
    z->links[1] = NULL;

    return z;
}


/*
rqueue_t q = rqueue_empty();
q = rqueue_enqueue(q, 3);
q = rqueue_enqueue(q, 7);
q = rqueue_enqueue(q, 9);
q = rqueue_enqueue(q, 12);

extreme[0] -> 3 -> 7 -> 9 -> 12 <- extreme[1]   */
rqueue_t rqueue_enqueue(rqueue_t q, elem_t e) {
    // Declaracion de variables auxiliares
    node_t new_node = NULL; // Nodo a insertar
    node_t aux = NULL; // Nodo auxiliar para manejar enlaces
    orientation_t prev; // Orientacion del nodo final, donde se insertara
    orientation_t next; // Direccion en la que se enlaza el nuevo nodo
    orientation_t lst; 

    assert(q != NULL); // Manejo de errores

    // Creo el nuevo nodo con valor e 
    new_node = create_node(e);

    // Si la cola esta vacia, el nuevo nodo sera el unico en la estructura
    if(rqueue_is_empty(q)) {
        q->extreme[current(q)] = new_node;
        q->extreme[inverse(q)] = new_node;
    }
    else {
        // Determinamos las orientaciones
        prev = inverse(q); // 'prev' indica el extremo donde agregaremos el nodo (último actual)
        next = current(q); // 'next' indica la direccion del enlace en la estructura

        aux = q->extreme[prev]; // Obtenemos el nodo actual que esta en el extremo

        // Conecto el ultimo nodo con el nuevo
        aux->links[next] = new_node; // El ultimo nodo ahora apunta al nuevo

        // Conecto el nuevo nodo con el anterior en la otra direccion  
        new_node->links[prev] = aux; // El nuvo nodo apunta al ulitmo nodo en direccion prev

        // Actualizo el extremo para reflejar que ahora el nuevo nodo es el ultimo
        q->extreme[prev] = new_node;   
    }
    return q;
}

elem_t rqueue_fst(rqueue_t q) {
    assert(q != NULL);
    assert(!rqueue_is_empty(q));
    return q->extreme[current(q)]->value;
}

void rqueue_dequeue(rqueue_t q) {
    // Aseguramos que la cola no sea NULL
    assert(q != NULL);
    // Aseguramos que la cola no esté vacía antes de eliminar
    assert(!rqueue_is_empty(q));

    // `fst` almacena el extremo desde donde eliminaremos (frente de la cola)
    orientation_t fst = current(q);
    // `next` almacena la dirección inversa (hacia dónde están enlazados los nodos)
    orientation_t next = inverse(q);

    // `z` apunta al nodo que vamos a eliminar (el primero de la cola)
    node_t z = q->extreme[fst];

    // Actualizamos el extremo para que apunte al siguiente nodo en la dirección `next`
    q->extreme[fst] = z->links[next];

    // Si el nuevo primer nodo no es NULL, rompemos el enlace con el nodo eliminado
    if (q->extreme[fst] != NULL) {
        // Eliminamos el enlace del nuevo primer nodo con el nodo eliminado
        q->extreme[fst]->links[fst] = NULL;
    } else {
        // Si la cola quedó vacía, aseguramos que ambos extremos sean NULL
        q->extreme[next] = NULL;
    }

    // Liberamos la memoria del nodo eliminado
    free(z);
}

void rqueue_revert(rqueue_t q) {
    assert(q != NULL);
    node_t tmp = q->extreme[0];
    q->extreme[0] = q->extreme[1];
    q->extreme[1] = tmp;
}

rqueue_t rqueue_destroy(rqueue_t q) {
    if (!q) return NULL;
    while(!rqueue_is_empty(q)){
        rqueue_dequeue(q);
    }
    free(q);
    return NULL;
}

void rqueue_dump(rqueue_t q) {
    orientation_t next;
    orientation_t fst;
    node_t aux = NULL;
    elem_t elem;
    assert(q != NULL);
    next = inverse(q);
    fst  = current(q);
    aux = q->extreme[fst];
    printf("\n Queue:");
    while(aux != NULL) {
        elem = aux->value;
        printf("%d ",elem);
        aux = aux->links[next];
    }
    printf("\n");
}
