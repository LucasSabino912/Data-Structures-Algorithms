# Practico 1 - Parte 1

# Ejercicio 1

Escribí algoritmos para resolver cada uno de los siguientes problemas sobre un arreglo a de posiciones de 1 a n, utilizando **do.** 

a) Inicializar cada componente del arreglo con el valor 0.

```c
proc todo0 (out a:array[1..n] of nat)
	var i: nat
	i:= 1
	while i <= n do
		a[i]:= 0
		i:= i+1
	od
end proc
```

b) Inicializar el arreglo con los promeros n numeros naturales positivos

```c
proc positivos (out a:array[1..n] of nat)
	var i: nat
	i:= 1
	while i <= n do
		a[i]:= i
		i:= i+1
	od
end proc
```

c) Inicializar el arreglo con los promeros n numeros naturales impares

```c
proc impares (out a:array[1..n] of nat)
	var imp,i: nat
	i:= 1
	while i <= n do
		a[i]:= i * 2 - 1
		i:= i + 1
	od
end proc
```

d) Incrementar las posiciones impares del arreglo y dejar intactas las posiciones pares

```c
proc inc (in/out a:array[1..n] of nat)
	var i: nat
	i:= 1
	while i <= n do
		a[i]:= a[i] + 1
		i:= i + 2
	od
end proc
```

# Ejercicio 2

Transformar los algoritmos en uno equivalente que use for . . . to

a) Inicializar cada componente del arreglo con el valor 0.

```c
proc todo0 (out a:array[1..n] of nat)
	var i: nat
	for i:= 1 to n do 
		a[i]:= 0
	od
end proc
```

b) Inicializar el arreglo con los promeros n numeros naturales positivos

```c
proc positivos (out a:array[1..n] of nat)
	var i: nat
	for i:= 1 to n do
		a[i]:= i
	od
end proc
```

c) Inicializar el arreglo con los promeros n numeros naturales impares

```c
proc impares (out a:array[1..n] of nat)
	var i: nat
	for i:= 1 to n do
		a[i]:= i * 2 + 1
end proc
```

d) Incrementar las posiciones impares del arreglo y dejar intactas las posiciones pares

```c
proc inc (in/out a:array[1..n] of nat)
	var i: nat
	for i:= to n do
		if (i mod 2 = 1) then
			a[i]:= a[i] + 1
		fi
	od
end proc
```

# Ejercicio 3

Escribi un algoritmo que reciba un arreglo a de posiciones de 1 a n y determine si el arreglo recibido esta ordenado o no. Explica en palabras que hace y como el algoritmo

```c
proc isSorted (in a:array[1..n], out res: bool
	var i: nat
	i:= 1
	res:= true
	for i:= 1 to n-1 do
		if a[i] > a[i+1] then
			res:= false
		fi
	od
end proc
```

El algoritmo retorna una variable de tipo bool que toma el valor true si el algoritmo esta ordenado de menor a mayor

El algoritmo tiene un ciclo for iterando sobre el arreglo, luego un if que chequea que la posicion i sea menor o igual a la posicion siguiente. Si esta posicion no se cumple, la variable res toma el valor false

# Ejercicio 4

Ordenar los siguientes arreglos, utilizando el algoritmo de **`ordenación por selección.`** Mostrar en cada paso de iteración cuál es el elemento seleccionado y cómo queda el arreglo después de cada intercambio.

a) `[7, 1, 10, 3, 4, 9, 5]`

[7, 1, 10, 3, 4, 9, 5] {- busco el menor elemento -}

[7, **1**, 10, 3, 4, 9, 5] {- intercambio con el elemento de la primera posición -}

[**1**, 7, 10, 3, 4, 9, 5] {- busco el menor elemento de los restantes -}

[**1**, 7, 10, **3**, 4, 9, 5] {- intercambio con el elemento de la segunda posición -}

[**1**, **3**, 10, 7, 4, 9, 5] {- busco el menor elemento de los restantes -}

[**1, 3**, 10, 7, **4**, 9, 5] {- intercambio con el elemento de la tercera posición -}

[**1, 3, 4**, 7, 10, 9, 5] {- busco el menor elemento de los restantes -}

[**1, 3, 4**, 7, 10, 9, **5**] {- intercambio con el elemento de la cuarta posición -}

[**1, 3, 4, 5**, 10, 9, 7] {- busco el menor elemento de los restantes -}

[**1, 3, 4, 5**, 10, 9, **7**] {- intercambio con el elemento de la cuarta posición -}

[**1, 3, 4, 5, 7**, 9, 10] {- busco el menor elemento de los restantes -}

[**1, 3, 4, 5, 7, 9**, 10] {- está en la posición correcta, el arreglo está ordenado -}

# Ejercicio 5

Calcular de la manera más exacta y simple posible el número de asignaciones a la variable `t` de los siguientes algoritmos.

```c
t := 0
for i := 1 to n do
    for j := 1 to n² do
        for k := 1 to n³ do
            t := t + 1
        od
    od
od
```

A ojo se puede ver que son n * n² * n³, por lo tanto es n^6

```c
t := 0
for i := 1 to n do
    for j := 1 to i do
        for k := j to j + 3 do
            t := t + 1
        od
    od
od
```

 2n²(n+1)

# Ejercicio 6

Descifrar `qué` hacen los siguientes algoritmos, explicar `cómo` lo hacen y reescribirlos asignando nombres adecuados a todos los identificadores

```c
proc p (in/out a: array[1..n] of T)
    var x: nat
    for i:= n downto 2 do
        x:= f(a,i)
        swap(a,i,x)
    od
end proc

fun f (a: array[1..n] of T, i: nat) ret x: nat
    x:= 1
    for j:= 2 to i do
        if a[j] > a[x] then
            x:= j
        fi
    od
end fun
```

La funcion f busca el mayor elemento del arreglo, y el procedimiento p lo que hace es ordenar de menor a mayor pero empezando por el final del arreglo 

# Ejercicio 10

Descifrar `qué` hacen los siguientes algoritmos, explicar `cómo` lo hacen y reescribirlos asignando
nombres adecuados a todos los identificadores

```c
proc q (in/out a: array[1..n] of T)
    for i:= n-1 downto 1 do
        r(a,i)
    od
end proc
```

```c
proc r (in/out a: array[1..n] of T, in i: nat)
    var j: nat
    j:= i
    while (j < n) ∧ (a[j] > a[j+1]) do
        swap(a,j+1,j)
        j:= j+1
    od
end proc
```

Ordena el arreglo de menor a mayor pero empezando por el ultimo elemento, igual que el insertion sort pero de derecha a izquierda