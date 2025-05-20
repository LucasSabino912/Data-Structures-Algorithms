#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %u años\n"
           "ALTURA: %u cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    // Alocación dinámica de data_t
    data_t *messi = malloc(sizeof(data_t));
    if (messi == NULL) {
        fprintf(stderr, "Error al reservar memoria\n");
        return EXIT_FAILURE;
    }

    // Inicialización con strcpy
    strcpy(messi->name, "Leo Messi");
    messi->age = 36;
    messi->height = 169;

    // Mostrar datos
    print_data(*messi);

    // Mostrar tamaños
    printf("name-size  : %u bytes\n"
           "age-size   : %u bytes\n"
           "height-size: %u bytes\n"
           "data_t-size: %u bytes\n\n",
           sizeof(messi->name),
           sizeof(messi->age),
           sizeof(messi->height),
           sizeof(*messi));

    // Mostrar direcciones de memoria
    printf("Direcciones:\n");
    printf(" &name  : %p\n", (void*)&(messi->name));
    printf(" &age   : %p\n", (void*)&(messi->age));
    printf(" &height: %p\n", (void*)&(messi->height));
    printf(" &messi : %p\n", (void*)messi);

    /*
     * Observación: es posible que haya "huecos" (padding)
     * entre los campos por alineación de memoria.
     * Por ejemplo: name ocupa 30 bytes, pero age podría empezar en
     * dirección 32 por alineación a 4 u 8 bytes.
     */

    free(messi);  // Liberar memoria dinámica

    return EXIT_SUCCESS;
}
/*
🔍 ¿Hay algo raro en las direcciones?

Sí. Probablemente vas a ver:
 - name empieza en una dirección.
 - age no empieza justo después, sino un poco más adelante (por ejemplo, si name termina en 0x7ff...1d, age puede empezar en 0x7ff...20).

Eso se debe a que el compilador alinea los datos en memoria para que accedan más rápido (alineación a múltiplos de 4 u 8 bytes). 
Esto genera "padding", es decir, bytes sin uso.

Diferencia entre versión automática y dinámica
    - En la versión automática (data_t messi = {...}):
        
        La estructura vive en el stack.
        Se destruye al salir de la función.
        No se usa malloc ni free.

    En la versión dinámica (data_t *messi = malloc(...)):
        
        Vive en el heap (montículo).
        Puede sobrevivir entre funciones.
        Se debe liberar con free para evitar leaks.


*/