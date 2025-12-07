// Transforma cada uno de los algoritmos anteriores en uno equivalente que utilice for ... to

// a
proc todo0 (out a:array[1..n] of nat)
    for i:= 1 to n do
        a[i]:= 0
    od
end proc

// b
proc primerosN (out a:array[1..n] of nat)
    for i:= 1 to n do 
        a[i] := i
    od
end proc 

// c
proc primerosImpares (out a:array[1..n] of nat)
    var aux: int
    aux := 1    
    
    for i:= 1 to n do
        a[i] := aux
        aux:= aux + 2
    od
end proc

// d
proc incrementarImpares (in/out a:array[1..n] of nat)
    for i := 1 to n do
        if (i mod 2 = 1) then
            a[i] := a[i] + 1
        fi
    od
end proc