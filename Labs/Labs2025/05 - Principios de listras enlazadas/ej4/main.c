#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    node *n1 = malloc(sizeof(*n1));
    node *n2 = malloc(sizeof(*n2));
    node *n3 = malloc(sizeof(*n3));

    n1->data = 9;
    n1->next = n2;

    n2->data = 12;
    n2->next = n3;

    n3->data = 18;
    n3->next = NULL;

    return n1;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    assert(xs != NULL);
    node *new_node = NULL;

    new_node = xs->next;

    return new_node;
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
