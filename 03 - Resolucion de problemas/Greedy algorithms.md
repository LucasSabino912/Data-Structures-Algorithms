# Algoritmos voraces

Se tratan de algoritmos que resuelven problemas de **optimizacion**, es decir, tenemos un problema que queremos resolver de manera **optima:**

- el camino mas corto que uno dos ciudades
- el costo minimo para proveer un cierto servicio
- el valor maximo alcanzable entre ciertos objetos

Los algoritmos voraces intentan construir la solucion optima buscada **paso a paso**, elegiendo en cada paso el componente de la solucion que parezca mas apropiado

## Estrategia

1. **Escoger la mejor opcion disponible en el momento**
2. **No reconsiderar decisiones previas**
3. **Repetir hasta encontrar la solucion**

```c
fun voraz(C: Set of Candidato, p: data) ret s: solution
	var C_aux: Set of Candidato
	car c: Candidato
	var p_aux: data
	
	s:= solucion_base()
	C_aux:= set_copy(C)
	p_aux:= p
	
	if not problema_resolvible(C,p) then
		s:= error
	else 
		while not problem_is_solved(C,p) do
			c:= select_candidate(C_aux)
			elim(C_aux,c)
			
			if is_feaseble(c) then
				s:= modify_solution(s,c,p_aux)
				p_aux:= modify_problem(p_aux,c)
			fi
		od
	fi
	
	set_destroy(C_aux)
end fun
```

### Problema de la autonomia

Se desea realizar un viaje en un automóvil con autonomía A (en kilómetros), desde la localidad l0 hasta la localidad ln pasando por las localidades l1, ... , ln−1 en ese orden. Se conoce cada distancia di ≤ A entre la localidad li−1 y la localidad li (para 1 ≤ i ≤ n), y se sabe que existe una estación de combustible en cada una de las localidades.

Escribir un algoritmo que compute el menor número de veces que es necesario cargar combustible para realizar el viaje, y las localidades donde se realizaría la carga.

Suponer que inicialmente el tanque de combustible se encuentra vacío y que todas las estaciones de servicio cuentan con suficiente combustible.

```c
Datos: 
 - A autonomia
 - l0 a ln localidades
 - d0 a d1 distancias
 - se debe pasar pos las localidades l1 hasta ln-1

Se debe calcular el **menor numero de veces** que es necesario cargar,
y las localidades donde se carga

**Criterio de seleccion:** cargo en la localidad en la que no me alcance para
llegar a la proxima

La solucion sera una tupla con dos elementos, un natural con la cantidad de 
veces donde se carga y una lista de localidades

Cargo en la localidad 0 y sigo hasta ln

type Cargas = tuple
								cant: nat
								loca: List of Localidades
							end tuple
							
type Localidad = tuple
									d: Nat
									name: String
							   end tuple
				

fun cargarCombustible(A: nat, l: List of Localidad) ret res: Cargas
  var l_aux: List of Localidad
  var actual: Localidad
  var siguiente: Localidad
  var autonomia: Nat

  l_aux := copy_list(l)

  // Carga inicial en l0
  actual := head(l_aux)
  tail(l_aux)
  autonomia := A
  res.cant := 1
  res.loca := empty_list()
  addr(res.loca, actual)

  while length(l_aux) > 0 do
    siguiente := head(l_aux)
    tail(l_aux)
    var distancia: Nat
    distancia := siguiente.d - actual.d
    
    if autonomia < distancia then
      // Cargo en localidad actual
      addr(res.loca, actual)
      res.cant := res.cant + 1
      autonomia := A
    fi
    autonomia := autonomia - distancia
    actual := siguiente
  od
  destroy_list(l_aux)
end fun
```

### Problema de las ballenas

En numerosas oportunidades se ha observado que cientos de ballenas nadan juntas hacia la costa y quedan varadas en la playa sin poder moverse. Algunos sostienen que se debe a una pérdida de orientación posiblemente causada por la contaminación sonora de los océanos que interferiría con su capacidad de inter-comunicación. En estos casos los equipos de rescate realizan enormes esfuerzos para regresarlas al interior del mar y salvar sus vidas.

