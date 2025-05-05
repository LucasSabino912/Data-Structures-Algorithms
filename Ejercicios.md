# Ejercicios

# Practico 1.1

## Ejercicio 1

```c
// Inicializar cada componente del arreglo en 0
proc todo0 (in/out a:array[1..n] of nat)
	for i:= 1 to n do
		a[i]:= 0
	od
end proc

// Inicializar con los primeros n naturales
proc naturales (in/out a:array[1..n] of nat)
	for i:= 1 to n do
		a[i]:= i
	od
end proc

// Inicializar con los primeros n naturales impares
proc impares (in/out a:array[1..n] of nat)
	for i:= 1 to n do
		a[i]:= (i * 2) - 1
	od
end proc

// Incrementar las posiciones imapres del arreglo y dejar intactas las pares
proc inc (out a:array[1..n] of nat)
	for i:= 1 to n do 
		a[i]:= a[i] + 1
		i:= (i * 2) - 1
	od
end proc
```

## Ejercicio 3

```c
/* Algoritmo que determine si el array esta ordenado */
fun ord(a:array[1..n]) ret b: bool
b:= true
	for i:= 1 to n-1 do
		if a[i] > a[i+1] then
			b:= false
		fi
	od
end fun
```

## Ejercicio 4

Ordenar con selection sort

[5, 4, 3, 2, 1]

indice 1, valor 1

minimo = 1, swap 5 y 1

[1, 4, 3, 2, 5]

indice 2, valor 2

minimo 2, swap 4 y 2

[1, 2, 3, 4, 5]

indice 3, valor 3

esta en su posicion

[1, 2, 3, 4, 5]

indice 4, valor 4

esta en su posicion

[1, 2, 3, 4, 5]

indice 5, valor 5

esta en su posicion

## Ejercicio 5

Calcular el posible numero de asignaciones de la variable t

```c
t:= 0
for i:= 1 to n do
	for j:= 1 to n^2 do
		for k:= 1 to n^3 do
			t:= t+1
		od
	od
od
// n * n^2 * n^3 = n^6

t:= 0
for i:= 1 to n do
	for j:= 1 to i do
		for k:= 1 to j+3 do
			t:= t+1
		od
	od
od

// n(n+1)(n+11)/6
```

## Ejercicio 6

Descrifrar que hacen los algoritmos

```c
proc p (in/out a:array[1..n] of T)
	var x: nat
	for i:= n downto 2 do
		x:= f(a,i)
		swap(a,i,x)
	od
end proc

fun f(a:array[1..n] of T, i: nat) ret x: nat
	x:= 1
	for j:= 2 to i do
		if a[j] > a[x] then
			x:= j
		fi
	od
end fun

// Selection sort desde el ultimo elemento hasta el primero
```

## Ejercicio 7

Ordenar con insertion sort

[5, 4, 3, 2, 1]

Indice 2, valor 4

4 < 5, muevo 5 a la derecha

[4, 5, 3, 2, 1]

Indice 3, valor 3

3 < 5, muevo 5 a la derecha

3 < 4, muevo 4 a la derecha

[3, 4, 5, 2, 1]

Indice 4, valor 2

2 < 5, muevo 5 a la derecha

2 < 4, muevo 4 a la dercha

2 < 3, muevo 3 a la derecha

[2, 3, 4, 5, 1]

Indice 5, valor 1

1 < 5, muevo 5 a la derecha

1 < 4, muevo 4 a la dercha

1 < 3, muevo 3 a la derecha

1 < 2, muevo 2 a la derecha

[1, 2, 3, 4, 5]

El arreglo queda ordenado, llegue al final

## Ejercicio 8

Calcula el orden del numero de asignaciones de t en los siguientes algoritmos

```c
t:= 1
while t < n do
	t:= t * 2
od

/*
En cada iteración, t se multiplica por 2.

El valor de t sigue la secuencia: 1, 2, 4, 8, ..., hasta que t >= n.

Por lo tanto, el número de asignaciones a t es O(log⁡ n)
*/

for i:= 1 to n do
	t:= i
	while t > 0 do
		t:= t div 2
	od
od
/*
El ciclo externo se ejecuta n veces.

En cada iteración, t toma el valor i.

El ciclo interno divide t entre 2 repetidamente hasta que t sea 0.

El número de iteraciones del ciclo interno para un valor i es O(log⁡ i).

Sumando para i de 1 a n, el total es: O(n log n)
*/

t:= n 
while t > 0 do
	t:= t div 2
od

/*
Similar al ciclo interno del algoritmo 2 pero solo una vez.

El número de iteraciones es O(log⁡n).

Por lo tanto, el número de asignaciones a t es O(logn).
*/

for i:= 1 to n do
	t:= i
	while t > 0 do
		t:= t-2
	od
od

/*
El ciclo externo se ejecuta n veces.

En cada iteración, t toma el valor i.

El ciclo interno decrementa t de 2 en 2 hasta llegar a 0 o menos.

Por lo tanto, el número total de asignaciones a t es O(n2).
*/

/*

¿Qué significa que un ciclo tenga O(log n) iteraciones?

Cuando decimos que un ciclo se ejecuta O(log n) veces, 
significa que el número de iteraciones crece proporcionalmente 
al logaritmo de n (normalmente en base 2, 
pero la base no afecta el orden de crecimiento).
Esto ocurre típicamente cuando en cada iteración se reduce 
o aumenta el valor de la variable de control exponencialmente 
(por ejemplo, multiplicándola o dividiéndola por 2).*/
```

## Ejercicio 10

Descifrar que hacen estos algoritmos y como lo hacen

