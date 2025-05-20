#ifndef _STRFUNCS_H
#define _STRFUNCS_H

#include <stdbool.h>
#include <stdio.h>

// Calcula la longitud de la cadena apuntada por str
size_t string_length(const char *str);

// evuelve una nueva cadena en memoria dinamica que se ibtiene tomando los carcteres de str distintos a c
char *string_filter(const char *str, char c);

// Indica si la cadena apuntada por str es simetricva
bool string_is_symmetric(const char *str);

#endif 