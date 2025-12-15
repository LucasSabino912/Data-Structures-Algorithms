/* Para obtener las mejores facturas y medialunas, es fundamental abrir el horno 
el menor número de veces posible. Por supuesto que no siempre es fácil ya que no hay 
que sacar nada del horno demasiado temprano, porque queda cruda la masa, ni demasiado 
tarde, porque se quema.

En el horno se encuentran n piezas de panadería (facturas, medialunas, etc). 
Cada pieza i que se encuentra en el horno tiene un tiempo mínimo necesario de cocción ti y un tiempo máximo admisible de cocción Ti.

Si se la extrae del horno antes de ti quedará cruda y si se la extrae después de Ti se quemará.

Asumiendo que abrir el horno y extraer piezas de él no insume tiempo, y que ti ≤ Ti para todo i ∈ {1,...,n}, 
qué criterio utilizaría un algoritmo voraz para extraer todas las piezas del horno en perfecto estado (ni crudas ni quemadas), 
abriendo el horno el menor número de veces posible? */


/* Datos:
    - Abrir el horno la mnor cantidad de tiempo posible
    - n piezas
   
   Criterio de seleccion: 
    - Sacar la que menor Ti tenga, y con esa sacar las que ya esten cocinas (T >= ti)  
    
    El algoritmo toma un conjunto de facturas y devuelve una lista ordenada de las facturas que se sacan */

type Factura = tuple
                name: string
                ti: int
                Ti: int
               end tuple

fun horno(C: Set of Factura) ret l: List of Factura
    var C_aux: Set of Factura
    var tiempo_actual: int
    var timpo_min: int
    var fl: List of Factura

    tiempo_actual, tiempo_min:= 0
    C_aux:= copy_set(C)
    l:= empty_list()

    while not is_empty_set(C_aux) do
        tiempo_min:= minimo(C_aux)
        tiempo_actual:= tiempo_min + tiempo_actual
        fl:= seleccionar_facturas(C_aux, tiempo_actual)
        concat(l, fl)
        fl:= empty_list()
        actualizar_facturas(C_aux, tiempo_actual)
    od

    destroy_set(C_aux)
    destroy_list(fl)
end fun

fun minimo(C: Set of factura) ret m: int
    var f: Factura

    m:= +inf

    while not is_empty_set(C_aux) do
        f:= get(C_aux)
        elim(C_aux, f)
        if f.Ti < min then
            m:= f.Ti
        fi
    od
    
    destroy_set(C_aux)
end fun

fun seleccionar_facturas(C: Set of Factura, t: int) ret l: List of Factura
    var C_aux: Set of Factura
    var f: Factura

    C_aux:= copy_set(C)
    l:= empty_list()

    while not is_empty_set(C_aux) do
        f:= get(C_aux)
        elim(C_aux, f)
        if f.ti >= t and f.Ti <= t then
            addr(l, f)
        fi
    od

    destroy_set(C_aux)
end fun

proc actualizar_facturas(in/out C: Set of Factura, in t: int)
    var C_aux: Set of Factura
    var f: Factura

    C_aux:= copy_set(C)

    while not is_empty_set(C_aux) do
        f:= get(C_aux)
        elim(C_aux, f)
        if f.Ti > t then
            elim(C, f)
        fi
    od

    destroy_set(C_aux)
end proc