```c
proc q(in/out a:array[1..n] of T)
	for i:= n-1 downto 1 do
		r(a,i)
	od
end proc

proc r (in/out a:array[1..n] of T, in i: nat)
	var j: nat
	j:= i
	while j < n && a[j] > a[j+1] then
		swap(a,j+1,j)
		j:= j+1
	od
end proc
```

# Practico 1.2

## Ejercicio 3

Escribir el procedimiento **`intercalar_cada`** que recibe un arreglo a:**array**[1..2ⁿ] **of int** y un número natural i: **nat**; e intercala el segmento a[1,2ⁱ] con a[2ⁱ+1,2∗2ⁱ], el segmento a[2∗2ⁱ+1,3∗2ⁱ] con a[3∗2ⁱ+1, 4 ∗2ⁱ], etc. Cada uno de dichos segmentos se asumen ordenados. Por ejemplo, si el arreglo contiene los valores

```c
proc intercalar_cada (in/out a:array[1..2ⁿ] of T, i: nat)
    var tam, izq, der, med: nat
    tam:= 2ⁿ
    izq:= 1
    der:= 2ⁱ⁺¹      {- tamaño a mergear -}
    med:= (izq+der)/2
    while der ≤ tam
        merge(a, izq, med, der)
        izq:= der + 1
        der:= der + 2ⁱ⁺¹
        med:= (izq+der)/2
    od
end proc
```

## Ejercicio 4

Escribir una variante del procedimiento **`partition`** que en vez de tomar el primer elemento del segmento `a[izq, der]`como pivot, elige el valor intermedio entre el primero, el último y el que se encuentra en medio del segmento. Es decir, si el primer valor es 4, el que se encuentra en el medio es 20 y el último es 10, el algoritmo deberá elegir como pivot al último.

```c
proc partitionv2(in/out a:array[1..n] of T in lft,rgt: nat) ret piv: nat
	var i,j: nat
	mid:= (lft+rgt)/2
	
	// Busco el pivot
	if a[lft] <= a[mid] & a[mid] <= a[rgt] then
		piv:= mid
	else if a[mid] <= a[rgt] & a[rgt] <= a[lft] then
		piv:= rgt
	else if a[mid] <= a[lft] & a[lft] < a[rgt] then
		piv:= lft
	fi
	
	// Partition
	i:= lft, j:= rgt
	while i <= j do
		if a[i] <= a[piv] then
			i:= i+1
		else if a[i] > a[piv] & a[j] < a[piv] then
			swap(a,i,j)
			i:= i+1
			j:= j-1
		fi
	od
	swap(a,i,j)
	piv:= j
end proc
```

## Ejercicio 5

Escribir un algoritmo que dado un arreglo a:**array**[1..n] **of int** y un número natural k ≤ n devuelve el elemento de a que quedaría en la celda a[k] si a estuviera ordenado. Está permitido realizar intercambios en a, pero no ordenarlo totalmente. La idea es explotar el hecho de que el procedimiento **`partition`** del **`quick_sort`** deja al pivot en su lugar correcto.

```c
proc kesimo(in a:array[1..n) of int, k: nat) ret res: nat
	var izq, der: nat
	izq:= 1
	der:= n
	piv:= partition(a, izq, der)
	while piv != k do
		if piv < k then
			izq:= piv+1
		else 
			der:= piv-1
		fi
		partition(a, izq, der)
	od
	res:= a[k]
end fun	
```

# Practico 1.3

## Ejercicio 1

Calcular el orden de complejidad de los algoritmos

- a: numero de llamadas recursivas
- b: relación del tamaño entre x e xi
- k: el orden de descomponer y combinar es n^k

```c
proc f1 (in n: nat)
	if n <= 1 then skip
	else 
		for i:= 1 to 8 do f1(n div 2) od
		for i:= 1 to n^3 do t:= 1 od
```

Verifico si es DyV:

- Hay caso base (n ≤ 1) y hace algo constante (skip)
- En el caso complejo, se llama recursivamente **8 veces** con un tamaño de *n div 2*
- Además hace algo constante n^3 veces

A = 8, b = 2, k = 3

El algoritmo primero tiene un for de orden n^3 y otro de log n

Por lo que el algoritmo es de orden O(n^3 log n)

## Ejercicio 2

Dado un arreglo a: **array**[1..n] **of nat** se define una *cima* de a como un valor k en el intervalo 1,...,n tal que *a[1..k]* está ordenado crecientemente y *a[k..n]* está ordenado decrecientemente.

A) determinar si tiene cima

```c
fun tiene_cima (a:array[1..n] of nat, in length: nat) ret res:bool
	res:= false
	if length = 1
		exist:= true
	fi
	
	while i < length & !exist do
		if a[i-1] < a[i] & a[i] > a[i+1] then
			exist:= true
		else 
			i:= i+1
		fi
	od
end fun
```

B) Escribir un algoritmo que halle la cima

```c
fun cima(a:array[1..n]) ret pos_cima: nat
	var i: nat
	pos_cima:= 0;
	i:= 0
	
	while i <= n && a[i] < a[i+1] do
		pos_cima:= i+1
		i:= i+1
	od
end fun
```

C) El algoritmo de búsqueda de cima pero usando búsqueda binaria O(log n)

```c
fun cima(a:array[1..n] of T) ret izq: nat
	var der,mid: nat
	izq:= 0
	der:= n
	
	while izq < der do
		mid:= (izq + der) div 2
		if a[mid] < a[mid+1] then
			izq:= mid + 1
		else 
			der:= mid
		fi
	od
```

# Practico 2.1

## Ejercicio 1

Escribir un algoritmo que dada una matriz a:array[1..n,1..m] of int calcule el elemento minimo

