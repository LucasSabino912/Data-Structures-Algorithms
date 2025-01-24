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
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    int *p = NULL;
    char *q = NULL;

    p = &x; // Le asigno a p la direccion de memoria de x
            // Ahora p apunta a x
    
    *p = 9; // Esta linea la asigna 9 a la direccion de memooria a la que apunta p
            // Dado que p apunta a x, *p se refiere a x
            // Esto es equivalente a x = 9, por lo tanto, x vale 9

    p = &m.age; // p apunta a m.age

    *p = 100; // m.age toma el valor 100
  
    p = &m.name_initial; // p apunta a m.name_initial

    *p = 'F'; // m.name_initial toma el valor F

    p = &a[1]; // p apunta al segundo elemento de a

    *p = 42; // a[1] = 42

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

