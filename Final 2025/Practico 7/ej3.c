/* Sos el flamante dueño de un teléfono satelital, y se lo ofrecés a tus n amigos para que lo lleven con 
ellos cuando salgan de vacaciones el próximo verano. Lamentablemente cada uno de ellos irá a un lugar diferente 
y en algunos casos, los períodos de viaje se superponen. 
Por lo tanto es imposible prestarle el teléfono a todos, pero quisieras prestárselo al mayor número de amigos posible.

Suponiendo que conoces los días de partida y regreso (pi y ri respectivamente) de cada uno de tus amigos,

Cuál es el criterio para determinar, en un momento dado, a quien conviene prestarle el equipo?

Tener en cuenta que cuando alguien lo devuelve, recién a partir del día siguiente puede usarlo otro. E
scribir un algoritmo voraz que solucione el problema.*/

/* Datos: 
    - n amigos
    - pi dia de partida
    - ri dia de regreso
    - Puedo usar el telefono recien un dia despues de devuelto

Criterio de seleccion: se lo presto al que antes me lo devuelva */

type Amigo = tuple
              id: string
              partida: Nat
              regreso: nat
            end tuple


fun tel(C: Set of Amigo) ret l: list of Amigo
    var C_aux: Set of Amigo
    var amigo: Amigo
    var diaActual: nat

    C_aux:= copy_set(C)
    dia:= 0

    while not is_empty_set(C_aux) do
        amigo:= seleccionar_amigo(C_aux)
        elim(C_aux, amigo)
        diaActual:= amigo.regreso + 1
        addr(l, amigo) 
        actualizar_amigos(C_aux, diaActual)
    od
    destroy_set(C_aux)
end fun

// Criterio de seleccion:
// Hallar al amigo que vuelva antes
fun seleccionar_amigo(C: Set of Amigo) ret a: amigo
    var C_aux: Set of Amigo
    var amigo: amigo
    var dia_min: int

    C_aux:= copy_set(C)
    dia_min:= +inf

    while not is_empty_set(C_aux) do
        amigo:= get(C_aux)
        elim(C_aux, amigo)
        if amigo.ri < dia.min then
            a:= amigo
           dia_min:= amigo.ri
        fi
    od
    destroy_set(C_aux)
end fun

proc actualizar_amigos(in/out C: Set of Amigo, in d: int)
    var C_aux: Set of Amigo
    var a: Amigo

    C_aux:= copy_set(C)

    while not is_empty_set(C_aux) do
        a:= get(C_aux)
        elim(C_aux, a)
        if a.pi > d then
            elim(C, a)
        fi
    od
    destroy_set(C_aux)
end proc