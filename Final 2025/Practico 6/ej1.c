/* Implementar el TAD Pila utilizando la siguiente representación:

implement Stack of T where

type Stack of T = List of T */


// Crea una pila vacia
fun empty_stack() ret s: Stack of T
    empyt_lisy(s)
end fun

// Agrega un elemento al tope de s
proc push(in e: T, in/out s: Stack of T)
    addl(e, s)
end proc

// Libera memoria en caso de que sea necesario
proc destroy(in/out s: Stack of T)
    destroy_list(s)
end proc

// Devuelve true si la pila es vacia
fun is_empty_stack(s: Stack of T) ret b: Bool
    b:= length(s) = 0
end fun

// Devuelve el elemento en el tope de s
{- PRE: !is_empty_stack(s) -}
fun top(s: Stack of T) ret e: T
    e:= index(s, length(s)
end fun

// Elimina el elmento en el tope de s
{- PRE: !is_empty_stack(s) -}
proc pop(in/out s: Stack of T)
    take(length(s) - 1)
end proc

// Copia s en s1
fun copy_stack(s: Stack of T) ret s1: Stack of T
    s1:= copy_list(s)
end fun