```c
fun min(a:array[1..n] of int) ret min: int
	min:= a[1,1]
	for i:= 1 to n do
		for j:= 1 to m do
			if a[i,j] < min then
				min:= a[i,j]
			fi
		od
	od
end fun
```

Escribir otro algoritmo que devuelva un arreglo **array**[*1..n*] con el mínimo de cada fila de la matriz a.

```c
fun fila_minimos(a: array[1..n, 1..m] of int) ret res: array[1..n] of int
	for i := 1 to n do
	min := a[i,1]
		for j := 2 to m do
			if a[i,j] < min then
				min := a[i,j]
			fi
		od
		res[i] := min
	od
end fun
```

## Ejercicio 2

Dados los tipos

```c
type mes = enumerate
							enero
							febrero
							...
							diciembre
					  end enumerate

type clima = enumerate 
							Temp
							TempMax
							TempMin
							Pres
							Hum
							Prec
						 end enumerate
```

El arreglo med:**array**[1980..2016,enero..diciembre,1..28,Temp..Prec] **of nat** es un arreglo multidimensional que contiene todas las mediciones estadísticas del clima para la ciudad de Córdoba desde el 1/1/1980 hasta el 28/12/2016. Por ejemplo, med[2014,febrero,3,Pres] indica la presión atmosférica que se registró el día 3 de febrero de 2014. Todas las mediciones están expresadas con números enteros. Por simplicidad asumiremos que todos los meses tienen 28 días.

- a) Dar un algoritmo que obtenga la menor temperatura mínima (TempMin) histórica registrada en la ciudad de Córdoba según los datos del arreglo

```c
fun tmpmin (med:**array**[1980..2016,enero..diciembre,1..28,Temp..Prec] **of nat) ret min: float
	min:= +infinito
	for año:= 1980 to 2016 do
		for mes:= enero to diciembre do
			for dia:= 1 to 28 do
				if min > med[año,mes,dia,TempMin] then
					min:= med[año,mes,dia,TempMin]
				fi
			od
		od
	od
end fun**
```

- b) Dar un algoritmo que devuelva un arreglo que registre para cada año entre 1980 y 2016 la mayor temperatura máxima (TempMax) registrada durante ese año

```c
fun tmpmax (med:**array**[1980..2016,enero..diciembre,1..28,Temp..Prec] of T) ret max:array[1..n]	
	max_año: nat
	for año:= 1980 to 2016 do
		max_aux:= med[año, 1, 1, TempMax]
		for mes:= enero to diciembre do
			for dia:= 1 to 28 do
				if max_año < a[año,mes,dia,tempMax] then
					max[año]:=  a[año,mes,dia,tempMax]
				fi
			od
		od
	od
end fun	
```

## Ejercicio 3

Dado el tipo

```c
type person = tuple 
								name: string
								age: nat
								weight: nat
							end tuple
```

1. Escribir un algoritmo que calcule la edad y peso promedio de un arreglo a:array[1..n] of person

```c
fun edad_peso_prom(a:array[1..n] of person) ret edad,peso: nat
	edad:= 0
	peso:= 0
	
	for i:= 1 to n do
		edad:= edad + a[i].edad
		peso:= peso + a[i].peso
	od
	
	peso:= peso / n
	edad:= edad / n
end fun
```

b. Escribir un algoritmo que ordene alfabeticamente el arreglo

```c
proc insertion_sort(in/out a:array[1..n] of T)
	for i:= 2 to n do
		insert(a,i)
	od
end proc

proc insert(in/out a:array[1..n] of T, in i: nat)
	var j: nat
	j:= i
	while j > 1 && a[j].name < a[j-1].name then
		swap(a,j-1,j)
		j:= j-1
	od
end proc

proc swap(in/out a:array[1..n] of T, in i,j: nat)
	var tmp: T
	tmp:= a[i].name
	a[i].name:= a[j].name
	a[j].name:= tmp
end proc
```

## Ejercicio 4

Dados dos punteros p y q

1. Escribir un algoritmo que intercambie los valores referidos sin modificar los valores de p y q
2. Escribir un algoritmo que intercambie los valores de los punteros 

```c
/* Esto intercambia los valores referidos */
proc swap_ref(in/out p,q: pointer to int)
	var tmp: int
	tmp:= *p
	*p:= *q
	*q:= tmp
end proc

/* Esto intercambia los los punteros */
proc swap_pun(in/out p,q: pointer to int)
	var tmp: int
	tmp:= p
	p:= q
	q:= tmp
end proc
```

## **Ejercicio 5**

Dados dos arreglos a,b: **array**[*1..n*] **of nat** se dice que a es “lexicográficamente menor” que b sii
existe k ∈ {1...n} tal que a[k] < b[k], y para todo i ∈ {1...k−1} se cumple a[i] = b[i]. En otras palabras, si en la primera posición en que a y b difieren, el valor de a es menor que el de b. También se dice que a es “lexicográficamente menor o igual” a b sii a es lexicográficamente 
menor que b o a es igual a b.

- a) Escribir un algoritmo lex_less que recibe ambos arreglos y determina si a es lexicográficamente menor que b.

```c
fun lex_less(a,b: array[1..n] of nat) ret res: bool
     var i: nat
     i:= 1
     while (a[i] = b[i] ^ i < n) do
          i:= i + 1
     od
     res:= a[i] < b[i]
end fun
```

- b) Escribir un algoritmo lex_less_or_equal que recibe ambos arreglos y determina si a es lexicográficamente menor o igual a b.

```c
fun lex_less_or_equal(a,b: array[1..n] of nat) ret res: bool
     var i: nat
     i:= 1
     while (a[i] = b[i] ^ i < n) do
          i:= i + 1
     od
     res:= a[i] ≤ b[i]
end fun
```

