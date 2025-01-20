/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

// Esta funcion lee el tamaño y cada uno de los miembros del array por teclado
unsigned int array_from_stdin(int array[], unsigned int max_size) {
    unsigned int size = 0;
    printf("Ingrese el tamaño del arreglo\n");
    scanf("%u", &size);

    if(size > max_size){
        exit(EXIT_FAILURE);
    }

    printf("Ingresar elementos\n");
    for(unsigned int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

    return size;
}

// Esta funcion imprime los datos del input como  un arreglo
void array_dump(int a[], unsigned int length) {
    
    printf("[%d", a[0]);

    for (unsigned int i = 1u; i < length; i++) {
        printf(", %d", a[i]);
    }

    printf("]\n");
}


int main() {

    int array[MAX_SIZE];
    
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
