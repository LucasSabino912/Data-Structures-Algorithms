#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int r = 0, x = 0, y = 0;
    x = 6;
    y = 4;

    printf("%d, %d\n", x, y);

    swap(&x, &y);

    printf("%d, %d\n", x, y);

    return r;
}
