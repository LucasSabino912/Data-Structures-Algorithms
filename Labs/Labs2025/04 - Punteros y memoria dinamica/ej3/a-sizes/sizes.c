#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h> // para strcpy

#include "data.h"

void print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %u años\n"
           "ALTURA: %u cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {
    // Reservamos memoria dinámica
    data_t *messi = malloc(sizeof(data_t));
    if (messi == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria.\n");
        return EXIT_FAILURE;
    }

    // Asignamos valores
    strcpy(messi->name, "Leo Messi");
    messi->age = 36;
    messi->height = 169;

    // Mostramos los datos
    print_data(*messi);

    // Tamaños de miembros y estructura
    printf("name-size  : %u bytes\n", sizeof(messi->name));
    printf("age-size   : %u bytes\n", sizeof(messi->age));
    printf("height-size: %u bytes\n", sizeof(messi->height));
    printf("data_t-size: %u bytes\n\n", sizeof(*messi));

    // Direcciones de memoria de cada campo
    printf("Dirección de name  : %p\n", (void*)&(messi->name));
    printf("Dirección de age   : %p\n", (void*)&(messi->age));
    printf("Dirección de height: %p\n", (void*)&(messi->height));
    printf("Dirección de messi : %p\n", (void*)messi); // dirección base

    // Liberamos memoria
    free(messi);

    return EXIT_SUCCESS;
}
