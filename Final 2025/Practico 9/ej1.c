// Problema de la moneda en backtracking 
cambio(i,j) =
	| 0        j = 0
	| inf      j > 0 && i = 0
	| min(cambio(i-1,j), 1+cambio(i,j-di))    j >= d1 > 0 && i > 0

// Problema de la moneda en programacion dinamica
fun cambio(d: array[1..n] of nat, k: nat) ret r: nat
    var cam: array[0..n, 0..k] of nat

    for i := 0 to n do cam[i,0] := 0 od
    for j := 1 to k do cam[0,j] := inf od

    for i := 1 to n do
        for j := 1 to k do
            if d[i] > j then
                cam[i,j] := cam[i-1,j]
            else
                cam[i,j] := min(cam[i-1,j],
                            1 + cam[i, j - d[i]])
            fi
        od
    od

    r := cam[n,k]
end fun