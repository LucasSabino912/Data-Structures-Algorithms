#include <stdlib.h>
#include <stdbool.h>

#include <assert.h>

#include "card.h"

// Nuestra estructura carta es una tupla con numero y palo 
struct s_card {
    cardnum_t num;   // Tipo cardnum_t  (se encuentra definido en card.h)
    cardsuit_t suit; // Tipo cardsuit_t (se encuentra definido en card.h)
};

bool invrep(card c) {
    bool valid=c!=NULL &&
               ace <= c->num && c->num <= king &&
               (c->suit==spades ||
                c->suit==hearts ||
                c->suit==diamonds ||
                c->suit==clubs);
    return valid;
}

card card_create(cardnum_t num, cardsuit_t suit) {
    // card c = NULL; ESTAS QUERIENDO ACCEDER A UN PUNTERO NULO!!
    card c = malloc(sizeof(*c));

    if(c == NULL){
        return NULL; // Manejo de error si malloc falla
    }

    c->num = num;
    c->suit = suit;

    assert(invrep(c));
    return c;
}

card card_destroy(card c) {

    c = NULL;

    assert(c==NULL);
    return c;
}

cardcolor_t card_color(card c) {
    assert(invrep(c));
    return c->suit==hearts || c->suit==diamonds ? red: black;
}

cardnum_t card_number(card c) {
    assert(invrep(c));
    return c->num;
}

cardsuit_t card_suit(card c) {
    assert(invrep(c));
    return c->suit;
}

bool card_equals(card c1, card c2) {
    assert(invrep(c1) && invrep(c2));
    return c1->num == c2->num && c1->suit==c2->suit;

}

