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
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
    assert(xs != NULL);
    node *new_node = malloc(sizeof(*new_node));

    new_node->data = 31;

    while(xs->next != NULL){
        xs = xs->next;
    }

    xs->next = new_node;
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

    printf("Lista antes del append: ");

    show_list(my_list);

    append_example(my_list);

    printf("Lista después del append: ");

    show_list(my_list);

    return 0;
}
