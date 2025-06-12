#include "remove.h"

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de eliminar todas las
 * ocurrencias de `e` en `l`
 *
 */
list remove_elem(list l, elem e) {
    list new = empty();
    for(int i = 0; i < length(l); i++){
        if(index(l,i) != e){
            if(is_empty(new)){
                new = addl(index(l,i), new);
            } else {
                new = addr(new, index(l,i));
            }
        }
    }

    return new;
}