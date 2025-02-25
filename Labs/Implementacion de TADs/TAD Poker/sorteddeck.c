#include "sorteddeck.h"
#include "card.h"
#include "card_helpers.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <assert.h>

// sdeck es un puntero a la estructura s_deck
struct s_sdeck {
    struct s_node *first;    // nodo con primer carta 
    struct s_node *last_red; // nodo con ultima carta roja, las demas seran negras
    unsigned int size;       // tamaño del deck (PRE: qred + qblack)
    unsigned int qred;       // Cantidad de rojas
    unsigned int qblack;     // Cantidad de negras
};

// s_node es la estructura, node_t es el puntero a la estructura
struct s_node {
    card c;              // Carta del nodo
    cardcolor_t color;   // Color de la carta (accedo con card_color(c))
    struct s_node *next; // Proxima carta
};

typedef struct s_node * node_t;

static node_t create_node(card c) {
    node_t new_node = malloc(sizeof(*new_node)); // Alloqueamos con el puntero a lo que seria la estructura
    if(new_node == NULL){
        return NULL; // Manejo de errores
    }

    new_node->c = c; // Le damos el valor c del nodo nuestra carta ingresada
    new_node->color = card_color(c); // Ingresamos al color mediante la funcion ya definida en el TAD carta
    new_node->next = NULL; // Como esta incializado, nuestro siguiente nodo es null

    return new_node; 
}

static node_t destroy_node(node_t node) {
    if(node == NULL){
        return NULL;
    }

    free(node);

    return NULL;
}

/*
Condiciones de consistencia: 
 - Orden
 - Integridad de contadores
 - Puntero last_red
*/
static bool invrep(sdeck deck) {
    if (deck == NULL) {
        return false;
    }

    // Si el mazo está vacío, los contadores deben ser 0 y last_red debe ser NULL
    if (deck->size == 0) {
        return (deck->qred == 0 && deck->qblack == 0 && deck->last_red == NULL);
    }

    unsigned int count_red = 0;
    unsigned int count_black = 0;
    node_t current = deck->first;
    node_t last_red = NULL;
    bool found_black = false;

    while (current != NULL) {
        // Verifico el color de la carta
        if (current->color == red) {
            count_red++;
            last_red = current;
            if (found_black) {
                return false; // Si encontré negro antes, la estructura está mal
            }
        } else if (current->color == black) {
            count_black++;
            found_black = true;
        } else {
            return false; // Color inválido
        }

        current = current->next;
    }

    // Verifico que los contadores sean correctos
    if (deck->qblack != count_black || deck->qred != count_red) {
        return false;
    }

    // Verifico que last_red realmente apunte a la última roja (si hay rojas)
    if (deck->qred > 0 && deck->last_red != last_red) {
        return false;
    }

    // Verifico que el tamaño total sea correcto
    return (deck->size == (count_red + count_black));
}



sdeck sorteddeck_create(void) {
    sdeck deck = malloc(sizeof(*deck));
    
    if(deck == NULL){
        return NULL; // Manejo de errores
    }
    // SIEMPRE incializar los campos
    deck->first = NULL;
    deck->last_red = NULL;
    deck->size = 0;
    deck->qblack = 0;
    deck->qred = 0;

    return deck;
 }

sdeck sorteddeck_destroy(sdeck deck) {
    if(deck == NULL){
        return NULL;
    }

    node_t current = deck->first;
    node_t next_node;

    while (current != NULL){
        next_node = current->next;  // Guardo la referencia al siguiente nodo
        destroy_node(current);      // Libero el nodo actual (ya devuelve NULL, pero no lo usamos)
        current = next_node;        // Avanzo en la lista
    }

    free(deck);
    return NULL;
}


