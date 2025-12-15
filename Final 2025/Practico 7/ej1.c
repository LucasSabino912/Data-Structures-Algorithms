/* Se desea realizar un viaje en un automóvil con autonomía A (en kilómetros), desde la localidad l0 hasta la localidad ln pasando por las localidades l1, ... , ln−1 en ese orden. Se conoce cada distancia di ≤ A entre la localidad li−1 y la localidad li (para 1 ≤ i ≤ n), y se sabe que existe una estación de combustible en cada una de las localidades.

Escribir un algoritmo que compute el menor número de veces que es necesario cargar combustible para realizar el viaje, y las localidades donde se realizaría la carga.

Suponer que inicialmente el tanque de combustible se encuentra vacío y que todas las estaciones de servicio cuentan con suficiente combustible.*/

/*
Datos: 
 - autonomía A
 - l0,...,ln localidades, empezando por l1 hasta ln-1
 - d0...dn distancias

calcular el menor numero de veces que se necesita cargar y las localidades deonde se carga

Criterio de seleccion: 
Cargo en la localidad que no me alcance para llegar a la proxima */


// Solucion a retornar
type Cargas = tuple
                cant: necesita
                localidades: List of Localidades 
             end tuple

type Localidad = tuple
                    distancia: nat
                    name: string
                 end tuple


fun cargar(A: nat, l: List of Localidad) ret res: Cargas
   var l_aux: List of Localidad
   var actual: Localidad
   var siguiente: Localidad
   var autonomia: nat
   var distancia: nat

   l_aux:= copy_list(l)

   // Carga inicial en l0
   actual:= head(l_aux)
   tail(l:l_aux)
   autonomia:= a
   res.cant:= 1
   res.localidades:= empty_list()
   addr(res.localidades, actual)

   while length(l_aux) > 0 do 
      siguiente:= head(l_aux)
      tail(l_aux)
      distancia:= siguiente.distancia
      if autonomia < distancia then
         addr(res.localidad, actual)
         res.cantidad:= res.cantidad + 1
         autonomia:= a
      fi
      autonomia:= autonomia - distancia
      actual:= siguiente
   od
   destroy_list(l_aux)
end fun