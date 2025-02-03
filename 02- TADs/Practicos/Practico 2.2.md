# Practico 2.2

# **Ejercicio 1**

Completar la implementación de listas dada en el teórico usando punteros.

```c
implement List of T where

type Node of T = tuple
                    elem: T
                    next: pointer to (Node of T)
                 end tuple

type List of T = pointer to (Node of T)
```

```c
fun empty_list() ret l: List of T
    alloc(l)
    l:= null
end fun

proc addl (in e:T, in/out l: List of T)
    var p: pointer to (Node of T)
    alloc(p)
    p->elem:= e
    p->next:= l
    l:= p
end proc

proc destroy_list (in/out l: List of T)
    var p: pointer to (Node of T)
    while (l ≠ null) do
        p:= l
        l:= l->next
        free(p)
    od
end proc

fun is_empty(l: List of T) ret b: bool
    b:= (l = null)
end fun

{- PRE: not is_empty(l) -}
fun head(l: List of T) ret e: T
    e:= l->elem
end fun

{- PRE: not is_empty(l) -}
proc tail(in/out l: List of T)
    var p: pointer to (Node of T)
    p:= l
    l:= l->next
    free(p)
end proc

proc addr (in/out l: List of T, in e: T)
    var p,q: pointer to (Node of T)
    alloc(p)
    p->elem:= e
    p->next:= null
    if (l ≠ null) then
        q:= l
        while (q->next ≠ null) do
            q:= q->next
        od
        q->next:= p
    else l:= p
    fi
end proc
{- agrega el elemento e al final de la lista l -}

fun length(l: List of T) ret n: nat
    if (l = null) then n:= 0
    else
        n:= 1 + length(l->next)
    fi
end fun

proc concat(in/out l: List of T,in l0: List of T)
    var p: pointer to (Node of T)
    if (l = null ^ l0 ≠ null) then
        l:= l0
    else
        p:= l
        while (p->next ≠ null do)
            p:= p->next
        od
        p->next:= l0
    fi
end proc

{- PRE: length(l) > n -}
fun index(l: List of T, n: nat) ret e: T
    var p: pinter to (Node of T)
    p:= l
    if (n > 1) then
        for i:= 1 to (n-1) do
            p:= p->next
        od
    fi
    e:= p->elem
end proc

proc take(in/out l: List of T, in n: nat)
    var p,q: pointer to (Node of T)
    var i: nat
    i:= 0
    if (l ≠ null) then
        if (n = 0) then
            while (l ≠ null) do
                p:= l
                l:= l->next
                free(p)
            od
        else if (0 < n) then
            p:= l
            {- busco el primer elemento a eliminar -}
            while (l ≠ null ^ i < n) do
                p:= p->next
                i:= i + 1
            od
            {- elimino los elementos -}
            while (p ≠ null) do
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

# Ejercicio 2

Dada una constante natural N, implementar el TAD Lista de elementos de tipo T, usando un arreglo de tamaño N y un natural que indica cuántos elementos del arreglo son ocupados por elementos de la lista.

```c
implement List of T where

type Node of T = tuple
									size: nat
									elems: array[1..N] of T
								 end tuple

// Creo una lista vacia
fun empty_list() ret l: List of T
	l.size:= 0
end fun

// Agrega el elemento e al comienzo de la lista
{- PRE: l.size < N -}
proc addl (in e: T, in/out l: List of T)
    l.size := l.size + 1
    // Mueve cada elemento un lugar hacia adelante
    for i := l.size - 1 downto 1 do
        l.elems[i + 1] := l.elems[i]
    od
    l.elems[1] := e
end proc

proc destroy_list(in/out l: List of T)
	l.size:= 0
end proc

// Devuelve true si es vacia
fun is_empty(l: List of T) ret b: bool
	b:= l.size = 0
end fun

//Devuelve el primer elemento de la lista l
{- PRE: !is_empty -}
fun head(l: List of T) ret e: T
	e:= l.elems[1]
end fun

// Elimina el primer elemento de la lista l
{- PRE: !is_empty -}
proc tail(in/out l: List of T)
	for i:= 2 to l.size - 1 do
		l.elems[i]:= l.elems[i+1]
	od
	l.size:= l.size - 1
