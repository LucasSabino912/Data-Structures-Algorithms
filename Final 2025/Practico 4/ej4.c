/* Dados dos punteros p,q: pointer to int

Escribir un algoritmo que intercambie los valores referidos sin modificar los valores de p y q.

Escribir otro algoritmo que intercambie los valores de los punteros.*/

// Cambian los punteros pero no lo valores
// p apunta a lo que apuntaba q y q a lo que apuntaba p
fun ptSwap(p,q: pointer to int)
    var tmp: int
    tmp:= *p
    *p:= *q
    *q:= tmp
end fun

// Cambian los valores de lo que apuntan pero siguen aputnando a lo mismo
fun ptSwap(p,q: pointer to int)
    var tmp: int
    tmp:= p 
    p:= q
    q:= tmp
end fun+

