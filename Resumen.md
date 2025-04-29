# Algoritmos de ordenación

## Selection sort

Selecciona el menor elemento de todos, lo intercambia con el que se encuentra en la primer posición, luego selecciona el segundo menor elemento del arreglo y lo intercambia con la segunda posición, y asi hasta que el arreglo este ordenado

Tiene una complejidad temporal de O(n²)

```c
proc selection_sort(in/out a:array[1..n] of T)
	var min: nat
	for i:= 1 to n-1 do 
		min:= min_pos_from(a,i)
		swap(a,i,min)
	od
end proc

fun min_pos_from(a:array[1..n], i: nat) ret min: nat
	min:= i
	for j:= i+1 to n do
		if a[j] < a[min] then
			min:= j
		fi
	od
end fun

proc swap(in/out a:array[1..n] of T, in i,j: nat)
	var tmp: T
	tmp:= a[i]
	a[i]:= a[j]
	a[j]:= tmp
end proc
```

- selection_sort con un for desde 1 a n-1 (pos. n ya ordenada), llama a min_pos_from para elegir al mínimo de la parte no ordenada y con swap los intercambia
- min_pos_from elije la posicion del mínimo de un arreglo desde una posición dada
- swap intercambia dos valores de un arreglo dada las posiciones

### Ordenando

[9, 1, 6, 3, 8, 5]  

Busco al minimo desde la posicion 0 a la 5: el minimo es 1

Intercambio 9 y 1

[1, 9, 6, 3, 8, 5]

Busco el minimo desde la posicion 1 a la 5: el minimo es 3

Intercambio 9 y 3

[1, 3, 6, 9, 8, 5]

Busco el minimo desde la posicion 2 a la 5: el minimo es 5

Intercambio 6 y 5

[1, 3, 5, 9, 8, 6]

Busco el minimo desde la posicion 3 a la 5: el minimo es 6

Intercambio 9 y 6

[1, 3, 5, 6, 8, 9]

Busco el minimo desde la posicion 4 a la 5: el minimo es 8

No intercambio porque ya esta en su posicion

Solo queda el elemento de la ultima posicion, por lo tanto el arreglo ya esta ordenado 

## Insertion sort

Cada elemento menor se inserta en su lugar correspondiente 

Tiene una complejidad temporal de O(n²)

```c
proc insertion_sort(in/out a:array[1..n] of T)
	for i:= 2 to n do
		insert(a,i)
	od
end proc

proc insert(in/out a:array[1..n] of T, in i: nat)
	var j: nat
	j:= i
	while j > 1 && a[j] < a[j-1] then
		swap(a,j-1,j)
		j:= j-1
	od
end proc

proc swap(in/out a:array[1..n] of T, in i,j: nat)
	var tmp: T
	tmp:= a[i]
	a[i]:= a[j]
	a[j]:= tmp
end proc
```

### Ordenando

[9, 1, 6, 3, 8, 5]

Indice 1, valor 1:

1 es menor que 9, asi que muevo 9 a la derecha y 1 en la posicion 0

[1, 9, 6, 3, 8, 5]

Indice 2, valor 6

6 es menor que 9, muevo 9 a la derecha y se inserta 6 en la posicion 1

[1, 6, 9, 3, 8, 5]

Indice 3, valor 3

3 es menor que 9, muevo 9 a la derecha

3 es menor que 5, muevo 6 a la derecha

3 es mayor que 1 por lo que se inserta en la posicion 1

[1, 3, 6, 9, 8, 5]

Inidice 4, valor 8

8 es menor que 9, muevo 9 a la derecha

8 es mayor que 6, por lo que se inserta en la posicion 3

[1, 3, 6, 8, 9, 5]

Indice 5, valor 5

5 es menor que 9, muevo 9 a la derecha

5 es menor que 8, muevo 8 a la derecha

5 es menor que 6, muevo 6 a la derecha

5 es mayor que 3, por lo que se inserta en la posicion 2

[1, 3, 5, 6, 8, 9]

## Quick sort

Se elige un elemento del array como **pivote**. El pivote puede ser cualquier elemento del array (aleatorio).

El proceedimiento **partition** reorganiza de manera de que todos los elemento menores al pivote se mueven a la izquierda y los mayores a la izquierda. Esto genera dos subarrays 

Luego se aplica partition recursivamente a los dos subarrays, y se aplica recursivamente hasta que los subarrays tengan un solo elemento o esten vacios, momento en el que el array está ordenado

Tiene una complejidad temporal de O(n log n)

