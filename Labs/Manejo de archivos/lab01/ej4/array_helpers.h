#include <stdbool.h>

/*
Aca escribo los prototipos de las funciones, que valores toman y devuelven.
Modularizar de esta forma es como crear una libreria aparte
*/

/** Transporta un arreglo de filepath a array
 * @param array al terminar la ejecucion contendra al array del filepath
 * @param max_size el tamaño maximo del arrau
 * @param filelpath la direccion del archivo que contiene al array
 * @returns size del array recibido
 **/
unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);

/**
 * Imprime un array dado por su arreglo
 * @param a el array a imprimir 
 * @param length su tamaño
 **/
void array_dump(int a[], unsigned int length);

/**
 * Retorna True si el arreglo esta ordenado
 * @param a el array que se chequeara
 * @param length el tamaño del array
 * @returns true si esta ordenado
 **/

bool is_sorted(int a[], unsigned int length);