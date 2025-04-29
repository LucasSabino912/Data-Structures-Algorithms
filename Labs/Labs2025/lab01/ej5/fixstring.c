#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


// Calculo el largo de la cadena
unsigned int fstring_length(fixstring s) {
    unsigned int i = 0;
    while(s[i] != '\0'){
        i++;
    }

    return i;
}

// Chequeo si dos strings son iguales
bool fstring_eq(fixstring s1, fixstring s2) {
    bool eq = true;
    unsigned int i = 0, lengths1 = fstring_length(s1), lengths2 = fstring_length(s2);

    if(lengths1 == lengths2){
        while(s1[i] != '\0' && s1[i] == s2[i]){
            i++;
        }
        if(i != lengths1){
            eq = false;
        }
    } else {
        eq = false;
    }

    return eq;
}

// Chequeo si s1 es menor a s2 usando orden alfabetico
bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool less_eq = true;
    unsigned int i = 0;

    if(fstring_eq(s1, s2) == false){
        while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
            i++;
        }
        if(s1[i] > s2[i]){
            less_eq = false;
        }
    }

    return less_eq;
}


void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fixstring_set(aux, s1);
    fixstring_set(s1, s2);
    fixstring_set(s2, aux);
}


