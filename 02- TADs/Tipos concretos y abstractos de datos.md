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