end proc

// Agrega un elemento al final de l
{- PRE: !is_empty -}
proc addr(in/out l: List of T, in e: T)
	l.size:= l.size + 1
	l.elems[l.size]:= e
end proc

// Devuelve el largo de la lista
fun length(l: List of T) ret n: nat
	n:= l.size
end fun

// Devuelve el n-esimo elemento de la lista l
fun index(l: List of T, in n: nat) ret e: T
	e:= l.elems[n]
end fun

// Concateno l y l0 (l0 al final de l)
{- PRE: l.size + l0.size <= N -}
proc concat(in/out l: List of T, in l0: List of T)
	var j: nat
	j:= 1
	l.size:= l.size + l0.size
	for i:= (l.size - l0.size + 1) to l.size do
		l.elems[i]:= l0.elems[j]
		j:= j+1
	od
end proc 

// Deja en l los primeros n elementos, eliminando el resto
{- PRE: n <= N && l.size >= n -}
proc take(in/out l: List of T, in n: nat)
	var tmpl: List of T
	tmpl.size:= n
	for i:= 1 to n do
		tmpl.elems[i]:= l.elems[i]
	od
	l:= tmpl
end proc

{- PRE: n <= N && l.size >= n -}
proc take(in/out l: List of T, in n: nat)
	l.size:= n
end proc

// Elimina los primeros n elementos de l
proc drop(l: List of T, in n: nat)
	var i,j: nat
	i:= 1
	j:= n + 1
	while j <= l.size do
		l.elems[i]:= l.elems[j]
		i:= i + 1
		j:= j + 1
	od
	l.size:= j
end fun

fun copy_list()l: List of T) ret cl: List of T
	cl.size:= l.size
	for i:= 1 to l.size do
		cl.elems[i]:= l.elems[i]
	od
end fun
```

Esta implementacion me limita la cantidad de elementos a N, basicamente pasa de ser una lista a un Array

# Ejercicio 3

Implementar el procedimiento **`add_at`** que toma una `lista de tipo T`, un `natural n`, un elemento `e de tipo T`, y agrega el elemento `e` en la posición `n`, quedando todos los elementos siguientes a continuación.

Esta operación tiene como precondición que n sea menor al largo de la lista.

*AYUDA: Puede ayudarte usar las operaciones copy, take y drop*

```c
proc add_at(in/out l: list of T, in n: nat, in e: T)
// drop elimina los primeros n elementos
// take deja los primeros n elementos 
	var l1: List of T
	l1:= copy_list(l)
	
	drop(l1,n) // Lista sin los primeros n, l1.size:= l1.size - n
	take(l,n) // Lista con los primeros n, l.size:= n
	
	l1.size:= l1.size + 1
	for i:= 1 to l1.size do
		l1.elems[i+1]:= l1.size[i]
	od
	
	l1.elems[1]:= e 
	
	concat(l,l1) // Concateno las listas en l, l.size:= l.size + l1.size

end proc
```

# Ejercicio 4

a) Especificar un TAD **`tablero`** para mantener el tanteador en contiendas deportivas entre dos equipos (equipo A y equipo B). Deberá tener un **constructor** para el comienzo del partido (`tanteador inicial`), un constructor para registrar un `nuevo tanto del equipo A` y uno para registrar un `nuevo tanto del equipo B`. El tablero sólo registra el estado actual del tanteador, por lo tanto el orden en que se fueron anotando los tantos es irrelevante. Además serequiere **operaciones** para comprobar:

- si el tanteador está en cero,
- si el equipo A ha anotado algún tanto,
- si el equipo B ha anotado algún tanto,
- una que devuelva verdadero si y sólo si el equipo A va ganando,
- otra que devuelva verdadero si y sólo si el equipo B va ganando,
- y una que devuelva verdadero si y sólo si se registra un empate.

Finalmente habrá una **operación** que permita:

- anotarle un número n de tantos a un equipo y otra
- que permita “castigarlo” restándole un número n de tantos.

En este último caso, si se le restan más tantos de los acumulados equivaldrá a no haber anotado ninguno desde el comienzo del partido.

```c
spec Tablero where

