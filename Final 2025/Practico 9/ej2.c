// Problema de la mochila

fun mochila(v:array[1..n] of valor, w:array[1..n] of w, W: nat) ret r: valor
    var moch[0..n,0..W] of valor

    for i:= 0 to n do moch[i,0]:= 0 od
    for j:= 0 to W do moch[0,j]:= 0 od

    for i:= 1 to n do
        for j:= 1 to W do
            if w[i] > j then
                moch[i,j]:= moch[i-1,j]
            else
                moch[i,j]:= (moch[i-1,j], 
                            v[i] + moch[i-1,j-w[i]])
            fi
        od
    od

    r:= moch[n,W]
end fun