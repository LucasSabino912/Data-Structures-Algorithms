# Practico 2.3

# Ejercicio 1

Implementar el TAD Pila utilizando la siguiente representación:

```c
implement Stack of T where

type Stack of T = List of T

// Crea una pila vacia
fun empty_stack() ret s: Stack of T
	empty_list(s)
end fun

// Agrega un elemento al tope de s
proc push(in e: T, in/out s: Stack of T)
	addl(e, s)
end proc

// Libera memoria en caso de que sea necesario
proc destroy(in/out s: Stack of T)
	destroy_list(s)
end proc

// Devuelve true si la pila es vacia
fun is_empty_stack(s: Stack of T) ret b: Bool
	b:= is_empty_list(s)
end fun

// Devuelve el elemento en el tope de s
{- PRE: !is_empty_stack(s) -}
fun top(s: Stack of T) ret e: T

// Elimina el elmento en el tope de s
+{- PRE: !is_empty_stack(s) -}
proc pop(in/out s: Stack of T)
	take(length(s) - 1)
end proc

// Copia s en s1
fun copy_stack(s: Stack of T) ret s1: Stack of T
	s1:= copy_list(s)
end fun
```

# Ejercicio 2

Implementar el TAD pila usando la siguiente implementacion

```c
implement Stack of T where

type Node of T = tuple
									elem: T
									next: pointer to (Node of T)
								 end tuple

type Stack of T = pointer to Node of T

spec Stack of T where

// Crea una pila vacia
fun empty_stack() ret s: Stack of T
	alloc(s)
	s:= null
end fun

// Agrega el elemento e al tope de s
proc push(in e: T, in/out s: Stack of T)
	var p: pointer to (Node of T)
	alloc(p)
	p->elem:= e
	p->next:= s
	s:= p
end proc

proc destroy_stack(in/out s: Stack of T)
	while s->next != null do
		destroy_stack(s->next)
		free(s)
	od
	s:= null
end proc

// Deuvelve true si la pila es vacia
fun is_empty_stack(s: Stack of T) ret b: Bool
	b:= s = null
end fun

// Devuelve el elemento en el tope de s
{- PRE: !is_empty_stack(s) -}
fun top(s: Stack of T) ret e: T
	e:= s->elem
end fun

// Elimina el elemento en el tope de s
{- PRE: !is_empty_stack(s) -}
proc pop(in/out s: Stack of T)
	var p: pointer to (Node of T)
	alloc(p)
	p:= s
	s:= s->next
	free(p)
end proc

fun copy_stack(s: Stack of T) ret s1: Stack of T
	var p: pointer to (Node of T)
	p:= s
	while-
									
```

# Ejercicio 3

Implementar el TAD Cola utilizando la siguiente representación, dónde N es una constante de tipo nat

```c
ímplement Queue of T where

type Queue of T = tuple
										elems: array[0..N-1] of T
										size: nat
									 end tuple

fun empty_queue() ret q: Queue of T
	q.zize:= 0
end fun

proc enqueue(in/out q: Queue of T, in e: T)
	q.size:= q.size + 1
	q.elems[q.size+1]:= e
end proc

fun is_empty(q: Queue of T) ret b: bool
	b:= q.size = 0
end fun

fun first(q: Queue of T) ret e: T
	e:= q.elems[0]
end fun

proc dequeue(in/out q: Queue of T)
	for i:= 1 to N-1 do
		q.elems[i-1]:= 1.elems[i]
	od
	q.size(N-1)-1
```

# Ejercicio 4

Completar la implementación del tipo Arbol Binario dada en el teórico, donde utilizamos la siguiente representación:

```c
implement Tree of T where

type Node of T = tuple
                    left: pointer to (Node of T)
                    value: T
                    right: pointer to (Node of T)
                 end tuple

type Tree of T = pointer to (Node of T)

```

```c
type Direction = enumerate
                    Left
                    Right
                 end enumerate

type Path = List of Direction

fun empty_tree() ret t: Tree of T
   t:= null
end fun

fun node (tl: Tree of T, e: T, tr: Tree of T) ret t: Tree of T
    alloc(t)
    t->left:= tl
    t->value:= e
    t->right:= tr
end fun

proc destroy_tree (in/out t: Tree of T)
    while(t ≠ null) do
        destroy_tree(t->left)
        destroy_tree(t->right)
        free(t)
    od
end proc

fun copy_tree(t: Tree of T) ret copy: Tree of T
    alloc(copy)
    copy->value:= t->value
    copy->left:= copy_tree(t->left)
    copy->right:= copy_tree(t->right)
end fun

fun is_empty_tree(t: Tree of T) ret b: Bool
    b:= (t = null)
end fun

fun root(t: Tree of T) ret e: T
    e:= t->value
end fun

fun left(t: Tree of T) ret tl: Tree of T
    tl:= t->left
end fun

fun right(t: Tree of T) ret tr: Tree of T
    tr:= t->right
end fun

fun height(t: Tree of T) ret n: Nat
    if(t = null) then n:= 0
    else
        n:= 1 + (height(t->left) max height(t->right))
    fi
end fun

fun is_path(t: Tree of T, p: Path) ret b: Bool
    var t_aux: Tree of T
    var p_aux: Path
    t_aux:= copy_tree(t)
    p_aux:= copy_list(p)
    b:= true
    while(not is_empty(p_aux) ^ b) do
        if(t->head(p_aux) = null) then b:= false
        else
            t_aux:= t_aux->head(p_aux)
            tail(p_aux)
        fi
    od
end fun

fun subtree_at(t: Tree of T, p: Path) ret t0: Tree of T
    var p_aux: Path
    p_aux:= copy_list(p)
    t0:= copy_tree(t)
    while(not is_empty(p_aux)) do
        t0:= t0->head(p_aux)
        tail(p_aux)
    od
end fun

fun elem_at(t: Tree of T, p: Path) ret e: T
    var t_aux: Tree of T
    var p_aux: Path
    t_aux:= copy_tree(t)
    p_aux:= copy_list(p)
    while(not is_empty(p_aux)) do
        t_aux:= t_aux->head(p_aux)
        tail(p_aux)
    od
    e:= t_aux->value
end fun

```