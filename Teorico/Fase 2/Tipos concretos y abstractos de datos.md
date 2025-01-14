# Tipos concretos y abstractos

Tipos de datos

- Enumerados
- Tuplas
- Arrays
- Punteros

Distinguimos dos clases de tipos de datos:

- Tipos **concretos:**
    - son nativos, o sea, provistos por el lenguaje de programacion
    - dependen del lenguaje de programacion
    - Por ej: enteros, char, strinf, booleanos, arreglos, etc
- Tipos **abstractos**:
    - surgen de analizar un problema a resolver, siendo asi un concepro independiente del lenguaje de programacion
    - Eventualmente se implementan usando tipos concretos, eso da lugar a una implementacion o repersentacion del tipo abstracto

# Tipos concretos

## Enumerado

Consiste de una serie finita de constantes, que seran los unicos elementos del tipo. En nuestro lenguaje el programador puede definit un nuevo tipo enumeradp de la siguiente forma:

```c
type E = enumerate 
		elem1
		elem2
		...
end enumerate
```

En C:

```c
typedef enum {
    ELEM1,
    ELEM2,
    // ...
} E;

```

El tipo E tiene unicamente los k elementos elem1, …, elemk

En un programa se puede decalarar una variable del tipo enumerado E:

```c
var e: E
e:= elem2
```

Tambien se permiten ciclos for donde el indice tome los valores de un tipo enumerado

```c
for i:= elem1 to elemk do ... od
```

## Tuplas

Las tuplas representan productos cartesianos de distintos tipos. Se puede definir un nuevo tipo mediante una tupla de la siguiente manera:

```c
type person = tuple 
		name: string
		age: nat
		weight: real
	    end tuple
```

En C: 

```c
typedef struct {
    char name[100];
    unsigned int age; 
    float weight;
} Person;

```

Para acceder a los campos de una tupla se utiliza el operador . 

```c
var manu: person
manu.name:= "manu"
manu.age:= 20
manu.weight:= 68
```

## Arrays

Los arreglos son colecciones de elementos del mismo tipo de tamaño fijo

```c
var a:array[1..n]

// Tambien pueden ser multidimensionales

var b:array[1..n,1..m] // Se piensa como una matriz 2x3

var c:array[1..n,'a'..'z',1..m]

// Para inicializar el arreglo c lo puedo hacer con 3 for anidados
for i:= m to n do
	for k:= 'a' to 'z' do
		for d:=1 to m do
			c[i,k,d]:= 0
		od
	od
od
```

## Punteros

Dado un tipo T, un **puntero a T** es un tipo de datos que representa el lugar de memorua donde esta alojado el elemento de tipo **T**

Por ejemplo se puede declarar un puntero a nat asi:

```c
var p: pointer to nat
```

En C:

```c
unsigned int *p;
```

Mediante punteros podemos manipular la memoria disponible al ejecutar el programa

- Para reservar un nuevo bloque se utiliza alloc(p)
- Puedo acceder al valor del bloque de memorua mediante la operacion *: *p:= 10, decimos que p *apunta* al valor 10
- Para liberar el bloquede memoria se utiliza free(p), luego de realizar el free, p ya no apunta a un bloque de memoria reservado por el programa, por lo cual no se puede saber que valor tiene la expresion *p
- Existe una constante para representar punteros que no apuntan a nada, p:= **null**

# Tipos abstractos

## Especificacion de TADs

Para especificar un TAD debemos: 

- Indicar su nombre
- Especificar constructores: procedimientos o funciones mediante los cuales puedo crear elementos del tipo que estoy especificando
- Especificar operaciones: procedimientos o funciones que permitiran manipular los elemenos del TAD
- Algunas operaciones tendran **precondiciones**
- Especificar la operacion destruccion que libera la memoria utilizada por los elementos del tipo

## Implementacion de TADs

Para implementar un TAD debemos:

- Definir un nuevo tipo con el nombre del TAD especificado, se utilizan tipos concretos
- Implementar cada constructor
- Implementar cada operacion
- Puedo necesitar operaciones auxiliares

# TAD Listas

