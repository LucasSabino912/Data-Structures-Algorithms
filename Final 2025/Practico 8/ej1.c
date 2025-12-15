/* 
- Sean d1,…, dn las denominaciones de las monedas, todas mayores que 0.
- No se asume que esten ordenadas
- Se dispone de una cantidad infinita de monedas de c/denominacion
- Se desea pagar un monto k de manera exacta utilizando **el menor numero de monedas posibles**

Dado un conjunto n de denominaciones y un monto k a pagar, recursiva mente iremos probando con cada denominacion para pagar el monto, si una denominacion es factible, pruebo usarla o no. Para ello calculo el resultado en cada caso y luego obtengo el minimo

La solución la obtenemos llamando a cambio(k, C) */

// Tengo i monedas para pagar un monto j
// Tengo di denominaciones

cambio(i,j) = 
    | 0               si j = 0              // ya pague, no tengo monto 
    | inf             si j > 0 & i = 0      // no tengo mnoedas pero si monto
    | cambio(i-1,j)   si di > j > 0 & i > 0 // no elijo esa moneda
    | min(cambio(i-1,j), 1 + cambio(i,j-di)) si j >= di si j >= di > 0 & i > 0

    