- c) Dado el tipo enumerado

```c
type ord = enumerate
                igual
                menor
                mayor
           end enumerate
```

Escribir un algoritmo lex_compare que recibe ambos arreglos y devuelve valores en el tipo ord.

¿Cuál es el interés de escribir este algoritmo?

```c
fun lex_compare(a,b: array[1..n] of nat) ret res: ord
     var i: nat
     i:= 1
     while (a[i] = b[i] ^ i < n) do
          i:= i + 1
     od
     if(a[i] < b[i]) then res:= menor
     else if (a[i] = b[i]) then res:= igual
     else res:= mayor
     fi
end fun
```

## **Ejercicio 6**

Escribir un algoritmo que dadas dos matrices a,b: **array**[*1..n,1..m*] **of nat** devuelva su suma.

Recordemos que la suma de dos matrices es la suma coordenada a coordenada:

```c
fun suma_matrix(a,b:array[1..n,1..m] of nat) ret suma:array[1..n,1..m] of nat
	for i:= 1 to n do
		for j:= 1 to m do
			suma[i,j]:= a[i,j] + b[i,j]
		od
	od
end fun
```

**Ejercicio 7**

Escribir un algoritmo que dadas dos matrices a:**array**[*1..n,1..m*] **of nat** y b:**array**[*1..m,1..p*] **of nat** devuelva su producto.

```c
fun producto_matrix(a: array[1..n, 1..m] of nat, 
                    b: array[1..m, 1..p] of nat)
								    ret c: array[1..n, 1..p] of nat

    for i := 1 to n do
        for j := 1 to p do
            c[i, j] := 0
            for k := 1 to m do
                c[i, j] := c[i, j] + a[i, k] * b[k, j]
            od
        od
    od
end fun
```

# Practico 2.2

## Ejercicio 1

Completar la especificacion e implementacin de listas usando punteros

```c
spec List of T where

constructors
	fun empty() ret l: List of T
	{- Crea una lista vacia -}
	
	proc addl(in e: T, in/out l: List of T)
	{- Agrega el elemento e al comienzo de la lista -}

destroy
	proc destroy(in/out l: List of T)
	
operations
	fun is_empty(l: List of T) ret b: bool
	{- Devuelve true si es vacia -}
	
	fun head(l: List of T) ret e: T
	{- Devuelve el primer elemento de la lista l -}
	{- PRE: !is_empty -}
		
	proc tail(in/out l: List of T)
	{- Elimina el primer elemento de la lista l -}
	{- PRE: !is_empty -}

	proc addr(in/out l: List of T)
	{- Agrega un elemento al final de l -}
	{- PRE: !is_empty -}
	
	fun length(l: List of T) ret n: nat
	{- Devuelve el tamaño de la lista l -}
	
	proc concat(in/out l: List of T, in l0: List of T)
	{- Agrega al final de l todos los elementos de l0 -}
	
	fun index(l: List of T, in n: nat) ret e: T
	{- Devuelve el n-esimo elemento de la lista l -}
	
	proc take(in/out l: List of T, in n: nat)
	{- Deja en l los primeros n elementos, eliminando el resto -}
	
	proc drop(l: List of T, in n: nat)
	{- Elimina los primeros n elementos de l -}
	
	fun copy_list(l1: List of T) ret l2: List of T
	{- Copia todos los elemtnso de l0 en el mismo orden -}
	
	
Implement List of T where

type Node of T = tuple
									elem: T
									next: pointer to (Node of T)
								 end tuple

type List of T = pointer to (Node of T)

fun empty() ret l: List of T
	l:= null
end fun

proc addl(in e: T, in/out l: List of T)
	var new: pointer to (Node of T)
	new->elem:= e
	new->next:= l
	l:= new
end proc 

proc destroy(in/out l: List of T)
	var aux: pointer to (Node of T)
	while l != null do
		aux:= l
		l:= l->next
		free(aux)
	od
end proc

fun is_empty(l: List of T) ret b: bool
	b:= l = null
end fun

{- PRE: !is_empty(l) -}
fun head(l: List of T) ret e: T
	e:= l->elem
end fun

{- PRE: !is_empty(l) -}	
proc tail(in/out l: List of T)
	var aux: pointer to (Node of T)
	aux:= l
	l:= l->next
	free(aux)
end proc
	

proc addr(in e: T, in/out l: List of T)
	var new: pointer to (Node of T)
	alloc(new)
	new->elem:= e
	new->next:= null
	
	if l = null then
		l:= new
	else 
		var p: pointer to (Node of T)
		p:= l
		while p->next != null do
			p:= p->next
		od
		p->next:= new
	fi
end proc

fun length(l: List of T) ret n: nat
	var p: pointer to (Node of T)
	p:= l
	n:= 0
	while p->next != null do
		n:= n + 1
		p:= p->next
	od
end proc

proc concat(in/out l: List of T, in l0: List of T)
	if l = null then
		l:= l0
	else 
		var p: pointer to (Node of T)
		while p->next != null do
			p:= p->next
		od
		p->next:= l0
	fi
end proc

fun index(l: List of T, in n: nat) ret e: T
	var i: nat
	var p: pointer to (Node of T)
	i:= 0
	p:= l
	while i < n do
		p:= p->next
		i:= i+1
	od
	e:= p->elem
end fun

proc take(in/out l: List of T, in n: nat)
	var i: nat
	var p: pointer to (Node of T)
	while i < n-1 && p != null do
		p:= p->next
		i:= i+1
	od
	if p != null then
		destroy(p->next)
		p->next:= null
	fi
end proc
	
proc drop(l: List of T, in n: nat)
	var i := 0
	while i < n and l ≠ null do
		tail(l)
		i := i + 1
	od
end proc
```

