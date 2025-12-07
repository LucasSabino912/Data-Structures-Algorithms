/* Escribı un algoritmo que reciba un arreglo a de posiciones 1 a n y determine si el arreglo recibido
esta ordenado o no. Explica en palabras que hace el algoritmo. Explica en palabras como lo hace. */

proc isSorted (in a:array[1..n] of int) ret is: bool
    is:= true    
    
    for i:= 1 to n do
        if a[i] > a[i+1] then
            is := false
        fi
    od
end proc

/* El algoritmo chequea que el arreglo este ordenado de menor a mayor, tiene una guarda que se fija si el numero 
en una posicion es mayor al siguiente, si esto se cumple, retornará false */ 