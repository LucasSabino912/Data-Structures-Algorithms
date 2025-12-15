/* En numerosas oportunidades se ha observado que cientos de ballenas nadan juntas hacia la costa y quedan varadas en la playa sin poder moverse. 
Algunos sostienen que se debe a una pérdida de orientación posiblemente causada por la contaminación 
sonora de los océanos que interferiría con su capacidad de inter-comunicación. 
En estos casos los equipos de rescate realizan enormes esfuerzos para regresarlas al interior del mar y salvar sus vidas.

Se encuentran n ballenas varadas en una playa y se conocen los tiempos s1,s2,...,sn que cada ballena 
es capaz de sobrevivir hasta que la asista un equipo de rescate. Dar un algoritmo voraz que 
determine el orden en que deben ser rescatadas para salvar el mayor número posible de ellas, 
asumiendo que llevar una ballena mar adentro toma tiempo constante t, que hay un único equipo de rescate 
y que una ballena no muere mientras está siendo regresada mar adentro. */

/* Datos:
    - n ballenas
    - sobreviven s1,...,sn
    - rescatarlas lleva un tiempo constante t 
    
Criterio de seleccion: seleccionar a la ballena que menos tiempo de vida le quede */

/* La ides es hacer:
    - Una funcion que ctualiza la solucion
    - Una funcion que encuentre la ballena con menos tiempo de vida
    - Una funcion que actualice las muertas 
  
   Manejarse con conjuntos ya que agarramos el conjunto y comparamos todas las ballenas sin orden */

type Ballena = tuple
                id: string
                s: nat
               end tuple


fun rescate(C: Set of Ballena, t: Nat) ret l: List of ballena
    var C_aux: Set of ballena
    var tiempo: nat
    var b: Ballena

    C_aux:= copy_set(C)
    l:= empty_list()
    tiempo:= 0

    while not is_empty_set(C_aux) do
        b:= hallar_ballena(C_aux)
        elim(C_aux, b)
        addr(l, b)
        actualizar_ballenas(C_aux, tiempo)
        tiempo:= tiempo + t
    od
    destroy_set(C_aux)
end fun

// Criterio de seleccion
fun hallar_ballena(C: Set of Ballena) ret b: Ballena
    var min: nat
    var ballena: Ballena
    var C_aux: Set of Ballena

    C_aux:= copy_set(C)
    min:= +inf

    while not is_empty_set(C_aux) do
        ballena:= get(C_aux)
        elim(C_aux, ballena)
        if min > ballena.s then
            min:= ballena.s
            n:= ballena
        fi
    od

    destroy_set(C_aux)
end fun

proc actualizar_ballenas(in/out C: Set of ballena, in t: nat)
    var b: ballena
    var C_aux: set of Ballena
    
    C_aux:= copy_set(C)

    while not is_empty_set(C_aux) do
        b:= get(C_aux)
        elim(C_aux, b)
        if b.s < t then
            elim(C, b)
        fi
    od

    destroy_set(C_aux)
end proc