## Ejercicio 2

Dada una constante natural N, implementar el TAD Lista de elementos de tipo T, usando un arreglo de tamaño N y un natural que indica cuántos elementos del arreglo son ocupados por elementos de la lista. ¿Esta implementación impone nuevas restricciones?

```c
spec List of T where

constructors
	fun empty() ret l: List of T
	{- Crea una lista vacia -}
	
	proc addl(in e: T, in/out l: List of T)
	{- Agrega el elemento e al comienzo de la lista -}

destroy
	proc destroy(in/out l: List of T)
	
operations
	fun is_empty(l: List of T) ret b: bool
	{- Devuelve true si es vacia -}
	
	fun head(l: List of T) ret e: T
	{- Devuelve el primer elemento de la lista l -}
	{- PRE: !is_empty -}
		
	proc tail(in/out l: List of T)
	{- Elimina el primer elemento de la lista l -}
	{- PRE: !is_empty -}

	proc addr(in/out l: List of T)
	{- Agrega un elemento al final de l -}
	{- PRE: !is_empty -}
	
	fun length(l: List of T) ret n: nat
	{- Devuelve el tamaño de la lista l -}
	
	proc concat(in/out l: List of T, in l0: List of T)
	{- Agrega al final de l todos los elementos de l0 -}
	
	fun index(l: List of T, in n: nat) ret e: T
	{- Devuelve el n-esimo elemento de la lista l -}
	
	proc take(in/out l: List of T, in n: nat)
	{- Deja en l los primeros n elementos, eliminando el resto -}
	
	proc drop(l: List of T, in n: nat)
	{- Elimina los primeros n elementos de l -}
	
	fun copy_list(l1: List of T) ret l2: List of T
	{- Copia todos los elemtnso de l0 en el mismo orden -}
	
	
Implement List of T where

type List of T = tuple
									size: nat
									elems: array[1..N] of T
								 end tuple

fun empty() ret l: List of T
	l.size:= 0
end fun

proc addl(in e: T, in/out l: List of T)
	l.size:= l.size + 1
	for i:= l.size downto 1 do
    l.elems[i+1]:= l.elems[i]
	od
	l.elems[1]:= e
end proc 

proc destroy(in/out l: List of T)
	l.size:= 0
end proc

fun is_empty(l: List of T) ret b: bool
	b:= l.size = 0
end fun

{- PRE: !is_empty(l) -}
fun head(l: List of T) ret e: T
	e:= l.elems[1]
end fun

{- PRE: !is_empty(l) -}	
proc tail(in/out l: List of T)
	for i:= 2 to l.size
		l.elems[i-1]:= l.elems[i]
	od
	l.size:= l.size - 1
end proc

proc addr(in e: T, in/out l: List of T)
	l.size:= l.size + 1
	l.elems[l.size]:= e
end proc

fun length(l: List of T) ret n: nat
	n:= l.size
end fun

proc concat(in/out l: List of T, in l0: List of T)
	var aux_size: nat
	aux_size:= l.size + 1
	l.size:= l.size + l0.size
	for i:= aux_size to l.size
		l.elems[i]:= l0.elems[i]
	od 
end proc

fun index(l: List of T, in n: nat) ret e: T
	e:= l.elems[n]
end fun

proc take(in/out l: List of T, in n: nat)
	var elim: nat
	elim:= l.size - n
	l.size:= l.size - elim 
end proc
	
proc drop(l: List of T, in n: nat)
	
end proc
```

## Ejercicio 5

Especificar el TAD **`Conjunto finito de elementos`** de tipo T. Como constructores considerar

- el conjunto vacío y
- el que agrega un elemento a un conjunto.

Como operaciones:

- una que chequee si un elemento e pertenece a un conjunto c,
- una que chequee si un conjunto es vacío,
- la operación de unir un conjunto a otro,
- insersectar un conjunto con otro y
- obtener la diferencia.

Estas últimas tres operaciones deberían especificarse como *procedimientos que toman dos conjuntos y modifican el primero de ellos*.

```c
spec set of T where

constructors
    fun empty_set() ret s: set of T
    {- crea un conjunto vacío -}

    proc add_elem(in e: T, in/out s: set of T)
    {- agrega un elemento al inicio del conjunto -}
    {- PRE: e no existe en el conjunto -}

destroy
    proc destroy_set(in/out s: set of T)
    {- Libera memoria en caso que sea necesario -}

operations
    fun belongs(s: set of T, e: T) ret b: bool
    {- chequea si el elemento e pertenece al conjunto c -}

    fun is_empty_set(s: set of T) ret b: bool
    {- chequea si el conjunto s es vacío -}

    proc merge_set(in/out s: set of T, in s1: set of T)
    {- une el conjunto s con el conjunto s1 -}

    proc intersec(in/out s: set of T, in s1: set of T)
    {- guarda en s la intersección entre los conjuntos s y s1 -}

    proc dif(in/out s: set of T, in s1: set of T)
    {- guarda en s la diferencia entre los conjuntos s y s1 -}

    fun copy_set(s: set of T) ret copy: set of T
    {- devuelve una copia del conjunto s -}
    
    
implement Set of T where

type Set of T = List of T

fun empty_set() ret s: Set of T
	s:= empty_list()
end fun

proc add_elem(in/out s: Set of T, in e: T)
	addr(s, e)
end proc

proc destroy_set(in/out s: Set of T)
	destroy_list(s)
end proc

fun belongs(s: Set of T, in e: T) ret b: bool
	
end fun

fun is_empty_set(s: Set of T) ret b: bool

end fun

proc merge_set(in/out s: Set of T, in s1: Set of T)

end proc

proc intersec(in/out s: Set of T, in s1: Set of T)

end proc

proc dif(in/out s: Set of T, in s1: Set of T)

end proc

fun copy_set(s: Set of T) ret c: Set of T

end fun
```

