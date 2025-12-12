/* Completar la implementación de listas dada en el teórico usando punteros.

implement List of T where

type Node of T = tuple
                    elem: T
                    next: pointer to (Node of T)
                 end tuple

type List of T = pointer to (Node of T) */

/* Constructors */

fun empty_list() ret l: list of t
    alloc(l)
    l:= null
end fun

proc addl (in/out l:list of t, in e: T)
    var p: pointer to (Node of T)
    allooc(p)
    p->elem:= el
    p->next:= l
    l:= p
end proc

/* Destructors */

proc destroy_list(in/out l:list of t)
    var p: pointer to (Node of T)
    while (l != null ) do 
        p:= l
        l:= l->next
        free(p)
    od
end proc

/* Operations */

fun is_empty(l:list of T) ret b: bool
    b:= (l = null)
end fun

fun head(l:list of T) ret e: T
    e:= l->elem
end fun

proc tail(in/out l:list of T)
    var p: pointer to (Node of T)
    p:= l
    l:= l->next
    free(p)
end proc

proc addr(in/out l:list of T, in e: T)
    var p, q: Pointer to (Node of T)
    alloc(p)
    p->elem:= e
    p->next:= null

    if (l != null) then
        q:= l
        while (q->next != null) do
            q:= q->next
        od
        q->next = p
    else l:= p
    fi
end proc

fun length() ret length: int
    var p: pointer to (Node of T)
    var i: int
    p:= l
    while (p->next != null) do
        p:= p->next
        i:= i + 1
    od
end fun

proc concat(in/out l1: list of T, in l2: list of T)
    var p: pointer to (Node of T)
    if l1 = null && l2 != null then
        l1:= l2
    else 
        p:= l1
        while (p->next != null) do
            p:= p->next
        od
        p->next:= l2
    fi
end fun

fun index(l:list of T, n: int) ret i: int
    var p: pointer to (Node of T)
    i:= 1
    
    while p->next != null && i < n do
        p:= p->next
        i:= i + 1
    od
end fun

proc take(in/out l:list of T, in n: int)
    var p,q: pointer to (Node of T)
    var i: nat
    i:= 0

    if l != null then
        if n = 0 then
            while l != null do
                p:= l
                l:= l-> next
                free(p)
            od
        else if n > 0 then
            p:= l
            // Busco el primer elemento a eliminar
            while l != null & i < n do
                p:= p->next
                i:= i + 1
            od

            // Elimino los elementos
            while p != null do
                q:= pointer
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