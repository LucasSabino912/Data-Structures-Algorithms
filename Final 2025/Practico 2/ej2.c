/* Escribı el procedimiento “intercalar cada” que recibe un arreglo a : array[1..2n] of int 
y un numero natural i : nat; e intercala el segmento a[1, 2ˆi] con a[2i + 1, 2 ∗ 2ˆi], 
el segmento a[2 ∗ 2ˆi + 1, 3 ∗ 2ˆi] con a[3 ∗ 2ˆi + 1, 4 ∗ 2ˆi], etc. 
Cada uno de dichos segmentos se asumen ordenados. */

proc intercalar_cada (in/out a : array[1..2*n] of int, in i : nat)
    var tam, inicio, medio, fin : nat
    tam := 2^i

    inicio := 1
    while inicio <= 2*n do
        medio := inicio + tam - 1
        fin   := inicio + 2*tam - 1

        // merge del segmento [inicio .. medio] con [medio+1 .. fin]
        merge(a, inicio, medio, fin)

        inicio := inicio + 2*tam
    od
end proc

proc merge(in/out a : array[1..2*n] of int, in l, m, r : nat)
    var i, j, k : nat
    var aux : array[l..r] of int

    i := l
    j := m + 1
    k := l

    while i <= m ∧ j <= r do
        if a[i] <= a[j] then
            aux[k] := a[i]
            i := i + 1
        else
            aux[k] := a[j]
            j := j + 1
        fi
        k := k + 1
    od

    while i <= m do
        aux[k] := a[i]
        i := i + 1
        k := k + 1
    od

    while j <= r do
        aux[k] := a[j]
        j := j + 1
        k := k + 1
    od

    // copiar de vuelta
    for k := l to r do
        a[k] := aux[k]
    od
end proc

