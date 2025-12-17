// Tads
/* TAD PilaReversible es igual que el TAD Pila pero ademas tiene la operacion revertir que dada una pila, invierte el orden de los elementos, por ejemplo:
   | 8 | 3 | 2 | => | 2 | 3 | 8 | */

type RevStack of T = tuple
                        elems: array[0..N-1] of T
                        bottom: nat
                        top: nat
                        direccion: {-1, 1}
                    end tuple

/* Bottom señala la posicion que se encuentra el elemento mas viejo de la pila, top señala la del mas nuevo de la pila reversible y direction 
es 1 si esta almacenada de izquierda a derecha (orden usual) y -1 al reves. La idea es nunca revertir realmente los valores de la pila

Basicamente top y bottom nunca se cambian, lo que hace direction es ver de que forma se realizan las operaciones */

type RevStack of T = tuple
    elems: array[0..N-1] of T
    bottom: nat
    top: nat
    direction: {-1, 1}
end tuple

fun empty() ret p: RevStack of T
    p.bottom := 0
    p.top := N-1
    p.direction := 1
end fun

proc reverse(in/out r: RevStack of T)
    r.direction:= r.direction * (-1)
end proc

fun is_empty_stack(p: RevStack of T) ret b: bool
    b := ((p.top + p.direction) mod N = p.bottom)
end fun

fun is_full(p: RevStack of T) ret b: bool
    b := ((p.top + p.direction) mod N = p.bottom)
end fun

// PRE: not is_full(p)
proc push(in e: T, in/out p: RevStack of T)
    p.top := (p.top + p.direction) mod N
    p.elems[p.top] := e
end proc

// PRE: not is_empty_stack(s)
proc pop(in/out s: RevStack of T)
    s.top := (s.top - s.direction) mod N
end proc

// PRE: not is_empty_stack(s)
fun top(s: RevStack of T) ret e: T
    e := s.elems[s.top]
end fun

proc reverse(in/out s: RevStack of T)
    s.direction := -s.direction
end proc

/* implementar una operación que reciba una pila reversible y  devuelva el elemento que se encuentra en la "base" de la misma. 
Es decir, si la pila es | 2|7|4|5|, donde 2 es el tope, la operación debe devolver 5 */
fun (r: Revstack of T) ret e: T
    // Aprovecho la reversibilidad
    reverse(r)
    e:= top(r)
    reverse(r)
end fun


// Algoritmos voraces
/* Sos DJ tenes una coleccion de N canciones de 15 artistas diferentes, cada una puntuada con un nivel vi de intensidad, 
con i entre 1 y N. Tenes que armar un set de 30 canciones para pasar en una fiesta de manera que la intensidad crezca desde
la cancion 1 a la 30, con la condicion de que no podes pasar mas de 3 canciones del mismo autor. Se busca que la suma de intensidad sea maxima */

// La solucion sera una lista ordenada de canciones

type Cancion = tuple
                intensidad: nat
                artista: nat   // valor entre 1 y 15
               end tuple


fun maxIntensidad(c: Set of Cancion) ret l: List of Cancion
    var C_aux: Set of cancion
    var i: nat
    var c: Cancion
    var usos:array[1..15]

    l:= empty_list(l)
    C_aux:= copy_set(C)
    i:= 0

    // lleno el arreglo de artistas
    for i:= 1 to 15 do
        array[i]:= 0
    od

    while not is_empty_set(C_aux) and length(l) < 30 do
        c:= seleccionar_cancion(C_aux)
        elim(C_aux, c)
        addl(l, c)
        i:= i + c.intensidad
        usos[c.autor]:= usos[c.autor] + 1
        actualizar_canciones(C_aux, usos, i)
    od
    destroy_set(C_aux)
end fun

// Criterio de seleccion: selecciono la cancion con menor intensidad  
fun seleccionar_cancion(C: Set of Cancion) ret cancion: Cancion
    var C_aux: Set of Cancion
    var c: Cancion
    var min: int 

    min:= +inf
    C_aux:= copy_set(C)
    
    while not is_empty_set(C_aux) do
        c:= get(C_aux)
        elim(C_aux, c)
        if c.i < min then
            min:= c.i
            cancion:= c
        fi
    od

    destroy_set(C_aux)
