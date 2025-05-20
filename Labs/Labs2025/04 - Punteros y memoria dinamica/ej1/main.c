/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */

/*
  - int *p, p es un puntero a int
  
  - Referenciacion(&): Obtiene la direccion de memoria de una variable
  
  - Desreferenciacion(*): Obtiene el valor de lo apuntado por el puntero
  
  - Constante nula de punteros(NULL): Direccion de memoria nula

  - Indexacion y flecha: 
      p[n]: Obtiene el valor que hay en la memoria moviendose n lugares a la derecha
      p->member, es un atajo a (*p).member, p es un puntero a struct

*/

int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    /*
       Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42
    */

    int *p = NULL; // Creo el puntero a un entero
    p = &x; // P apunta a la direccion de memoria de x
    *p = 9; // Desreferencio a p y x toma el valor 9

    person_t *q = NULL; // Puntero a la estructura
    q = &m; // q apunta a la direccion de memoria de m
    q->age = 100; // Esto es lo mismo que (*q).age = 100;
    q->name_initial = 'F';

    p = &a[1]; // p apunta al primer segundo elemento de a
    *p = 42; // Desreferencio y cambio el valor de a[1]

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

