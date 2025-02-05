# Programación dinámica

La programacion dinamica es un metodo para transformar una definicion recursiva, como un problema de backtracking, en una definicion iterativa, a traves de una **tabla de valores**

El objetico es evitar la reiteracion de computos, un ejemplo dserua la definicion de la secuencioa de Fibonacci

fn = 

> n                    n ≤1
> 

> fn-1 + fn-2     n > 1
> 

Esta funcion recursiva es exponencial, la razon es que el calculo de fn lleva a calcular: 

2 veces fn-2, 3 veces fn-3, 5 veces fn-4, etc.

### ¿Como evitar tantos recalculos?

Llevando una tabla de valores calculados comenzando desde los casos base.

Sea f un arreglo de 0 a n:

- f[0]:= 0
- f[1]:= 1
- f[2]:= f[0] + f[1]
- f[3]:= f[2] + f[1]

### Fibonacci a traves de una tabla

```c
{ PRE: n > 1 }
fun fib(n: nat) ret r: nat
	var f: array[0..n] of nat
	f[0]:= 0
	f[1]:= 1
	for i:= 2 to n do
		f[i]:= f[i-1] + f[i-2]
	od
	r:=f[n]
end fun
```

Este algoritmo paso de ser exponencial a ser lineal O(n)

### Problema de la moneda

```c
cambio(i,j) = 
	| 0        j = 0
	| inf      j > 0 && i = 0
	| min(cambio(i-1,j), 1+cambio(i,j-di)    j >= d1 > 0 && i > 0
```

Este problema puede llegar a ser exponencial debido a las dos llamadas recursivas que tiene el último caso.

- Habiendo dos parámetros, la tabla sera una matriz en vez de un vector como en el caso de Fibonacci
- Los casos base corresponden al llenado de la primera columna y primera fila de la matriz

```c
fun cambio(d:array[1..n] of nat, k: nat) ret r: nat
	var cam: array[0..n,0..k] of nat
	for i:=0 to n do cam[i,0]:=0 od
	for j:=0 to k do cam[0,1]:=inf od
	for i:=1 to n do
		for j:1 to k do
			if d[i] > j then
				cam[i,j]:= cam[i-1,j]
			else 
				cam[i,j]:= min(cam[i-1,j], 1 + cam[i,j-d[i]])
			di
		od
	od
	r:=cam[n,k]
end fun
```

### Problema de la mochila

```c
fun mochila(v:array[1..n] of valor, w:array[1..n] of nat, W: nat) ret r: Valor
	var moch:array[0..n,0..W] of Valor
	for i:= to n do moch[i,0]:=0 od
	for j:= to W do moch[o,j]:=0 od
	for i:=1 to n do
		for j:=1 to W do
			if w[i] > j then
				moch[i,j]:= max(moch[i-1,j],v[i]+moch[i-1],j-w[i]])
			fi
		od
	od		
	r:=moch[n,W]
end fun
```

# Problema de la moneda (bt a pd)

Dar una definición de la función cambio utilizando la técnica de programación dinámica a partir de la siguiente definición recursiva (backtracking):

```c
cambio(i, j) = | 0                                                  si j = 0
               | infinito                                           si j > 0 ∧ i = 0
               | min q∈{0,1,...,j÷di} (q + cambio(i−1, j−q ∗ di))   si j > 0 ∧ i > 0
```

```c
fun cambio(monedas:array[0..n] of nat, c: nat) ret res: nat
	var a:array[0..n,0..c] of nat
	
	for i:=0 to n do a[i,0]:= 0
	for j:=0 to c do a[0,j]:= infinito
	
	for i:=1 to n do
		for j:=1 to c do
			a[i,j]:= min(q∈{0,1,...,j÷di} (q + a−1, j−q ∗ di)))
		od
	od
	res:=a[n,c]
end fun
```

# Problema de la panadería

```c
panaderia(i,j) = | 0                                                si i = 0 ∨ j = 0     // no tengo pedidos ó no tengo harina
                 | max(mi + panaderia(i-1,j-hi), panaderia(i-1,j))  si i > 0 ∧ j > 0     // tengo pedidos y tengo harina
                 
fun panaderia(m: array[1..n] of nat, h: array[1..n] of nat, H: nat) ret r: nat
	var a:array[0..n,0..h] of nat
	
	for i:=0 to n do a[i,0]:= 0
	for j:=0 to n do a[0,j]:= 0
	
	for i:=1 to n do
		for j:=1 to h do
			a[i,j]:= max(m[i] + a[i-1,j-1], a[i-1,j])
		od
	od
	r:=a[n,h]
end fun             
```

# Problema del globo aerostático

```c
globo(i,j) = | 0                                        si j = 0             // no debo deshacerme de objetos
             | infinito                                 si i = 0 ∧ j > 0     // debo deshacerme de objetos, pero no tengo más
             | min(vi + globo(i-1,j-pi), globo(i-1,j))  si i > 0 ∧ j > 0     // debo deshacerme de objetos, tengo objetos

fun globo(p:array[0..n] of nat, v:array[0..n] of nat, P: nat) ret r: nat
	var a:array[0..n,0..d] of nat
	
	for i:= 0 to n do a[i,0]:=0
	for j:= 1 to d do a[0,j]:=infinito
	
	for i:=1 to n do
		for j:=1 to d do
			a[i,j]:= min(v[i] + a[i-1,j-1], a[i-1,j])
		od
	od
	r:=a[n,p]
end fun
```