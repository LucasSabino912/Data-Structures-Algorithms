/* Escribi algoritmos para resolver cada uno de los siguientes problemas sobre un arreglo a de posiciones 1 a n, 
utilizando do. Elegi en cada caso entre estos dos encabezados el que sea mas adecuado:

proc nombre (in/out a:array[1..n] of nat)
. . .
end proc

proc nombre (out a:array[1..n] of nat)
. . .
end proc

(a) Inicializar cada componente del arreglo con el valor 0.
(b) Inicializar el arreglo con los primeros n n´umeros naturales positivos.
(c) Inicializar el arreglo con los primeros n n´umeros naturales impares.
(d) Incrementar las posiciones impares del arreglo y dejar intactas las posiciones pares. */


// in/out depende del contenido previo del array
// out no depende del contenido previo, se usa comunmente para inicializar


// a
proc todo0 (out a:array[1..n] of nat)
    var i: int
    i := 1

    while i <= n do
        a[i] := 0
        i := i + 1
    od

end proc

// b
proc primerosN (out a:array[1..n] of nat)
    var i: int
    i := 1

    while i <= n do 
        a[i] := i
        i := i + 1 
    od

end proc 

// c
proc primerosImpares (out a:array[1..n] of nat)
    var i, aux: int
    i := 1
    aux := 1

    while i <= n do 
        a[i] := aux
        i := i + 1 
        aux:= aux + 2
    od
end proc

// d
proc incrementarImpares (in/out a:array[1..n] of nat)
    var i: nat
    i := 1

    while i <= n do
        a[i] := a[i] + 1
        i:= i + 2 
    od

end proc