![https://saberpunto.com/wp-content/uploads/lista-enlazada.webp](https://saberpunto.com/wp-content/uploads/lista-enlazada.webp)

### Especificacion de Listas

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

### Implementacion de las listas mediante punteros

```c
implement List of T where

type Node of T = Tuple
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

{- PRE: !is_empty(l) -}
fun head(l: List of T) ret e: T
	e:= l->elem
end fun

{- PRE: !is_empty(l) -}
proc tail(in/out l: List of T)
	var p: pointer to (Node of T)
	p:= l
	l:= l->next
	free(p)
end proc

proc addr(in/out l: List of T, in e: T)
	var p,q: pointer to (Node of T)
	alloc(q)
	q->elem:= e
	q->next:= null
	if !is_empty(l) then
		p:= l
		while p->next != null do
			p:= p->next
		od
	else l:= q
	fi
end proc

fun length(l: List of T) ret n:nat
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
	if (l = null && l0 != null) then
		l:= l0
	else 
		p:= l
		// Busco el ultimo nodo asi concateno l0 al final de l
		while (p->next != null) do
			p:= p-next
		od
		p->next:= l0 // Final de l
	fi
end proc

{-PRE: length(l) > n -}
fun index(l: List of T, n: nat) ret e: T
	var p: pointer yo (Node of T)
	p:= l
	if n > 1 then
		for i:= 1 to n-1 do
			p:= p->next
		od
	else
		e:= p-elem
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

Ejemplo de uso del TAD Lista

```c
fun promedio(l: List of float) ret r: float
	var largo: nat
	var elem: float
	var laux: List of float
	
	largo:= length(l)
	r:= 0.0
	laux:= copy_list(l)
	
	while not is_empty(laux) do
		elem:= head(laux)
		r:= r + elem
		tail(laux)
	od
	destroy(laux)
	r:= r/largo
end fun
```

# TAD contador

Solo necesitamos algo que se pueda:

- inicializar
- incrementar
- comprobar si su valor es el incial
- decrementar si no lo es

## Especificacion del TAD contador

```c
spec Counter where

constructors
	fun init() ret c: Counter
	{- Crea un contador inicial -}
	
	proc incr(in/out c: Counter)
	{- Incrementa el contador c -}
	
destroy
	proc destroy(in/out c: Counter)
	{- Libera memoria en caso de que sea necesario -}
	
operations
	fun is_init() ret b: bool
	{- Devuelve true si el contador esta inicalizado -}
	
	proc decr(in/out c: Counter)
	{- Decrementa el contador c -}
	{- PRE: !is_init(c) -}
```

## Implementacion del TAD Contador

```c
implement Counter where

type Counter = nat

proc initi(in/out c: Counter)
	c:= 0
end proc

proc inc(in/out c: Counter)
	c:= c + 1
end proc

fun is_init(c: Counter) ret b: bool
	b:= (c = 0)
end fun

{- PRE: !is_init(c) -}
proc dec (in/out c: Counter)
	c:= c - 1
end proc

proc destroy (in/out c: Counter)
	skip
end proc
```

### Algoritmo de parentesis balanceados:

Basicamente el algoritmo busca si los parentesis estan balanceados o no, el resultado deberia ser counter = 0 y b = true

- Si se encuentra un ‘(’ se incrementa el contador, y si encontramos un ’)’ se decrementa
- Si el contador es incial y encuentro ‘)’ devuelvo false, si termino de recorrer y el contador no es inicial tambien devuelvo false

```c
fun matching_parentesis(a:array[1,,n] of char) ret b: bool
	var i: nat
	var c: Counter
	b:= true
	i:= 1
	while i <= n && b = true do
		if a[i] = '(' then
			inc(c)
		else if a[i] = ')' && is_init(c) then
			b:= false
		else if a[i] = ')' && !is_init(c}) then
			dec(c)
		fi
		i:= i + 1
	od
	b:= b && is_init(c)
	destroy(c)
end proc
```

# TAD Pila

La pila se define por 5 operaciones:

- Inicializar vacia
- Comprobar si esta vacia
- Apilar un nuevo elemento
- Examinar el primer elemento (si no es vacia)
- Quitar el elemento

![https://upload.wikimedia.org/wikipedia/commons/thumb/d/d1/Pila.svg/1200px-Pila.svg.png](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d1/Pila.svg/1200px-Pila.svg.png)

## Especificacion del TAD Pila

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

# TAD Cola

Imaginemos cualquier situacion en que ciertos datos deben transferirse de una unidad a la otra, por ejemplo, datos que se quieren subir a algun sitio de internet desde un disco. Un agente suministra o producuce datos (el disco) y otro que los utiliza los consume (el sitio de internet). Para amortiguar el impacto por diferencia de velocidades, se introduce un buffer entre ellos, un buffer recibe y almacena los datos a medida que se producen, emitiendolos en el mismo orden a medida que son solicitados.

Esto se puede solucionar usando una **Cola.** Una cola se puede:

- Inicializar vacia
- Agregar o encolar un dato
- Comprobar si quedan datos en el buffer, es decir si esta vacia
- Examinar el primer dato
- Quitar o decolar un dato

El primer dato que se agrego, es el primer que debe enviarse y quitarse de la cola, usa una politica **FIFO** (first in/ first out)

[https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSJa2pjGMLLOk9ulj_BhcCnTc6FvMEUMsA3CA&s](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSJa2pjGMLLOk9ulj_BhcCnTc6FvMEUMsA3CA&s)

## Especifiacion del TAD Cola

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
