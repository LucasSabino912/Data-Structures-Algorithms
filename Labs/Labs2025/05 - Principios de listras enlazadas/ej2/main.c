#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
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

    n1->data = 9;
    n1->next = n2;

    n2->data = 12;
    n2->next = n3;

    n3->data = 18;
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
