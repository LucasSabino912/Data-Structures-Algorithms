#include <stdbool.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

// Esta funcion devuelve el tamaño del arreglo leido en el archivo
unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *file = fopen(filepath, "r"); // Abro el archivo en modo lectura

    // Chequeo que se haya abierto de forma correcta
    if(file == NULL){
        exit(EXIT_FAILURE);
    }

    // Ahora obtengo los datos del array
    // Primero obtengo el tamaño del array
    unsigned int size;
    fscanf(file, "%u", &size);

    // Chequeo que el tamaño supere el tamaño maximo
    if(size > max_size){
        exit(EXIT_FAILURE);
    }

    // Se leen 'size' caracteres del archivo
    // Se almacenan en ls posiciones '0' hasta 'size - 1'
    for (unsigned int i = 0; i < size; i++){
        fscanf(file, "%d", &array[i]);
    }
    
    // Cierro el archivo y devuelvo el tamaño
    fclose(file);
    return size;
     
}

// Esta funcion imprime los datos del input como  un arreglo
void array_dump(int a[], unsigned int length) {
    
    printf("[%d", a[0]);

    for (unsigned int i = 1u; i < length; i++) {
        printf(", %d", a[i]);
    }

    printf("]\n");
}

bool is_sorted(int a[], unsigned int length){
    for (unsigned int i = 1; i < length; i++){
        if(a[i] < a[i - 1]){
            return false;
        }
    }
    return true;
}

void array_swap(int a[], unsigned int i, unsigned int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}