Se encuentran n ballenas varadas en una playa y se conocen los tiempos s1,s2,...,sn que cada ballena es capaz de sobrevivir hasta que la asista un equipo de rescate. Dar un algoritmo voraz que determine el orden en que deben ser rescatadas para salvar el mayor número posible de ellas, asumiendo que llevar una ballena mar adentro toma tiempo constante t, que hay un único equipo de rescate y que una ballena no muere mientras está siendo regresada mar adentro.

```c
Datos: 
 - n ballenas
 - sobreviven un tiempo s1,..,sn
 - rescatarlas lleva un tiempo constante t

Se debe determinar el orden en las que las ballenas seran salvadas
El algoritmo toma un cjto de ballenas y devolvera una lista ordenada  
de las ballenas rescatadas en orden

El criterio de seleccion sera salvar a la que menos tiempo de vida le quede,
siempre y cuando el tiempo de rescate sea menor al de sobrevivencia

type Ballena = tuple
								id: string
								s: nat 
							 end tuple
							 
fun ballena(C: Set of Ballena, t: Nat) ret l: List of Ballena
	var C_aux:= Set of Ballena
	var tiempo:= nat
	var b: Ballena
	
	C_aux:= copy_set(C)
	tiempo:= 0
	
	while not is_empty_set(C_aux) then
		b:= encontrar_ballena(C_aux)
		elim(C_aux, b) 
		addr(l, b) 
		actualizar_ballenas(C_aux, tiempo)		
	  tiempo:= tiempo + t
	od
	destroy_set(C_aux)
end fun

fun encontrar_ballena(C: Set of Ballena) ret b: Ballena 
	var min: nat
	var ballena: ballena 
	var C_aux: Set of Ballena
	
	C_aux:= copy_set(C)
	min:= +infinito 
	
	while not is_empty_set(C_aux) do
		b:= get(C_aux) 
		elim(C_aux, b)
		if ballena.s < min then
			min:= ballena.s 
			b:= ballena
		fi 
	od
	destroy_Set(C_aux)
end fun

proc actualizar_ballenas(in/out C: Set of Ballenas, t: Nat) 
	var C_aux: Se of Ballenas 
	var b: Ballena 
	
	C_aux:= copy_set(C)
	
	while not is_empty_set(C_aux) do
		b:= get(C_aux)
		elim(C_aux, b)
		if t < b.s then
			elim(C, b) 
		fi
	od
	destroy_set(C_aux)
end proc
```

### Problema del teléfono satelital

Sos el flamante dueño de un teléfono satelital, y se lo ofrecés a tus n amigos para que lo lleven con ellos cuando salgan de vacaciones el próximo verano. Lamentablemente cada uno de ellos irá a un lugar diferente y en algunos casos, los períodos de viaje se superponen. Por lo tanto es imposible prestarle el teléfono a todos, pero quisieras prestárselo al mayor número de amigos posible.

Suponiendo que conoces los días de partida y regreso (pi y ri respectivamente) de cada uno de tus amigos,

Cuál es el criterio para determinar, en un momento dado, a quien conviene prestarle el equipo?

Tener en cuenta que cuando alguien lo devuelve, recién a partir del día siguiente puede usarlo otro. Escribir un algoritmo voraz que solucione el problema.

```c
Datos: 
 - n amigos
 - pi dia de partida
 - ri dia de regreso
 - Puedo usar el telefono recien un dia despues de devuelto

Quiero prestarselo al mayor numero de amigos posible

Criterio de seleccion: Se lo presto al que antes me lo devuelva

El algoritmo tomara un conjunto de amigos y devuelve una lista ordenada
de los amigos a los que les presto el telefono en orden

type Amigo = tuple
							id: string
							p: nat
							r: nat
						 end tuple

fun tel(C: Set of Amigo) ret l: List of Amigo
	var C_aux: Set of Amigo
	var amigo: Amigo
	var dia_actual: nat
	
	C_aux:= copy_set(C)
	dia:= 0
	
	while not is_empty_set(C_aux) do
		amigo:= seleccionar_amigo(C_aux)
		elim(C_aux, amigo)
		dia_actual:= amigo.r + 1
		addr(l, amigo)
		actualizar_amigos(C_aux, dia_actual)
	od
	destroy_set(C_aux)
end fun

// Criterio de seleccion
fun seleccionar_amigo(C: Set of Amigo) ret a: Amigo
	var C_aux: Set of Amigo
	var amigo: Amigo
	var dia_min: Nat
	
	C_aux:= copy_set(C)
	dia_min:= +infinito
	
	while not is_empty_set(C_aux) do
		amigo:= get(C_aux)
		elim(C_aux, amigo) 
		if amigo.r < dia_min then
			a:= amigo
			ida_min:= a.r
		fi
	od
	destroy_set(C_aux)
end fun

proc actualizar_amigos(in/out C: Set of Amigo, in d: nat)
	var C_aux: Set of Amigo
	var a: Amigo
	
	C_aux:= copy_set(C)
	
	while not is_empty_set(C_aux) do
		a:= get(C_aux)
		elim(C_aux, a)
		if d > a.p then
			elim(C, a)o
		fi
	od
	destroy_set(C_aux)
end proc	
```

