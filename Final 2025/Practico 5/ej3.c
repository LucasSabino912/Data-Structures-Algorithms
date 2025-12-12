/* Implementar el procedimiento add_at que toma una lista de tipo T, un natural n, un elemento e de tipo T, 
y agrega el elemento e en la posición n, quedando todos los elementos siguientes a continuación.

Esta operación tiene como precondición que n sea menor al largo de la lista. 

AYUDA: Puede ayudarte usar las operaciones copy, take y drop */


/* PRE: n < length(l) */
proc add_at(in/out l:list of T, in: n: nat, in e: T)
    l.size:= l.size + 1

    for i:= l.size - 1 downto n + 1 do 
        l.elems[i + 1]:= l.elems[i]
    od

    l.elems[n]:= e
end proc