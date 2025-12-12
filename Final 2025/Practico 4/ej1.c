/* Escribir un algoritmo que dada una matriz a: array[1..n,1..m] of int calcule el elemento m´ınimo.
Escribir otro algoritmo que devuelva un arreglo array[1..n] con el mınimo de cada fila de la matriz a */

fun minFromArray (a:array[1..n,1..m] of int) ret min: int
    min := +inf

    for i:= 1 to n do 
        for j:= 1 to m do
            if a[i,j] < min then
                min:= a[i,j]
            fi
        od
    od
end fun

fun minToArray (a:array[1..n,1..m] of int) ret min:array[1..n] of int
    var min: int
    for i:= 1 to n do
        min[i]:= a[i,1]
        for j:= 1 to m do
            if a[i,j] < min then
                min[i]:= a[i,j]
            fi
        od
    od
end fun 