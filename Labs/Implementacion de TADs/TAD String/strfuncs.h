#ifndef _STRFUNCS_H_
#define _STRFUNCS_H

#include <stdbool.h>

// Calcula la longitud de la cadena apuntada por str
size_t string_length(const char *str);

// Devuelve una nueva cadena en memoria dinamica que se obtiene tomando los caracteres
// de str que son distintos del caracter c
char *string_filter(const char *str, char c);

// Indicia si str es simetrico 
bool string_is_symmetric(const char *str);

#endif