#include <stdlib.h>
#include <stdio.h>

/* Simulamos el procedimiento absolute (proc = void) */
void absolute(int x, int y) {
    if (x >= 0){
        y = x; 
    } else {
        y = -x;
    }
}

int main(void) {
    int a = 0, res = 0;
    a = -10;
    absolute(a, res);
    printf("%d", res);
    return EXIT_SUCCESS; // r:= 0
}

/*
Siguiendo la defincion del teorico, el valor que se imprime es 10
Pero en el programa, el valor es 0, ya que las variables x e y tienen el
scope limitado a absolute
*/