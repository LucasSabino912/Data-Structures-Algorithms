#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if(x > 0){
        y = x;
    } else {
        y = -x;
    }
}

int main(void) {
    int a = -10, res = 0;
    absolute(a, res);

    printf("%i", res);

    return EXIT_SUCCESS;
}

// No imprime nada