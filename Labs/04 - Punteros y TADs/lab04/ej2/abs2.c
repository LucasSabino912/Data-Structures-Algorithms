#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// *y = valor de y, &y = direccion de memoria de y
void absolute(int x, int *y) {
    if (x >= 0){
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a = 0, res = 0;
    a = -10;

    absolute(a, &res); // res = 10

    printf("%d", &res);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/*
*y en absolute nunca se modifica, solo se modifica el valor al que apunta

En este programa, absolute puede modificar directyamente el valor de res 
en main a traves de *y
*/