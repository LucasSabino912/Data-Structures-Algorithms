#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    // Crea los nodos dinamicamente
    node* n1 = malloc(sizeof(node));
    node* n2 = malloc(sizeof(node));
    node* n3 = malloc(sizeof(node));

    // Verificar que la memoria se haya asignado correctamente
    if(n1 == NULL || n2 == NULL || n3 == NULL){
        free(n1);
        free(n2);
        free(n3);
        return NULL;
    }

    // Asigno valores a los nodos
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    // Enlazar los nodos
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    return n1;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    show_list(my_list);

    return 0;
}
