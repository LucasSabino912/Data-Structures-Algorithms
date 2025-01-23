#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

// Devuelve el segundo elemento de la llamada por consola
char *parse_filepath(int argc, char *argv[]){
    /* Parse the filepath given by command line*/
    char *result = NULL;
    if(argc < 2){
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

/**
 * @param path, toma la direccion del archivo
 * @param indexes, arreglo de enteros, se va a rellenar de los indices del archivo
 * @param letters, arreglo de caracteres, se va a rellenar de las letras del archivo
 * @param max_size, tamaño maximo de los arreglos
 * @return tamaño real de los arrreglos
 */
unsigned int data_from_file(const char* path, unsigned int indexes[], char letters[], unsigned int max_size){
    FILE *file = fopen(path, "r");

    if(file == NULL){
        printf("Archivo no encontrado\n");
        exit(EXIT_FAILURE);
    }

    // Equiparo length al tamaño verdadero del archivo
    // feof me indica si el archivo llego al final
    unsigned int length = 0u;
    for (unsigned int i = 0; !feof(file); i++){
        // Devuelvo error si el archivo es mas grande de los esperado
        if(i >= max_size){
            printf("Archivo demasiado grande\n");
            exit(EXIT_FAILURE);
        }
        /**
          * fscanf lee datos de file de acuerdo con el formato especificado en la cadena
          * " -> *_*"": Indica que se espera encontrar literalmente con " -> *_*" en el archivo
          * Si no se encuentra, fscanf fallara 
         **/  
        if(fscanf(file, "%u -> *%c*", &indexes[i], &letters[i]) == 2){
            length++;
        }
    }

    // Devuelve error si algun indice excede el tamaño de length
    for(unsigned int i = 0; i < length; i++){
        if (indexes[i] > length - 1){
            printf("El valor del indice %u = %u, con la letra %c, es mayor al tamaño del arreglo = %u\n", i, indexes[i], letters[i], length);
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);
    return length;
}

void sort_letters(unsigned int indexes[], char letters[], char sorted[], unsigned int length){
    for (unsigned int i = 0; i < length; i++){
        for (unsigned int  j = 0; j < length; j++){
            // Si el indice en el array es igual al indice en el archivo se agrega la letra al array
            if(i == indexes[j]){
                sorted[i] = letters[j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 

    filepath = parse_filepath(argc, argv);

    length = data_from_file(filepath, indexes, letters, MAX_SIZE);

    sort_letters(indexes, letters, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