/*
    Esta funcion agrega una carta:
     - Si es negra va al final
     - Si es roja va despues de last_red, ya que es mas eficiente que mover todo
*/
sdeck sorteddeck_add(sdeck deck, card c) {
    assert(invrep(deck));
    node_t new_node = create_node(c);
    if(new_node == NULL){
        return deck; // Error al allocar memoria
    }

    if(card_color(c) == red){
        // Si no hay cartas en el mazo o no hay rojas
        if(deck->last_red == NULL){
            // Inserto al inicio
            // El nuevo nodo ahora apunta al que antes era el primero
            new_node->next = deck->first; // Lo meto al next para no perder la referencia a mi nodo (memory leak)
            // Ahora el nuevo nodo es la primera carta del mazo
            deck->first = new_node;
        } else {
            new_node->next = deck->last_red->next;
            deck->last_red->next = new_node;
        }
        deck->last_red = new_node; // Actualizo el ultimo rojo
        deck->qred++;
    } else {
        // Inserto al final (caso carta negra)
        if(deck->first == NULL){
            deck->first = new_node;
        } else {
            node_t current = deck->first;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = new_node;
        }
        deck->qblack++;
    }

    deck->size++;

    assert(invrep(deck) && !sorteddeck_is_empty(deck));
    return deck;
}

sdeck sorteddeck_remove(sdeck deck, card c) {
    assert(invrep(deck));
    
    if(deck->first == NULL){
        return deck; // Si el mazo esya vacio, no hay nada que hacer
    }

    node_t prev = NULL;
    node_t current = deck->first;

    // Busco la carta 'c' en el mazo
    while(current != NULL && current->c != c){
        prev = current;
        current = current->next; 
    }

    // Si no se encontrola carta, no se hacen cambios
    if(current == NULL){
        return deck;
    }

    // Si la carta es la primera en el mazo
    if(prev == NULL){
        deck->first = current->next;
    } else
    {
        prev->next = current->next;
    }
    
    // Actualizo last red si elimine la ultima carta roja
    if(current->color == red){
        deck->qred--;
        if(deck->last_red == current){
            deck->last_red = prev; // Queda null si era la unica roja
        }
    } else {
        deck->qblack--;
    }

    deck->size--;

    current = destroy_node(current);

    assert(invrep(deck));
    return deck;
}

sdeck sorteddeck_popfirst(sdeck deck) {
    assert(invrep(deck));
    if(deck == NULL || deck->first == NULL){
        return deck; // No hago nada
    }

    node_t remove = deck->first; // Guardo la referencia al primer nodo
    deck->first = remove->next; // muevo al puntero first al proximo nodo 

    if(remove->color == red){
        deck->qred--;
        if(deck->last_red == remove){
            deck->last_red = NULL; // Si elimine la ultima carta roja
        }
    } else {
        deck->qblack--;
    }

    deck->size--;

    free(remove);

    return deck;
}

card sorteddeck_first(sdeck deck) {
    return deck->first->c;
}

unsigned int sorteddeck_size(sdeck deck) {
    return deck->size;
}

unsigned int sorteddeck_redcount(sdeck deck) {
    return deck->qred;
}

unsigned int sorteddeck_blackcount(sdeck deck) {
    return deck->qblack;
}

bool sorteddeck_is_empty(sdeck deck) {
    return deck->size == 0;
    // return deck->first == NULL es otra opcion
}


/*
    1° creo un arreglo dinamico
    2° recorro la lista enlazada
    3° almaceno las cartas en el arreglo
    4° devuelvo el arreglo
*/
card* sorteddeck_to_array(sdeck deck) {
    assert(invrep(deck));
    if(deck->size == 0){
        return NULL;
    }

    // Asigno memoria para el arreglo
    card* array = malloc(deck->size * sizeof(card));
    if(array == NULL){
        return NULL;
    }

    // Ahora recorro el deck
    node_t current = deck->first;
    unsigned int i = 0;

    while(current != NULL){
        array[i] = current->c; // Almaceno la carta en el array
        current = current->next;
        i++;
    }

    return array;
}

void sorteddeck_dump(sdeck deck) {
    assert(invrep(deck));
    node_t node = deck->first;
    if (node != NULL) {
        card_dump(node->c);
        while (node->next != NULL) {
            printf(" -> ");
            node = node->next;
            card_dump(node->c);
        }
        printf("\n");
    } else {
        printf("<>\n");
    }
}

