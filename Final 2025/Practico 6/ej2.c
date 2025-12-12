/* implement Stack of T where

type Node of T = tuple
					elem: T
					next: pointer to (Node of T)
				 end tuple

type Stack of T = pointer to Node of T

spec Stack of T where */

// Crea una pila vacia
fun empty_stack() ret s: Stack of T
	s:= null
end fun

// Agrega un elemento al tope de s
proc push(in e: T, in/out s: Stack of T)
	var p: pointer to (Node of T)
	
	p->elem:= e
	p->next:= s 
	s:= p
end proc

// Libera memoria en caso de que sea necesario
proc destroy(in/out s: Stack of T)
	s:= null
	free(s)
end proc

// Devuelve true si la pila es vacia
fun is_empty_stack(s: Stack of T) ret b: Bool
	b:= s = null
end fun

// Devuelve el elemento en el tope de s
{- PRE: !is_empty_stack(s) -}
fun top(s: Stack of T) ret e: T
	e:= s->elem
end fun

// Elimina el elmento en el tope de s
{- PRE: !is_empty_stack(s) -}
proc pop(in/out s: Stack of T)
	var p: pointer to (Node of T)
	p:= s
	s:= s->next
	free(p)
end proc

// Copia s en s1
fun copy_stack(s: Stack of T) ret s1: Stack of T
	var p: pointer to (node of T)
	
	p:= s
	while p->next != null do
		s1->elem:= p->elem
		p:= p->next
	od
end fun