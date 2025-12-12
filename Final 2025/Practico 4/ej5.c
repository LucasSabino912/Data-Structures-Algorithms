/* Dados dos arreglos a,b: array[1..n] of nat se dice que a es “lexicográficamente menor” que b sii
existe k ∈ {1...n} tal que a[k] < b[k], y para todo i ∈ {1...k−1} se cumple a[i] = b[i].
En otras palabras, si en la primera posición en que a y b difieren, el valor de a es menor que el de b. 
También se dice que a es “lexicográficamente menor o igual” a b sii a es lexicográficamente menor que b o a es igual a b. 

Escribir un algoritmo lex_less que recibe ambos arreglos y determina si a es lexicográficamente menor que b.

Escribir un algoritmo lex_less_or_equal que recibe ambos arreglos y determina si a es lexicográficamente menor o igual a b. */

fun lex_less(a:array[1..n] of nat, b:array[1..n] of b) ret lexLess: bool
    var done: bool
    done:= false
    lexLess:= false

    while done = false and i <= n do
        for i:= 1 to n do
            if a[i] < b[i] then
                lexLess:= true
                done:= true
            else if a[i] > b[i] then
                lexLess:= false
                done:= true
            fi
        od
    od
end fun
                
fun lex_less_eq(a:array[1..n] of nat, b:array[1..n] of b) ret lexLess: bool
    var done: bool
    done:= false
    lexLess:= true

    while done = false and i <= n do
        for i:= 1 to n do
            if a[i] < b[i] then
                lexLess:= true
                done:= true
            else if a[i] > b[i] then
                lexLess:= false
                done:= true
            fi
        od
    od
end fun
                