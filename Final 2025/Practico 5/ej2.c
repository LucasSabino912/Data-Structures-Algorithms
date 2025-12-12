/* Dada una constante natural N, implementar el TAD Lista de elementos de tipo T, 
usando un arreglo de tamaño N y un natural que indica cuántos elementos del arreglo 
son ocupados por elementos de la lista.

implement List of T where

type Node of T = tuple
                    size: nat
                    elems: array[1..N] of T
			    end tuple */

fun empty_list() ret l: list of t
    l.size:= 0
end fun


proc addl (in/out l:list of t, in e: T)
    l.size:= l.size + 1
    for i:= l.size - 1 downto 1 downto
        l.elems[i + 1]:= l.elems[i]
    od 

    l.elems[1]:= e
end proc

/* Destructors */

proc destroy_list(in/out l:list of t)
    l.size:= 0
end proc

/* Operations */

fun is_empty(l:list of T) ret b: bool
    b:= (l.size = 0)
end fun


fun head(l:list of T) ret e: T
    e:= l.elems[1]
end fun


proc tail(in/out l:list of T)
    l.size:= l.size - 1
end proc


proc addr(in/out l:list of T, in e: T)
    l.size:= l.size + 1
    l.elems[l.size]:= e
end proc


fun length() ret l: int
    l:= l.size
end fun


proc concat(in/out l1: list of T, in l2: list of T)
    var aux: int
    
    aux:= l1.size
    l1.size:= l1.size + l2.size
    
    for i:= aux to l1.size do
        l1.elems[i]:= l2.elems[i - aux]
    od 
end fun


fun index(l:list of T, n: int) ret i: int
    i:= l.elems[n]
end fun


proc take(in/out l:list of T, in n: int)
    var tmpl: List of t
    tmpl.size:= n 
    
    for i:= 1 to n do
        tmpl.elems[i]:= l.elems[i]
    od
    
    l.size:= tmpl.size
    l:= tmpl
end proc


proc drop(in/out l: List of T, in n: nat)
    var i,j: int
    i:= 1
    j:= n + 1
    while j <= l.size do
        l.elems[i]:= l.elems[j]
        i++
        j++
    od

    l.size:= j
end proc


fun copy_list(l1: List of T) ret l2: List of T
    l2.size:= l1.size    
    for i:= 1 to l1.size do
        l2.elems[1]:= l1.elems[i]
    od
end fun