#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 100

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered = NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH - 1);
    
    if (fgets(user_input, MAX_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error leyendo la entrada\n");
        return EXIT_FAILURE;
    }

    // Eliminar salto de línea
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    filtered = strdup(user_input);
    if (filtered == NULL) {
        fprintf(stderr, "Error reservando memoria\n");
        return EXIT_FAILURE;
    }

    for (unsigned int i = 0; i < SIZEOF_ARRAY(ignore_chars); i++) {
        char *temp = string_filter(filtered, ignore_chars[i]);
        free(filtered);
        filtered = temp;

        if (filtered == NULL) {
            fprintf(stderr, "Error reservando memoria durante filtrado\n");
            return EXIT_FAILURE;
        }
    }

    printf("El texto:\n\n\"%s\"\n\n%s un palíndromo.\n\n", user_input,
           string_is_symmetric(filtered) ? "Es" : "NO es");

    free(filtered);

    return EXIT_SUCCESS;
}
