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
    node *n1 = malloc(sizeof(node));
    node *n2 = malloc(sizeof(node));
    node *n3 = malloc(sizeof(node));

    if (n1 == NULL || n2 == NULL || n3 == NULL){
        free(n1);
        free(n2);
        free(n3);
        return NULL;
    }

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    return n1;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    if(xs == NULL){
        exit(EXIT_SUCCESS);
    }

    node *new_node = xs;
    xs = xs->next;
    free(new_node);

    return xs;
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

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
