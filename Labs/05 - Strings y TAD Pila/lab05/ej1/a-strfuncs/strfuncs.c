#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Calcula la longitud de la cadena apuntada por str
size_t string_length(const char *str){
    unsigned int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

// Devuelve una nueva cadena en memoria dinamica que se obtiene tomando los caracteres
// de str que son distintos del caracter c
char *string_filter(const char *str, char c);

// Indicia si str es simetrico 
bool string_is_symmetric(const char *str);