# Practico 2.3

## Ejercicio 1

Implementar el TAD Pila utilizando la siguiente representación:

```c
spec Stack of T where

constructors
	fun empty_stack() ret s: Stack of T
	{- Crea una ipla vacia -}
	
	proc push(in e: T, in/out s: Stack of T)
	{- agrega el elemento e al tope de s -}
	
operations
	fun is_empty_stack(s: Stack of T) ret b: Bool
	{- Devuelve true si la pila es vacia -}
	
	fun top(s: Stack of T) ret e: T
	{- Devuelve el elemento en el tope de s -}
	{- PRE: !is_empty_stack(s) -}
	
	proc pop(in/out s: Stack of T)
	{- Elimina el elemento en el tope de s -}
	{- PRE: !is_empty_stack(s) -}

Implement stack of T where

type Stack of T = List of T

// Para la resolución voy a agregar el tope de pila al final del stack

fun empty_stack() ret s: Stack of T
    s:= emprty_list()
end fun

proc push (in e: T, in/out s: Stack of T)
    addr(s,e)
end proc

proc destroy_stack (in/out s: Stack of T)
    destroy_list(s)
end proc

fun is_empty_stack(s: Stack of T) ret b: Bool
    b:= is_empty(s)
end fun

{- PRE: not is_empty_stack(s) -}
fun top(s: Stack of T) ret e: T
    e:= index(s, length(s))
end fun

{- PRE: not is_empty_stack(s) -}
proc pop (in/out s: Stack of T)
    take(length(s) - 1)
end proc

fun copy_stack (s: Stack of T) ret s_copy: Stack of T
    s_copy:= copy_list(s)
end fun
```

## Ejercicio 2

```c
spec Stack of T where

constructors
	fun empty_stack() ret s: Stack of T
	{- Crea una ipla vacia -}
	
	proc push(in e: T, in/out s: Stack of T)
	{- agrega el elemento e al tope de s -}
	
operations
	fun is_empty_stack(s: Stack of T) ret b: Bool
	{- Devuelve true si la pila es vacia -}
	
	fun top(s: Stack of T) ret e: T
	{- Devuelve el elemento en el tope de s -}
	{- PRE: !is_empty_stack(s) -}
	
	proc pop(in/out s: Stack of T)
	{- Elimina el elemento en el tope de s -}
	{- PRE: !is_empty_stack(s) -}

// Aparte de las operaciones de destruccion y copa de todos los TADs

implement Stack of T where

type Node of T = tuple
                    elem: T
                    next: pointer to (Node of T)
                 end tuple

type Stack of T = pointer to (Node of T)

fun empty_stack() ret s: Stack of T
	s:= null
end fun

proc push(in e: T, in/out s: Stack of T)
	var p: pointer to (Node of T)
	p->elem:= e
	p->next:= s
	s:= p
end proc

fun is_empty_stack(s: Stack of T) ret b: Bool
	b:= s = null
end fun

{- PRE: !is_empty_stack(s) -}
fun top(s: Stack of T) ret e: T
	e:= s->elem
end fun

{- PRE: !is_empty_stack(s) -}
proc pop(in/out s: Stack of T)
	var p: pointer to (node of T)
	p:= s
	s:= s->next
	free(p)
end proc

fun copy_stack (s: Stack of T) ret s_copy: Stack of T
    var p: pointer to (Node of T)
    p:= s
    while(p->next ≠ null) do
        alloc(s_copy)
        s_copy->elem:= p->elem
        s_copy->next:= p->next
        p:= p->next
    od
    s_copy->elem:= p->elem
    s_copy->next:= p->next
end fun
```

## Ejercicio 3

a) Implementar el TAD Cola utilizando la siguiente representación, donde N es una constante de tipo nat:

```c
implement Queue of T where

type Queue of T = tuple
                    elems: array[0..N-1] of T
                    size: nat
                  end tuple

```

```c
fun empty_queue() ret q: Queue of T
    q.size:= 0
end fun

proc enqueue (in/out q: Queue of T, in e: T)
    q.elems[q.size+1]:= e
    q.size:= q.size + 1
end proc

fun is_empty_queue(q: Queue of T) ret b: Bool
    b:= (q.size = 0)
end fun

{- PRE: not is_empty_queue(q) -}
fun first(q: Queue of T) ret e: T
    e:= q.elems[0]
end fun

{- PRE: not is_empty_queue(q) -}
proc dequeue (in/out q: Queue of T)
    for i:= 1 to N-1 do
        q.elems[i-1]:= q.elems[i]
    od
    q.size:= (N-1)-1
end proc
```

b) Implementar el TAD Cola utilizando un arreglo como en el inciso anterior, pero asegurando que todas las operaciones estén implementadas en orden constante.

```c
implement Queue of T where

type Queue of T = tuple
                    elems: array[0..N-1] of T
                    start: nat
                    end: nat
                  end tuple

fun empty_queue() ret q: Queue of T
    q.start:= 0
    q.end:= 0
end fun

proc enqueue (in/out q: Queue of T, in e: T)
    q.end:= (q.end + 1) `mod` N
    q.elems[q.end]:= e
end proc

fun is_empty_queue(q: Queue of T) ret b: Bool
    b:= (q.start = q.end)
end fun

fun first(q: Queue of T) ret e: T
    e:= q.elems[q.start]
end fun

proc dequeue (in/out q: Queue of T)
    q_start:= (q_start + 1) `mod` N
end proc
```

