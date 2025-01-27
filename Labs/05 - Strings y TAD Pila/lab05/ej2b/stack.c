#include <stdlib.h>
#include <assert.h>
#include "stack.h"

// Implemento un tack usando las listas con nodos
struct _s_stack {
    stack_elem elem;
    stack next;
    nat size;
};

/**
* @brief Creates an empty stack
* @return An empty stack
*/
stack stack_empty(){
    return NULL;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e){
    stack push = malloc(sizeof(struct _s_stack)); // Creo un stack
    push->elem = e; // Primer elemento del stack, e (nustro elemento a agregar al comienzo)
    push->next = s; // Elemento proximo, el stack original
    push->size = stack_size(s) + 1; // Agrando push

    return push;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s){
    assert(!stack_is_empty(s)); // Chequeo que s no sea NULL
    stack pop = s->next; // Defino a pop como el resto del stack que no sea e
    free(s); // Libero memoria de s, para que s->elem no quede perdido en la memoria
    
    return pop;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s) {
    return (s != NULL ? s->size : 0);
}


/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s){
    return s == NULL;
}

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem *stack_to_array(stack s){
    // Creo un arreglo de tipo stack_elem (contendra elementos de ese tipo)
    stack_elem * array = malloc(sizeof(stack_elem) * stack_size(s));
    stack aux = s; // Creo un stack auxiliar
    unsigned int i = 0;
    while(aux != NULL){ // Mientras que aux no sea null
        array[i] = stack_top(aux); // Pongo el primer elemento de aux en array
        aux = aux->next; // Paso al proximo elemento
        i++;
    }

    return array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s){
    while(!stack_is_empty(s)){
        s = stack_pop(s);
    }
    return NULL;
}