end fun

proc actualizar_canciones(in/out C: Set of Cancion, in usos: array[1..15], in i: nat)
    var C_aux: Set of Cancion
    var c: Cancion

    C_aux:= copy_set(C)
    
    while not is_empty_set(C_aux) do
        c:= get(C_aux)
        elim(C_aux, c)
        if c.i < i or usos[c.autor] >= 3 then
            elim(C, c)
        fi
    od
    destroy_set(C_aux)
end proc


// Backtracking y PD
/* Sos la única programadora de una flamante empresa que provee desarrollo en distintos proyectos. 
Tenés n proyectos posibles a los cuales ofrecer servicio y la posibilidad de trabajar H horas como máximo. 
Para cada proyecto i ∈ {1..n} ya calculaste la cantidad de horas h₁ que requiere de trabajo, y la paga p que 
recibirás si lo hacés. Tenés la posibilidad de pedirle a un amigo que te ayude con algunos proyectos, en 
cuyo caso te va a tomar la mitad de las horas (división entera) realizarlo, pero vas a cobrar la mitad del dinero 
(ya que la otra mitad se la darás a tu amigo). Tu tarea es calcular la máxima ganancia que podés obtener eligiendo 
qué proyectos tomar y cuándo recurrir a la ayuda de tu amigo. */

/* Datos:
    - n proyectos posibles
    - H horas maximas
    - pi paga y hi horas por cada proyecto
    - pi/2 y hi/2 si ayuda a tu amigo

    maxima ganancia eligiendo proyectos y cunado recurrir a un amigo */

type Proyectos = tuple
                    h: int
                    p: int
                end tuple

i proyectos
j horas

proy(i, j) = 
    | 0                                                                         si i = 0 or j = 0
    | proy(i-1,j)                                                               si i > 0 and j < h[i] / 2
    | max(proy(i-1,j), p[i]/2 * proy(i-1,j-h[i]/2))                             si h[i] / 2 <= j < h[i]
    | max(proy(i-1,j), p[i] + proy(i-1, j-h[i]), p[i]/2 * proy(i-1,j-h[i]/2))   si h[i] <= j 


fun proy(in p: array[1..N], h: array[1..H]) ret m: nat
    var a:array[0..N,0..H]
    var horas_restantes: nat

    horas_restantes:= 0

    for i:= to N do a[i,0]:= 0
    for j:= to H do a[0,j]:= 0

    for i:= 1 to N do
        for j:= 1 to H do
            if i > 0 and j < horas_restantes / 2 then
                a[i,j]:= a[i-1,j]
            else if (horas_restantes / 2) <= j < horas[i] then
                a[i,j]:= max(a[i-1,j], p[i]/2 + a[i-1,j - horas[i]/2])
            else 
                a[i,j]:= max(a[i-1,j], p[i] + a[i-1,j - horas[i]], p[i]/2 + a[i-1,j - horas[i]/2])
            fi
        od
    od

    m:= a[N,M]
end fun



// ¿Que hace p?
proc p(in/out l: List)
    var a,b: pointer to Node
    a:= l
    while a != null do 
        b:= a->next
        if b != null do 
            a->next:= b->next
            free(b)
        fi 
        a:= a->next
    od 
end proc

// Primer corrida
a -> l // a lista, primer elemento
b -> l->next // b segundo elemento
si existe l->next entonces
a->next:= b->next->next // a->next pasa a ser tercer elemento
borro b // borro segundo elemento
a->next->next->next // a pasa a tercer elemento

// Segunda corrida
b -> a->next // b cuarto elemento
si existe a->next entonces
a->next:= b->next->next // a->next pasa a ser el quinto
free(b) // borro b
a->next->next->next // a pasa a quinto elemento

// El algoritmo borra los elementos pares de una lista