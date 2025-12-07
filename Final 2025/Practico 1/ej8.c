Calcula el orden del numero de asignaciones a la variable t de los siguientes algoritmos.
(a) 
t := 1
do t < n
    t := t ∗ 2
od
// Cada iteracion duplica a t
// Queremos saber cuantas veces podemos multiplicar por 2 antes de llegar a n
// => t = 2ˆk = n => k = log2 n
// Cada iteracion hace una asignacion a t asi que:
// O(log n)


(b) 
t := n
do t > 0
    t := t div 2
od
// Ahora t se divide por 2 cada vex
// O(log n)

(c) 
for i := 1 to n do
    t := i
    do t > 0
        t := t div 2
    od
od

// El while es O(log n)
// y el for es O(n)
// O(n log n)


(d) 
for i := 1 to n do
    t := i
    do t > 0
        t := t − 2
    od
od

// O(nˆ2)