constructors
	fun tanteado_incial() ret t: Tablero
	{- inicializa el tablero -}
	
	proc tantoA(in/out t: Tablero)
	{- Incrementa el contador del equipo A -}
	
	proc tantoB(in/out t: Tablero)
	{- Incrementa el contador del equipo B -}

destroy
	proc destroy(in/out t: Tablero)
	{- Libera memoria en caso de que sea necesario -}

operations
	fun en0(t: Tablero) ret b: bool
	{- Devuelve true si el tanteador esta en cero -}
	
	fun anotoA(t: Tablero) ret b: bool
	{- Devuelve true si el equipo A anoto -}
	
	fun anotoB(t: Tablero) ret b: bool
	{- Devuelve true si el equipo B anoto -}
	
	fun ganaA(t: Tablero) ret b: bool
	{- Devuelve true si el equipo A gana -}
	
	fun ganaBt: Tablero) ret b: bool
	{- Devuelve true si el equipo B gana -}
	
	fun empate(t: Tablero) ret b: bool
	{- Devuelve true si se registra un empate entre A y B -}
	
	proc sumar n_tantos(in/out t: Tablero, in n: nat, in e: char)
	{- Suma n tantos al equipo e -}
	
	proc sumar n_tantos(in/out t: Tablero, in n: nat, in e: nat)
	{- Resta n tantos al equipo e -}
	
```

b) Implementar el TAD Tablero utilizando una tupla con dos contadores:

- uno que indique los tantos del equipo A, y
- otro que indique los tantos del equipo B.

```c
implement Tablero where

type Tanteador = tuple
									a: Counter
									b: Counter
								 end tuple

type Tablero = tanteador

// Inicializa el tablero
fun tanteado_incial() ret t: Tablero
	t.a:= init(t.a)
	t.b:= init(t.b)
end fun

// Incrementa el contador del equipo A
proc tantoA(in/out t: Tablero)
	incr(t.a)
end proc

// Incrementa el contador del equipo B
proc tantoA(in/out t: Tablero)
	incr(t.b)
end proc

// Libera memoria en caso de que sea necesario
proc destroy(in/out t: Tablero)
	desrtoy(t.a)
	destroy(t.b)
end proc

// Devuelve true si el tanteador esta en cero
fun en0(t: Tablero) ret b: bool
	b:= is_init(t.a) && is_init(t.b)
end fun

// Devuelve true si el equipo A anoto
fun anotoA(t: Tablero) ret b: bool
	b:= not(is_init(t.a))
end fun

// Devuelve true si el equipo B anoto
fun anotoB(t: Tablero) ret b: bool
	b:= not(is_init(t.b))
end fun

// Devuelve true si el equipo A gana
fun ganaA(t: Tablero) ret b: bool
	b:= t.a > t.b
end fun

// Devuelve true si el equipo B gana
fun ganaB(t: Tablero) ret b: bool
	b:= t.a < t.b
end fun

// Devuelve true si se registra un empate entre A y B
fun empate(t: Tablero) ret b: bool
	b:= t.a = t.b
end fun

// Suma n tantos al equipo e
proc sumarn(in/out t: Tablero, in n: nat, in e: char)
	if e = 'a'
		for 1 to n do
			incr(t.a)
		od
	else
		for 1 to n do 
			incr(t.b) 
		od
	fi
end proc

// Resta n tantos al equipo e
proc restarn(in/out t: Tablero, in n: nat, in e: nat)
	if e = 'a' then
		if (t.a < n) then
			init(t.a)
		else
			for 1 to n do
				decr(t.a)
			od
		fi
	else
		if (t.b < n) then
			init(t.b)
		else
			for 1 to n do
				decr(t.b)
			od
		fi
	fi
end proc
```

# Ejercicio 5

Especificar el TAD **`Conjunto finito de elementos`** de tipo T. Como constructores considerar

- el conjunto vacío
- el que agrega un elemento a un conjunto.

Como operaciones:

- una que chequee si un elemento e pertenece a un conjunto c,
- una que chequee si un conjunto es vacío,
- la operación de unir un conjunto a otro,
- insersectar un conjunto con otro y
- obtener la diferencia.

Estas últimas tres operaciones deberían especificarse como *procedimientos que toman dos conjuntos y modifican el primero de ellos*.

```c
spec Set of T where

