#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "strfuncs.h"

// Calcula la longitud de la cadena apuntada por str
size_t string_length(const char *str) {
    size_t i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}


// Devuelve una nueva cadena en memoria dinamica que se ibtiene tomando los carcteres de str distintos a c
char *string_filter(const char *str, char c) {
    size_t len = string_length(str);
    char *str_cpy = malloc(len + 1);  // Reservo como si no filtrara nada (+1 para el '\0')

    if (str_cpy == NULL) {
        return NULL;  // Por si malloc falla
    }

    size_t i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != c) {
            str_cpy[j] = str[i];
            j++;
        }
        i++;
    }

    str_cpy[j] = '\0'; // terminamos la cadena nueva

    return str_cpy;
}
// Indica si la cadena apuntada por str es simetrica
bool string_is_symmetric(const char *str){
    bool res = true;
    size_t i = 0, j = string_length(str);
    if (j > 0) {
        j--;  // índice del último carácter válido
    }

    while (i < j && res){
        if(str[i] != str[j]){
            res = false;
        }
        i++;
        j--;
    }

    return res;
}