```c
// Me devuelve la posicion del pivot (con sus subarrays)
proc partition(in/out a:array[1..n] of T, in lft,rgt: nat)
	 var i,j: nat
	 piv:= lft
	 i:= lft+1
	 j:= rgt
	 while i <= j do
		 if a[i] <= a[piv] then
			 i:= i+1
		else if a[j] >= a[piv] then
			j:= j-1
		else if a[i] > a[piv] && a[j] < a[piv] then
			swap(a,i,j)
			i:= i+1
			j:= j-1
		fi
	od
	swap(a,piv,j)
	piv:= j
end proc

proc quick_sort_rec(in/out a:array[1..n] of T, in lft,rgt: nat)
	var piv: nat
	if rgt > lft then
		partition(a, lft, rgt, piv) // Me devuelve posicion del pivot
		quick_sort_rec(a, lft, piv-1)
		quick_sort_rec(a, piv+1, rgt)
	fi
end proc

proc quick_sort(in/out a:array[1..n] of T)
	quick_sort_rec(a,1,n)
end proc
```

### Ordenando

[9, 1, 6, 3, 8, 5]

Primera llamada:

- pivote = 5
- Particion:
    - 9 > 5, no hago nada
    - 1 < 5, lo muevo adelante [1, 9, 6, 3, 8, 5]
    - 6 > 5 no hago nada
    - 3 < 4, lo muevo adelante [1, 3, 6, 9, 8, 5]
    - 8 > 5, no hago nada
- Pongo el pivote en su lugar (swap 6 y 5)

[1, 3, 5, 9, 8, 6]

Se aplica quick sort recursivamente

- 1° subarray: [1, 3]
    - pivote = 3
    - 1 < 3, todo bien
    
    - ya esta ordenado
- 2° subarray: [9, 8, 6]
    - pivote = 6
    - 9 > 6, no hago nada
    - 8 > 6, no hago nada
- Pongo el pivote en su lugar (swap 9 y 6)

Aplico quick sort en [8, 9]

- pivote = 9
- 8 < 9, todo bien
- ya esta ordenado

Resultado final [1, 3, 5, 6, 8, 9]

# Divide y venceras

## Binary search

La búsqueda binaria es un algoritmo eficiente para **encontrar un elemento en una lista ordenada de elementos**.

Tiene una complejidad temporal de O(log n)

```c
fun binary_search_rec (a:array[1..n] of T, x:T, lft, rgt: nat) ret i:nat
		var mid: nat
		if lft > rgt then
				i:= 0
		else if lft <= rgt then
				mid:= (lft+rgt)/2
				if x < a[mid] then
						i:= binary_search_rec(a, x, lft, mid-1)
				else if x = a[mid] then
						i:= mid
				else if x > a[mid] then
						i:= binary_search_rec(a, x, mid+1, rgt)
				fi
		fi
end fun

fun binary_search (a:array[1..n] of T, x:T) ret i:nat
		i:= binary_search_rec(a, x, 1, n)
end fun
```

# Tipos concretos

## Enumerado

Consiste en una serie finita de constantes, que seran los unicos elementos del tipo

```c
// Definicion del enumerado
// elem1,...,elemk
type e = enumerate
					elem1
					elem2
					...
end enumerate

// Definicion de variables
var e: E
e:= elem2

// Se recorre de esta forma
for i:= elem1 to elemk do ... od
```

## Tuplas

Las tuplas representan productos cartesianos de disntintos tipos

```c
// Definicion de la tupla
type person = tuple
								name: string
								age: nat
								weight: float
							end tuple

// Acceso a los campos de las tuplas
var lucas: person
lucas.name:= "Lucas"
lucas.age:= 22
lucas.weight:= 88
```

## Arrays

Los arreglos son colecciones de elementos del mismo tipo

```c
// Arreglo unidimensional
var a:array[1..n]

// Arreglo mulitdimensional
var b:array[1..n,1..m]
var c:array[1..n,'a'..'z',1..m]

// Iniciar y recorrer los arreglos
for i:= m to n do
	for k:= 'a' to 'z' do
		for d:= 1 to m do
			c[i,k,d]:= 0
		od
	od
od
```

## Punteros

Dado un tipo T, un **puntero** a T es un tipo de datos que representan el lugar de memoria donde esta alojado el elemento de tipo T

```c
var p: pointer to nat

// Reservar un nuevo bloque
alloc(p)
// Acceder a un bloque de memoria
*p:= 10 // p apunta al valor 10
// Liberar el bloque de memoria
free(p)
// Representar punteros que no apuntan a nada
p:= null
```

# Tipos abstractos

### Especificación de TADs

Para **especificar** un nuevo TAD debemos:

- Indicar su **nombre**
- **Especificar constructores:** procedimientos o funciones mediante los cuales puedo crear elementos del tipos que estos especificando
- **Especificar opercaciones:** procedimientos o funciones que permitiran manipular los elementos del TAD
- Algunas operaciones tendran **precondiciones**
- Especificar la operacion **destruccion** que libera memoria en caso de que sea necesario

