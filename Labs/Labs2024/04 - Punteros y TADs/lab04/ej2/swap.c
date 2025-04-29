#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y) {
    int tmp;
    tmp = *x;  // Guarda el valor de *x en una variable temporal.
    *x = *y;   // Asigna el valor de *y a *x.
    *y = tmp;  // Asigna el valor guardado en tmp a *y.
}

int main(void){
    int x = 6, y = 4;
    printf("%d %d", x, y);

    swap(&x, &y);

    printf("%d %d", x, y);

    return EXIT_SUCCESS;
}