# Ejercicios parcial 1

## Algoritmos

```c
proc p(in/out a:array[1..n] of T)
	var i: nat
	var x: nat
	i:= 2
	do i <= N
		x:= f(a,i)
		swap(a,i,x)
		i:= i+2
	od
end proc

fun f (a:array[1..n] of T, i: nat) ret x: nat
	var j: nat
	j:= j+2
	x:= i
	do j <= N 
		if a[j] < a[x] then
			x:= j
		fi
		j:= j+2
	od
end fun

Ordena las posiciones pares 
del arreglo de forma creciente 
sin modificar los elementos en posiciones impares.

/***************************/
proc p(in/out l: list)
	var a,b: pointer to node
	a:= l
	while a != null do
		b:= a->next
		if b != null then
			a->next:= b->next
			free(b)
		fi
		a:= a->next
	od
end proc

Este procedimiento elimina 
todos los nodos en posiciones impares
 de la lista enlazada, 
 considerando que el primer nodo (l) es la posición 1.

/* Plantear la recurrencia en funcion de n y calcular el orden contando
   la cantidad de asignaciones a la variable t */
fun f(n: nat) ret t: nat
	if n <= 1 then
		t:= 1 // 1 asignacion
	else 
		t:= f(n/2) // 1 asignacion
		t:= t + f(n/2) // 1 asignacion
		for i:= 1 to n do
			for j:= 1 to n do // nxn asignaciones
				t:= t+1
			od
		od
	fi
end fun 

O(n2)

/*
Realizar un algoritmos que dado un elemento e que no pertenece al array, ubique los
menores a e al coienzo del arreglo y devolver la canrtidad de menores a e

utilizar proc p(in/out a:array[1..n] of Int, in e, out k: nat)
*/

proc p(in/out a: array[1..n] of int, in e: int, out k: nat)
  var i, j: nat
  k := 1  // índice donde irá el próximo menor a e

  for i := 1 to n do
      if a[i] < e then
          swap a[i], a[k]
          k := k + 1
      fi
  od

  k := k - 1  // porque al final k apunta a la posición siguiente
end proc

```

## Ordenar

## ✅ 1. **`[7,20,4,6,2,15]` con Quick Sort**

Y además mostrar las **llamadas recursivas** a `quick_sort_rec(arr, low, high)`.

Supongamos que el algoritmo de `quick_sort` elige como pivote el **último elemento** del subarreglo (`arr[high]`).

### 🔢 Paso a paso:

### Llamada inicial:

```c
quick_sort_rec([7,20,4,6,2,15], 0, 5)
Pivote: 15
```

**Partición (menores a izquierda, mayores a derecha)**:

→ `[7, 4, 6, 2, 15, 20]`

Posición final del pivote: índice **4**

### Llamadas recursivas:

- `quick_sort_rec([7,4,6,2,15,20], 0, 3)`
    - Pivote: 2 → `[2,4,6,7,...]`, pivote en índice 0
    - Llamadas:
        - `quick_sort_rec(..., 0, -1)` ← fin (caso base)
        - `quick_sort_rec([4,6,7], 1, 3)`
            - Pivote: 7 → `[4,6,7]`, pivote en índice 3
            - Llamadas:
                - `quick_sort_rec([4,6], 1, 2)`
                    - Pivote: 6 → `[4,6]`, pivote en 2
                    - Llamadas:
                        - `quick_sort_rec(..., 1, 1)` ← fin
                        - `quick_sort_rec(..., 3, 2)` ← fin
                - `quick_sort_rec(..., 4, 3)` ← fin
- `quick_sort_rec(..., 5, 5)` ← fin

```c
quick_sort_rec(arr, 0, 5)
  ├─ quick_sort_rec(arr, 0, 3)
  │   ├─ quick_sort_rec(arr, 0, -1)
  │   └─ quick_sort_rec(arr, 1, 3)
  │       ├─ quick_sort_rec(arr, 1, 2)
  │       │   ├─ quick_sort_rec(arr, 1, 1)
  │       │   └─ quick_sort_rec(arr, 3, 2)
  │       └─ quick_sort_rec(arr, 4, 3)
  └─ quick_sort_rec(arr, 5, 5)
```

## ✅ 2. **`[3,17,2,10,5,8,3]` con Selection Sort**

### Paso a paso:

En Selection Sort, en cada paso se busca el mínimo del resto del arreglo y se lo intercambia con el actual.

1. `[3,17,2,10,5,8,3]` → mínimo de `3..3` es `2`
    
    → swap con `3` → `[2,17,3,10,5,8,3]`
    
2. `[2,17,3,10,5,8,3]` → mínimo de `17..3` es `3`
    
    → swap con `17` → `[2,3,17,10,5,8,3]`
    
3. `[2,3,17,10,5,8,3]` → mínimo de `17..3` es `3`
    
    → swap con `17` → `[2,3,3,10,5,8,17]`
    
4. `[2,3,3,10,5,8,17]` → mínimo de `10..17` es `5`
    
    → swap con `10` → `[2,3,3,5,10,8,17]`
    
5. `[2,3,3,5,10,8,17]` → mínimo de `10..17` es `8`
    
    → swap con `10` → `[2,3,3,5,8,10,17]`
    
6. `[2,3,3,5,8,10,17]` → ya está ordenado

## TADs

