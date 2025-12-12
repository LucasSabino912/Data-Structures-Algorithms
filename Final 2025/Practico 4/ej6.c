/* Escribir un algoritmo que dadas dos matrices a,b:array[1..n,1..m] of nat devuelva su suma.

Escribir un algoritmo que dadas dos matrices a:array[1..n,1..m] of nat y b:array[1..m,1..p] of nat devuelva su producto. */

fun sumMatrix (a:array[1..n,1..m], b:array[1..n,1..m]) ret suma:array[1..n,1..m]
    for i:= 1 to n do
        for j:= 1 to m do
            suma[i,j]:= a[i,j] + a[i,j]
        od
    od
end fun


fun prodMatrix (a:array[1..n,1..m], b:array[1..m,1..p]) ret prod:array[1..n,1..p]
    for i:= 1 to n do        // filas de a
        for j:= 1 to p do    // columnas de b
            prod[i,j]:= 0    // Reinicio el acumuladtivo de la suma
            for k:=1 to m do // columnas de a, filas de b
                prod[i,j]:= prod[i,j] + (a[i,k] * b[k,j])
            od
        od
    od
end fun