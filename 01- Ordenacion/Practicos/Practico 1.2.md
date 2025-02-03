# Practico 1.2

# Ejercicio 1

a) Ordenar los arreglos del ejercicio 4 del práctico anterior utilizando el algoritmo de **`ordenación por intercalación`**.

- a)
    
    `[7, 1, 10, 3, 4, 9, 5]`
    
    {- divido a la mitad -}
    
    [`7, 1, 10, 3`, `4, 9, 5`]
    
    {- divido a la mitad -}
    
    [`7, 1`, `10, 3`, `4, 9, 5`]
    
    {- divido a la mitad -}
    
    [`7`, `1`, `10`, `3`, `4, 9, 5`]
    
    {- intercalo [7, 1] -}
    
    [**`1, 7`**, `3`, `10`, `4, 9, 5`]
    
    {- intercalo [3, 10] -}
    
    [**`1, 7`**, `3, 10`, `4, 9, 5`]
    
    {- intercalo [1, 7, 3, 10] -}
    
    [**`1, 3, 7, 10`**, `4, 9, 5`]
    
    {- divido a la mitad -}
    
    [**`1, 3, 7, 10`**, `4, 9`, `5`]
    
    {- divido a la mitad -}
    
    [**`1, 3, 7, 10`**, `4`, `9`, `5`]
    
    {- intercalo [4, 9] -}
    
    [**`1, 3, 7, 10`**, `4, 9`, `5`]
    
    {- intercalo [4, 9, 5] -}
    
    [**`1, 3, 7, 10`**, `4, 5, 9`]
    
    {- intercalo las dos mitades -}
    
    [**`1, 3, 4, 5, 7, 9, 10`**]
    
    {- el arreglo está ordenado -}
    
- b)
    
    `[5, 4, 3, 2, 1]`
    
    {- divido a la mitad -}
    
    [`5, 4`, `3, 2, 1`]
    
    {- divido a la mitad -}
    
    [`5`, `4`, `3, 2, 1`]
    
    {- intercalo [5, 4] -}
    
    [**`4, 5`**, `3, 2, 1`]
    
    {- divido a la mitad -}
    
    [**`4, 5`**, `3, 2`, `1`]
    
    {- divido a la mitad -}
    
    [**`4, 5`**, `3`, `2`, `1`]
    
    {- intercalo [3, 2] -}
    
    [**`4, 5`**, `2, 3`, `1`]
    
    {- intercalo [2, 3, 1] -}
    
    [**`4, 5`**, `1, 2, 3`]
    
    {- intercalo las dos mitades -}
    
    [**`1, 2, 3, 4, 5`**]
    
    {- el arreglo está ordenado -}
    

# Ejercicio 2

a) Escribir el procedimiento **`intercalar_cada`** que recibe un arreglo a:**array**[1..2ⁿ] **of int** y un número natural i: **nat**; e intercala el segmento a[1,2ⁱ] con a[2ⁱ+1,2∗2ⁱ], el segmento a[2∗2ⁱ+1, 3∗2ⁱ] con a[3∗2ⁱ+1, 4 ∗2ⁱ], etc. Cada uno de dichos segmentos se asumen ordenados. Por ejemplo, si el arreglo contiene los valores

```
[3, 7, 1, 6, 1, 5, 3, 4];
```

y se lo invoca con i = 1 el algoritmo deberá devolver el arreglo

```
[1, 3, 6, 7, 1, 3, 4, 5]
```

Si se lo vuelve a invocar
con este nuevo arreglo y con i = 2, devolverá

```
[1, 1, 3, 3, 4, 5, 6, 7]
```

El algoritmo

```c
proc intercalar_cada(in/out a:array[1..2ⁿ] of int, in i: int)
	var tam, izq, der, med: nat
	tam:= 2ⁿ
	izq:= 1
	der:= 2ⁱ⁺¹ // Tamaño a mergear
	med:= (izq+der)/2
	while der <= izq
		merge(a, izq, med, der)
		izq:= der + 1
		der:= der + 2ⁱ⁺¹
		med:= (izq+der)/2
	od
end proc 
```

# Ejercicio 3

Ordenar los arreglos con el algoritmos de `ordenacion rapida`

[7, 1, 10, 3, 4, 9, 5]

Elijo el pivot

[**7**, 1, 10, 3, 4, 9, 5]

Comparo

[**7**, *1*, 10, 3, 4, 9, *5*]

El 1 se queda, comparo

[**7**, 1, *10*, 3, 4, 9, *5*]

swap

[**7**, 1, *5*, 3, 4, 9, *10*]

Comparo

[**7**, 1, 5, 3, 4, 9, 10]

Se queda, como no tengo mas que comparar, llevo el pivot a su lugar

[4, 1, 5, 3, 7, 9, 10]

Elijo el pivot mi nuevo pivot

[**4**, 1, 5, 3, **7**, 9, 10]

comparo

[**4**, *1*, 5, *3*, **7**, 9, 10]

comparo

[**4**, 1, *5*, *3*, **7**, 9, 10]

swap

[**4**, 1, 3, 5, **7**, 9, 10]

llevo el pivot a su lugar

[1, 3, 4, 5, 7, 9, 10]

El algoritmo etsa ordenado, pero igual elijo el pivot y comparo pasando por todos los numeros

# Ejercicio 4

Escribir una variante del procedimiento **`partition`** que en vez de tomar el primer elemento del segmento `a[izq, der]`como pivot, elige el valor intermedio entre el primero, el último y el que se encuentra en medio del segmento. Es decir, si el primer valor es 4, el que se encuentra en el medio es 20 y el último es 10, el algoritmo deberá elegir como pivot al último.

```c
proc partition2.0(in/out a:array[1..n], in lft,rgt: nat, out ppiv: nat)
	var i,j,mid: 
	mid:= (rgt+lft)/2
	
	// Busco el pivot
	if(a[lft] <= a[mid] && a[mid] <= a[rgt]) then
		ppiv:= mid
	else if(a[mid] <= a[lft] && a[lft] <= a[rgt]) then
		ppiv:= lft
	else if(a[lft] < a[rgt] && a[rgt] <= a[mid]) then
		ppiv:= rgt
	fi
	
	// Sigo con partition de siempre
	
	while i <= j do 
		if a[i] <= a[ppiv] then 
			i:= i+1
		else if a[j] >= a[ppiv] then 
			j:= j-1
		else if a[i] > a[ppiv] && a[j] < a[ppiv] then
			swap(a,i,j)											    		    
			i:= i+1
		  j:= j+1
		fi
	od
	swap(a,ppiv,j)
	ppiv:= j
end proc
```

# Ejercicio 5

Escribir un algoritmo que dado un arreglo a:**array**[1..n] **of int** y un número natural k ≤ n devuelve el elemento de a que quedaría en la celda a[k] si a estuviera ordenado. Está permitido realizar intercambios en a, pero no ordenarlo totalmente. La idea es explotar el hecho de que el procedimiento **`partition`** del **`quick_sort`** deja al pivot en su lugar correcto.

```c
proc k-esimo(in a:array[1..n] of int, k: nat, out res: nat)
	var izq,der,piv: nat
	izq:= 1
	der:= n
	ppiv:= partition(a, izq, der)
	while(ppiv != k) do
		if(ppiv < k) then
			izq:= ppiv + 1
		else
			der:= ppiv - 1
		fi
	od
	res:= a[k]
end proc
```