### Problema de las facturas

Para obtener las mejores facturas y medialunas, es fundamental abrir el horno el menor número de veces posible. Por supuesto que no siempre es fácil ya que no hay que sacar nada del horno demasiado temprano, porque queda cruda la masa, ni demasiado tarde, porque se quema.

En el horno se encuentran n piezas de panadería (facturas, medialunas, etc). Cada pieza i que se encuentra en el horno tiene un tiempo mínimo necesario de cocción ti y un tiempo máximo admisible de cocción Ti.

Si se la extrae del horno antes de ti quedará cruda y si se la extrae después de Ti se quemará.

Asumiendo que abrir el horno y extraer piezas de él no insume tiempo, y que ti ≤ Ti para todo i ∈ {1,...,n}, qué criterio utilizaría un algoritmo voraz para extraer todas las piezas del horno en perfecto estado (ni crudas ni quemadas), abriendo el horno el menor número de veces posible?

```c
Datos: 
	- abrir el horno la menor cantidad de veces posible
	- n piezas
	- tiempo minimo ti y tiempo maximo Ti

Criterio de seleccion: sacar la que menor tiempo Ti tenga, y con esa las que
ya esten en su tiempo de coccion

El algoritmo toma un conjunto de facturas y devuelve una lista ordenada
de las facturas que se sacan

type Pieza = tuple
							id: string
							t: nat
							T: nat
						 end tuple
						 
						 
type Pieza = tuple
    id: string
    t: nat   // tiempo mínimo de cocción
    T: nat   // tiempo máximo antes de quemarse
end tuple

fun horno(C: Set of Pieza) ret l: List of Pieza
    var C_aux: Set of Pieza
    var facturas: List of Pieza
    var t_actual: nat
    var min_T: nat

    C_aux := copy_set(C)
    l := empty_list()

    while not is_empty_set(C_aux) do
        min_T := minimo(C_aux)
        t_actual := min_T
        facturas := seleccionar_facturas(C_aux, t_actual)
        concat(l, facturas)
        actualizar_facturas(C_aux, t_actual)
    od

    destroy_set(C_aux)
end fun

fun minimo(C: Set of Pieza) ret min: nat
    var C_aux: Set of Pieza
    var fac: Pieza

    C_aux := copy_set(C)
    min := +infinito

    while not is_empty_set(C_aux) do
        fac := get(C_aux)
        elim(C_aux, fac)

        if fac.T < min then
            min := fac.T
        fi
    od

    destroy_set(C_aux)
end fun

fun seleccionar_facturas(C: Set of Pieza, t: nat) ret l: List of Pieza
    var C_aux: Set of Pieza
    var fac: Pieza

    C_aux := copy_set(C)
    l := empty_list()

    while not is_empty_set(C_aux) do
        fac := get(C_aux)
        elim(C_aux, fac)

        if fac.t ≤ t and t ≤ fac.T then
            addr(l, fac)
        fi
    od

    destroy_set(C_aux)
end fun

proc actualizar_facturas(in/out C: Set of Pieza, in t: nat)
    var C_aux: Set of Pieza
    var fac: Pieza

    C_aux := copy_set(C)

    while not is_empty_set(C_aux) do
        fac := get(C_aux)
        elim(C_aux, fac)

        if fac.t ≤ t and t ≤ fac.T then
            elim(C, fac)
        fi
    od

    destroy_set(C_aux)
end proc
```


