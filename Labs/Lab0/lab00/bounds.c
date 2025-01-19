#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 0;

    for(int i = 0; i < length; i++){
        if(value < arr[i]){
            res.is_lowerbound = false;
        } 
        else if(value > arr[i]){
            res.is_upperbound = false;
        }
        else if(value == arr[i]){
            res.exists = true;
            res.where = i;
        } 
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value = 9;
    int input;

    printf("Ingresar los elementos del arreglo uno a uno\n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("Elemento %d: ", i);
        scanf("%d", &input);
        a[i] = input;
    }

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_lowerbound && result.exists){
        printf("El valor es minimo y esta en la posicion %d\n", result.where);
    } 
    else if (result.is_upperbound && result.exists){
        printf("El valor es maximo y esta en la posicion %d\n", result.where);        
    }
    if (result.is_lowerbound && !result.exists){
        printf("Es cota inferior %d\n", result.where);
    } 
    else if (result.is_upperbound && !result.exists){
        printf("Es cota superior %d\n", result.where);        
    }

    return EXIT_SUCCESS;
}