### **Implementacion de TADs**

Para **implementar** un TAD debemos:

- Definir un nuevo tipo con el **nombre del TAD** especificado, se utilizan **tipos concretos**
- Implementar cada **constructor**
- Implementar cada **operacion**
- Puedo necesitar **operaciones auxiliares**

## TAD Lista

### Especificacion de listas

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
```

### Implementacion de listas enlazadas (punteros)

```c
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
	var p: pointer to (Node of T)
	alloc(p)
	p->elem:= e
	p->next:= l
	l:= p
end proc

fun is_empty(l: List of T) ret b: bool
	b:= l = null
end fun

{- PRE: !is_empty -}
fun head(l: List of T) ret e: T
	e:= l->elem
end fun

{- PRE: !is_empty -}
proc tail(in/out l: List of T)
	var p: pointer to (Node of T)
	p:= l
	l:= l->next
	free(p)
end proc

{- PRE: !is_empty -}
proc addr(in/out l: List of T)
	var p,q: pointer to (Node of T)
	alloc(q)
	q->elem:= e
	q->next:= null
	if !is_empty(l) then
		p:= l
		while p->next != null do
			p:= p->next
		od
	else 
		l:= q 
	fi
end proc

fun length(l: List of T) ret n: nat
	var p: pointer to (Node of T)
	n:= 0
	p:= l
	while p != null do
		n:= n+1
		p:= p->next
	od
end fun

proc concat(in/out l: List of T, in l0: List of T)
	var p: pointer to (Node of T)
	if l = null && l0 != null then
		l:= l0
	else 
		p:= l
		// Busco el ultimo nodo asi concateno l0 al final de l
		while p->next != null do
			p:= p->next
		od
		p->next:= l0 // Final de l
	fi
end proc

fun index(l: List of T, in n: nat) ret e: T
	var p: pointer to (Node of T)
	p:= l
	if n > 1 then 
		for i:=1 to n-1 do
			p:= p->next
		od
	else 
		e:= p->elem
	fi
	e:= p->elem
end fun

proc take(in/out l: List of T, in n: nat)
	var p,q: pointer to (Node of T)
	var i: nat
	i:= 0
	if l!= null then
		if n = 0 then
			while l != null do
				p:= l
				l:= l->next
				free(p)
			od
		else if 0 < n then
			p:= l
			// Busco el primer elemento a eliminar
			while l != null && i < n do
				p:= p->next
				i:= i+1
			od
			// Elimino los elemnentos
			while p != null do
				q:= p
				p:= p->next
				free(q)
			od
		fi
	fi
end proc

proc drop(in/out l: List of T, in n: nat)
    var p: pointer to (Node of T)
    var i: nat
    i:= 0
    if (l ≠ null ^ 0 < n) then
        while (l ≠ null ^ i < n) do
            p:= l
            l:= l->next
            free(p)
            i:= i + 1
        od
    fi
end proc

fun copy_list(l1: List of T) ret l2: List of T
  var p: pointer to (Node of T)
  var n: nat
  n:= length(l1)
  if (l1 = null) then l2:= empty_list()
  else
      p:= l1
      alloc(l2)
      for i:= 1 to n do
          l2->elem = p->elem
          l2->next = p->next
          p:= p->next
      od
  fi
 end fun
```

## TAD Pila

### Especificicion del TAD Pila

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
```

## TAD Cola

### Especificicion del TAD Cola

```c
spec Queue of T where

constructors
	fun empty_queue() ret q: Queue of T
	{- Crea una cola vacia -}
	
	proc enqueue(in/out q: Queue of T, in e: T)
	{- Agrega el elemento e al final de la cola q -}

operations
	fun is_empty_queue(q: Queue of T) ret b: Bool
	{- Devuelve True si la lista es vacia -}
	
	fun first(q: Queue of T) ret e: T
	{- Devuelve el elemento que se encuentra al comienzo de q -}
	{- PRE: !is_empty_queue(q) -}
	
	proc dequeue(in/out q: Queue of T)
	{- Elimina el elemento que se encuentra al comienzo de q -}
	{- PRE: !is_empty_queue(q) -}
```

### Algoritmo de transferencia de datos con buffer

```c
proc buffer ()
	var d: data
	var q: queue of data
	empty_queue(q)
	while !finish() do
		if there_is_product() then
			d_= get_product()
			enqueue(q,d)
		else if there_is_demand() && !is_empty(q) then
			d:= first(q)
			consume(d)
		fi
	od
end proc
```

# Arboles binarios de busqueda

Un árbol binario es una estructura de datos que consiste en nodos que almacenan un elemento y dos subestructuras, que a la vez pueden ser otro nodo, o vacío