Se requiere desarrollar el software de un GPS para mapas de ciudades conformadas por manzanas cuadradas de 100 metros de lado y cuyas calles son todas doble mano. El GPS dara indicaciones al finalizar cada cuadra con las siguientes posibilidades: **continue recto, gire a la derecha, llego a destino.** Un recorrido entonces consiste de una secuencia de indicaciones

Para ello definir un TAD recorrido que contendra las indicaciones del GPS para ir de una esquina de la ciudad hasta otra. Un recorrido trivial sera el que consta de ir de una esquina a otra, por lo cual el GPS dira **llego a destino**. Un ejemplo interesante seria: **continue recto, continue recto, gire a la izquierda, gire a la derecha, llego a destino**. Un recorrido entonces consiste de una secuencia de indicaciones

Se encesita tambien que una vez realizada una accion restante se actualice. Para ello, se introducen las operaciones **actualizar continuando recto, actualizar girando a la izquierda, actualizar girando a la derecha**, que en caso de coincidir con lo idnicado por el recorrido se limitara a eliminar del mismo la indicacion ejecutada, pero en caso de no coincidir debera recalcular el recorrido para llegr al destino originial

Tambien se requieren operaciones que devuelvan un booleano para saber si la siguiente indicacion de un recorrido es continuar recto doblar a la derecha o izquierda o llegar a destino

1. Espcecificar el TAD recorrido con los constructores correspondientes, las tres operaciones de actualizaciopn, las cuatro de consulta y una operacion longitud que devuelva en metros la longitud de un recorrido
2. Implementar el TAD Recorrido utilizando una lista de elemenots de tipos **Indicacion**, donde el tipo indicacion debera definirse como un enumerado de 3 elementos: Striaght, left, right
3. Usando el TAD recorrido Implementa una funcion que dado un recorrido devuelva uin natural indicando cuantas veces se debe doblar a la izquierda

```c
spec Recorrido where

constructores
	fun crear_recorrido() ret r: recorrido
	{- Crea un recorrido vacio -}
	
	proc agregar_indicacion(in/out r: recorrido, in i: indicacion)
	{- Agrega la indicacion i al recorrido r -}
	
destroy
	proc destroy_recorrido(in/out r: recorrido)
	{- Libera memoria en caso de que sea necesario
	
operaciones
	fun es_vacio(r: recorrido) ret b: bool
	{- Devuelve si un recorrido es o no vacio -}
	
	fun proxima_indicacion(r: recorrido) ret i: indicacion
	{- Devuelve la proxima indicacion -}
	{- PRE: not es_vacio -}
	
	proc actializar_recto(in/out r: recorrido)
	{- Si la poxima es recta la elimina, si no recalcula -}
	{- PRE: not is_vacio -}
	
	proc actializar_right(in/out r: recorrido)
	{- Si la poxima es derecho la elimina, si no recalcula -}
	{- PRE: not is_vacio -}
	
	proc actializar_left(in/out r: recorrido)
	{- Si la poxima es left la elimina, si no recalcula -}
	{- PRE: not is_vacio -}
	
	fun es_recto(r: recorrido) ret b: bool
	{- Retorna true si la prioxima es recta -}
	{- PRE: not is_vacio -}
	
	fun es_right(r: recorrido) ret b: bool
	{- Retorna true si la prioxima es derecha -}
	{- PRE: not is_vacio -}
	
	fun es_left(r: recorrido) ret b: bool
	{- Retorna true si la prioxima es left -}
	{- PRE: not is_vacio -}
	
	fun es_destino(r: recorrido) ret b: bool
	{- Retorna true si la prioxima es recta -}
	{- PRE: not is_vacio -}
	
	fun long(r: recorrido) ret n: nat
	{- Devuelve la distancia del recorrido en metros -}
	
	
Implemrn Recorrido of T where

type Recorrido = List of Indicacion

type Indicacion = enumerate
										straight 
										left 
										right
										destination
									end enumerte	
									
fun crear_recorrido() ret r: recorrido
	r:= empty_list()
end fun

proc agregar_indicacion(in/out r: recorrido, in i: indicacion)
	addr(r, i)
end proc

proc destroy_recorrido(in/out r: recorrido)
	destoy_list(r)
end proc

fun es_vacio(r: recorrido) ret b: bool
	b:= is_empty(r)
end fun

fun proxima_indicacion(r: recorrido) ret i: indicacion
	i:= head(r)
end fun

{- PRE: not is_vacio -}
proc actualizar_recto(in/out r: recorrido)
	if head(r) = straight then
		tail(r)
	else 
		r:= empty()
		addr(r, destination)
	fi
end proc

{- PRE: not is_vacio -}
proc actializar_right(in/out r: recorrido)
	if head(r) = right then
		tail(r)
	else 
		r:= empty()
		addr(r, Destination)
	fi
end proc
		
{- PRE: not is_vacio -}
proc actializar_left(in/out r: recorrido)
	if head(r) = left then
		tail(r)
	else 
		r:= empty()
		addr(r, Destination)
	fi
end proc

{- PRE: not is_vacio -}
fun es_recto(r: recorrido) ret b: bool
	b:= head(r) = striaght
end fun

{- PRE: not is_vacio -}
fun es_right(r: recorrido) ret b: bool
	b:= head(r) = right
end fun

{- PRE: not is_vacio -}
fun es_left(r: recorrido) ret b: bool
	b:= head(r) = left
end fun

{- PRE: not is_vacio -}
fun es_destino(r: recorrido) ret b: bool
	b:= head(r) = destination
end fun

fun long(r: recorrido) ret n: nat
	var tmp: Recorridotmp:= copy_list(r)
	n:= 0
	while not is_empty(r) & head(tmp) != desitination do
		n:= n+100
		tail(tmp)
	od
end fun
```