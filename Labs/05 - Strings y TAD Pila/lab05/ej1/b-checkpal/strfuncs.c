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
char *string_filter(const char *str, char c){
    unsigned int i = 0, j = 0, strlen = string_length(str), filterlen = 0;
    // Calculo la longitud del stringg ya filtrado
    while (i < strlen){
        if (str[i] != c){
            filterlen++;
        }
        i++;
    }

    char * filtered = NULL;
    filtered = malloc(sizeof(char) * (filterlen + 1));
    if (filtered == NULL){
        return NULL;
    }

    filtered[filterlen] = '\0';

    i = 0;
    while(i < strlen){
        if(str[i] != c){
            filtered[j] = str[i];
            j++;
        }
        i++;
    }
    
    return filtered;
}

bool string_is_symmetric(const char *str){
    unsigned int i = 0;
    while(i <= string_length(str)/2){
        if(str[i] != str[string_length(str) -1 -i]){
            return false;    
        }
        i++;
    }
    return true;
}