constructors
  // Crea un conjunto vacio
	fun empty_set() ret s: Set of T
	
	// Agrega un elemento al conjunto
	proc add(in/out s: Set of T, in e: T)

destroy
	// Libera memoria en caso que sea necesario
	proc destroy_set(in/out s: Set of T)
	
Operations
	// Chequea si un elemento pertenece al conjunto
	fun pertenece(s: Set of T, e: T) ret b: bool
	
	// Chequea si el conjunto es vacio
	fun esVacio(s: Set of T) ret b: bool
	
	// Unir un conjunto con otro
	proc union(in/out s: Set of T, in s1: Set of T)
	
	// Intersectar un conjunto y otro
	proc intersec(in/out s: Set of T, in s1: Set of T)
	
	// Obtener la diferencia
	proc dif(in/out s: Set of T, in s1: Set of T)
```

Implementar el TAD **`Conjunto finito de elementos`** de tipo T utilizando:

a) una lista de elementos de tipo T, donde el constructor para
agregar elementos al conjunto se implementa directamente con el
constructor addl de las listas.

```c
implement Set of T where

type Set of T = List of T

// Crea un conjunto vacio
fun empty_set() ret s: Set of T
	empty_list(s)
end fun

// Agrega un elemento al conjunto
proc add(in/out s: Set of T, in e: T)
	addl(s, e)
end proc

// Libera memoria en caso que sea necesario
proc destroy_set(in/out s: Set of T)
	destroy(s)
end proc

// Chequea si un elemento pertenece al conjunto
fun pertenece(s: Set of T, e: T) ret b: bool
	var i: nat
	i:= 1
	b:= false
	while i < length(s) && b = false do
		if(index(s,i) = e) then b:= true fi
	od
end fun

// Chequea si el conjunto es vacio
fun esVacio(s: Set of T) ret b: bool
	b:= length(s) = 0
end fun

// Unir un conjunto con otro
proc union(in/out s: Set of T, in s1: Set of T)
	// Evito concat porque no puede haber repetidos
	var existe: bool
	existe:= false
	for i:= 1 to length(s1) do
		for j:= 1 to length(s) do
			if(index(s1,i) = index(s,j)) then existe:= true fi
		od
		if existe = false then addr(s1,i) fi
		b:= false
	od
end proc

// Intersectar un conjunto y otro
proc intersec(in/out s: set of T, in s1: set of T)
var s_tmp: set of T
var existe: bool
s_tmp:= copy_list(s)
s:= empty_list
for i:= 1 to length(s_tmp) do
    for j:= 1 to length(s1) do
        if(index(s_tmp,i) = index(s1,j)) then
            existe:= true
        fi
    od
    if (existe ^ not is_empty(s)) then
        {- agrego el elemento en la posicion que corresponda -}
        for k:=1 to length(s) do
            if(index(s_tmp,i) < index(s,k)) then
                add_at(s,k,index(s,k))
            fi
        od
    else if(existe ^ is_empty(copy_list)) then addl(s,index(s,i))
    fi
    existe:= false
od

proc dif_aux(in/out res: set of T, in a,a_comp: set of t)
    var existe: bool
    existe:= false
    for i:= 1 to length(a) do
        for j:= 1 to length(a_comp) do
            if(index(a,i) = index(a_comp,j)) then
                existe:= true
            fi
        od
        if (existe ^ not is_empty(res)) then
            {- agrego el elemento en la posicion que corresponda -}
            for k:=1 to length(res) do
                if(index(a_comp,i) < index(a,k)) then
                    add_at(res,k,index(a,k))
                fi
            od
        else if(existe ^ is_empty(a_comp)) then addl(res,index(a,i))
        fi
        existe:= false
    od
end proc

proc dif(in/out s: set of T, in s1: set of T)
    var s_tmp: set of T
    s_tmp:= copy_list(s)
    s:= empty_set()
    {- guardo en s los elementos de s que no se repiten en s1 -}
    dif_aux(s,s_tmp,s1)
    {- guardo en s los elementos de s1 que no se repiten en s -}
    dif_aux(s,s1,s_tmp)
end proc

fun copy_set(s: set of T) ret copy: set of T
    copy:= copy_list(s)
end fun
```