#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



void array_dump(int a[], size_t length) {
    fprintf(stdout, "length: %lu\n", length);
    fprintf(stdout, "[ ");
    for (size_t i = 0u; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, ", ");
        }
    }
    fprintf(stdout, "]\n");
}


int *array_from_file(const char *filepath, size_t *length) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid array size.\n");
        exit(EXIT_FAILURE);
    }

    // Reservar memoria para el arreglo
    int *array = malloc(size * sizeof(int));
    if (array == NULL && size > 0) {
        fprintf(stderr, "Not enough memory.\n");
        exit(EXIT_FAILURE);
    }

    // Guardar el tamaño real del arreglo en *length
    *length = size;

    // Leer los elementos del archivo
    while (i < size) {
        res = fscanf(file, " %d ", &(array[i]));
        if (res != 1) {
            fprintf(stderr, "Invalid array element at index %u.\n", i);
            free(array);  // evitar memory leak si falla
            exit(EXIT_FAILURE);
        }
        ++i;
    }

    fclose(file);
    return array;
}


