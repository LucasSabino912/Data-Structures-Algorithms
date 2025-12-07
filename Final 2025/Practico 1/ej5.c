Calcula de la manera mas exacta y simple posible el numero de asignaciones a la variable t de los
siguientes algoritmos. Las ecuaciones que se encuentran al final del practico pueden ayudarte.

(a) 
t := 0
for i := 1 to n do
    for j := 1 to nˆ2 do
        for k := 1 to nˆ3 do
            t := t + 1
        od
    od
od

k va de nˆ3, j va desde nˆ2, i va desde n
=> nˆ3 * nˆ2 * n = nˆ6 asignaciones de t


(b) 
t := 0
for i := 1 to n do
    for j := 1 to i do
        for k := j to j + 3 do
            t := t + 1
        od
    od
od

2nˆ2 + 2n asignaciones de la variable t