**Constructores**: 

- Árbol vacío
- Nodo consistente de un elemento de algún tipo T y dos arboles

**Botánica y genealogía**: en la foto podemos ver un nodo

- Un **nodo** es un árbol no vacío
- Tiene **raíz, subarbol izquierdo y subarbol derecho**
- A los subarboles se los llama **hijos** (izquierdo y derecho)
- Y al nodo se le dice **padre** de sus hijos
- Una hoja es un nodo con los dos hijos vacios
- Se define **camino, altura, profundidad y nivel**

**Niveles**: 

- En el nivel 1 hay a lo sumo 1 nodos
- En el nivel 2 hay a lo sumo 2 nodos
- En el nivel 3 hay a lo sumo 4 nodos
- En un árbol de altura n hay a lo sumo
    
    2ˆ0 + 2ˆ1 + … 2ˆ(n-1) = 2ˆn - 1 nodos
    

Podemos recorrer un árbol indicando el camino desde la raíz.

Un camino lo podemos representar como una secuencia donde cada elemento nos indica si debo bajar a la izquierda o a la derecha

# Especificación del TAD árbol binario

```c
type Direction = enumerate
											left
											right
								 end enumerate
								 
type Path =  List of Direction

spec Tree of T where 

constructors
	fun empty_tree() ret t: Tree of T
	{- crea un arbol vacio -}
	
	fun node(tl: Tree od T, e: T, tr: Tree of T)
																ret t: Tree of T
	{- crea un nodo con el elemento e y los subarboles tl y tr -}

operations
	fun is_empty_tree(t: Tree of T) ret b: bool
	{- devuelve true si el arbol es vacio -}
	
	fun root(t: Tree of T) ret e: T
	{- deuelve el elemento que se encuentra en 
		 la raiz de t -}
	{- PRE: not is_empty_tree(t) -}
	
	fun left(t: Tree of T) ret tl: Tree of T
	{- devuelve el subarbol izquierdo de t -}
	{- PRE: not is_empty_tree(t) -}

	fun right(t: Tree of T) ret tl: Tree of T
	{- devuelve el subarbol derecho de t -}
	{- PRE: not is_empty_tree(t) -}

	fun height(t: Tree of T) ret n: nat 	
	{- Devuelve la distancia que haye entre la raiz
		 de t y la hoja mas profunda -}
	
	fun is_path(t: Tree of T, p: Path) ret b: bool
	{- devuelve true si p es un camino valido de t -}
	
	fun subtree_at(t: Tree of T, p: Path) ret e: T
	{- devuelve el elemento que se encuentra al
		 recorrer el camino p en t -}
	{- PRE: is_path(t,p) -}	
	
implement Tree of T where

type Node of T = tuple
								left: pointer to (Node of T)
								value: T
								right: pointer to (Node of T)
								 end tuple

type Tree od T = pointer to (Node of T)

fun empty_tree() ret t: Tree of T
	t:= null
end fun					 

fun node(tl: Tree of T, e: T, tr: Tree of T)
															ret t: Tree of T
	alloc(t)
	t->value:= e
	t->left:= tl
	t->right:= tr
end fun
```

# Arboles binarios de búsqueda

- Son casos particulares de arboles binarios
- Son arboles binarios en donde la informacion esta organizada de forma tal que el siguiente algoritmo permite buscar de forma eficiente un elemento:
    - El elemento buscado se compara con la raíz de t
        - Si es el mismo, la búsqueda finaliza
        - Si es menor que la raíz, la búsqueda se restringe al subarbol izquierdo de t con el mismo algoritmo
        - Si es mayor que la raíz, la búsqueda se restringe al subarbol derecho t con el mismo algoritmo
- Si el árbol esta “balanceado”, es un algoritmo logaritmico

Para que este algoritmo funcione, t debe cumplir lo siguiente:

- Los valores alojados en el subarbol izquierdo de t deben ser menores que el alojado en la raíz de t
- Los valores alojados en el subarbol derecho de t deben ser mayores que el alojado en la raíz de t
- Estás dos condiciones deben darse para todos los subarboles de t

Si se cumplen estas condiciones, decimos que t es un árbol **binario de búsqueda,** o **ABB**

### Agregar un elemento en un ABB

Si quiero agrega un elemento e a un ABB t de manera de mantener la propiedad debo realizar el siguiente procedimiento recursivo:

- Si t es vacío, formo el nodo que consta del elemento e y los dos subarboles vacios
- En caso contrario, comparo el elemento e con la raíz del árbol t
- Si e es menor que la raíz, lo agrego al subarbol izquierdo
- Si e es mayor o igual que la raíz, lo agrego al subarbol derecho
