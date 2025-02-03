# Greedy algorithms

Es la tecnica mas sencilla de resolucion de problemas. Normalmente se trata de algoritmos que resuelven problemas de optimizacion, por ejemplo:

- Camino mas corto entre dos ciudades
- Valor maximo alcanzable entre ciertos objetos
- Csoto minimo para proveer cierto servicio
- Menor numero de billetes para pagar un importe

### Caracteristicas

- Nuna revisan una eleccion ya realizada
- Confian en haber elegido bien las componentes anteriores
- No todos admiten solucion voraz
- Dichas soluciones resultan eficientes

### Forma general

- Se tiene un problema a resolver de manera optima
- Un conjunto de candidatos a integrar la solucion
- Los candidatos se clasifican en 3:
    - Los aun no considerados
    - Los incorporados a la solucion parcial
    - Los descartados
- Tenemos una manera de saber si los candidatos ya incirporados completan una solcucion al sistema
- Una funcion comprueba si un candidato o cjto de candidatos es factible de formar parte de la solucion
- Otra funcion que seleccione entre los candidatos no considerados el mas promisorio

### Pasos a seguir para un algoritmo greedy

1. Plantear un problema donde se toma una decision y nos quedamos con un sobrpblema que se pueda resolver
2. Probamos que siempre hay una solucion optima al tomar la eleccion freedy, osea, probar que la decision fuie correcta y se puede seguir con el problema
3. Crear una subestructura optima, enseñando que combinando el subproblema con la eleccion greedy, nos queda la solucion total

### ¿Como se que la solucion es suficiente?

La **propiedad de la seleccion greedy** dice que podemos ensamblar una solucion optima global haciendo elecciones greedys locales, en otras palabras, cuando consideramos que eleccion hacer lo hacemos sin tomar en cuenta resultados de subproblemas

El problema debe tener una **subestructura optima,** cuando una solucion optima del problema general, incorpora soluciones opotimas de subproblemas generados

## Esquema general

```c
// p es un input con informacion del problema
fun voraz(C: set of Candidate, p: ProbData) ret s: solution
	var c: Candidate
	var p_aux: ProbData
	var C_aux: Set of candidate
	
	S := base_solution()
	
	C_aux := set_copy(C)
	p_aux := p
	
	if(not problem_solvable(C, p)) -> S _= error_solution()
	else 
		do (not problem_is_solved(p_aux)) ->
			c:= select_candidate(c)
			elim(C_aux, c)
			
			if is_feasible(c) ->
				S := modify_solution(S, c , p_aux)
				p_aux := modify_problem(p_aux, c)
			fi
		od
	fi
	set_destroy(C_aux)
end fun
```

# Problema de la moneda

Tenemos una cantidad infinita de monedas de:

- 1 peso
- 50 centavos
- 25 centavos
- 10 centavos
- 5 centavos
- 1 centavo

Se desea pagar un cierto monto de manera exacta y con la menor cantidad de monedas posibles. Se debe **seleccionar una moneda de la mayor denominacion posible** (Criterio de seleccion) que no exceda el monto a pagar. Utilizar el mismo algoritmo para el importe remanente.

## Version 1

```c
fun cambio (m: Nat, C: Set of Nat) ret S: Nat
  var c, resto: Nat
  var C_aux: Set of Nat
  S := 0
  C_aux = copy_set(C
  resto := m    
  while resto > 0 do 
    c := max(C_aux) // Elijo la moneda de mayor denominación disponible
    elim(C_aux, c) // Elimino esta moneda del conjunto 
    // cuántas monedas de esta denominación usamos y sumamos al contador
    S := S + resto 'div' c
    // Calculo el monto restante después de usar estas monedas
    resto := resto 'mod' c 
  od
  set_destroy(C_aux) // Liberacion de memoria del conjunto auxiliar
end fun
```

## Version 2

```c
fun cambio (m: Nat, C: Set of Nat) ret S: Nat
  var c, resto: Nat
  var C_aux: Set of Nat
  S := 0
  C_aux = copy_set(C)
  resto := m  
  while (not is_empty(C_aux)) do
	  c:= max(C_aux)
	  if c > resto then // Chequeo factibilidad
		  elim(C_aux, c)
		else 
			resto := resto - c
			S := S + 1
	  fi
	od
	set_destroy(C_aux)
end fun
```

## Version 3: Devolviendo el valor de cada moneda

```c
fun cambio (m: Nat, C: Set of Nat) ret S: List of Nat
  var c, resto: Nat
  var C_aux: Set of Nat
  S := empty_list()
  C_aux = copy_set(C)
  resto := m  
  while (not is_empty(C_aux)) do
	  c:= max(C_aux)
	  if c > resto then // Chequeo factibilidad
		  elim(C_aux, c)
		else 
			resto := resto - c
			addl(S, c) // Agrego a la solucion
		fi
	od
	set_destroy(C_aux)
end fun
```

# Problema de la mochila

- Tenemos una mochila de capacidad W
- Tenemos n objetos de valor v1, v2, …, vn y peso w1, w2, …, wn
- Se quiere encontrar la mejor seleccion de objetos para llevar en la mochila
- Por mejor seleccion se entiende a aquella que totaliza el mayor valor posible sin que su peso exceda la capacidad W de la mochila
- Para que el problema no sea trivial se asume que la suma de los n objetos es mayor a W

El criterio de seleccion sera combinando entre los mas valiosos y los mas livianos, ya que hay que asegurarnos que cada kg utilizado en la mochikla sea utilzado de la mejor manera posible y cada kg valga lo mas posible.

Este problema no tiene solucion voraz, pero se simplifica permitiendo fraccionar objetos

```c
type Objeto = tuple
								id: Nat
								value: Float
								weight: Float
							end tuple

type obj_mochila = tuple
												obj: Objeto
												frac: Float // La fraccion del objeto que recibo
											 end tuple

fun mochila(W: Float, C: Set of Objeto) ret L: List of obj_mochila
	var o_m : obj_mochila
	var resto: Float
	var C_aux : Set of Objeto
	S := empty_list()
	C_aux := set_copy(C)
	resto := W
	while resto > 0 do
		o_m.obj := select_obj(C_aux)
		if o_m.obj.weight <= resto then
			o_m.frac := 1.0
			resto := resto - o_m.obj.weight
		else 
			o_m.frac := resto/o_m.obj.weight
			resto := 0
		fi
		addl(S, o_m)
		elim(C_aux, o_m.obj)
	od
	set_destroy(C_aux)
end fun
		
// Ahora implemento el criterio de seleccion
fun select_obj(C: Set of Objeto) ret r : Objeto
	var C_aux : Set of Objeto
	var o : Objeto
	var m : Float
	m := -inf
	C_aux := set_copy(C)
	while !is_empty_set(C_aux) do
		o := get(C_aux)
		if o.value/o.weight > m then
			m := o.value/o.weight // Busco la relacion valor peso maxima
			r := 0
		fi
		elim(C_aux, o)
	od
	set_destroy(C)
end fun
```

# Problema de las localidades

Se desea realizar un viaje en automovil con autonomía A (en km), desde la localidad l0 hasta la localidad ln, pasando por l1, …, ln-1 en ese orden. Se conoce cada distancia di ≤ A entre la localidad li - 1 y la localidad li (1 ≤ i ≤ n), y se sabe que hay una  estación de servicio en cada una de las localidades

Escribir un algoritmo que compute el menor número de veces que es necesario cargar combustible para realizar el viaje, y las localidades donde se realizaría la carga.

Suponer que inicialmente el tanque de combustible esta vacío y que todas las estaciones cuentan con suficiente combustible 

```c
Criterio de seleccion: cargo en la localidad en la que me quede sin combustible necesario
para llegar a la localidad siguiente

- Autonomia A
- Localidades l0 ... ln
- Distancias d1 ... dn
- Donde di es la distancia entre li-1 y li

La solucion sera una tupla compuesta por un natural que me indica la cantidad de cargas y 
y una lista de las localidades donde cargo combustible en orden

En el algoritmo realizo la primera carga en la localidad 0, luego busco aquella distancia
que no pueda recorrer por falta de combustible y la agreo a la lista de cargas, hago lo 
mismo hasta llegar a destino

type cargas = tuple
								cant: Nat
								localidades : List of string
							end tuple

fun carga_combustible(A: Nat, l: list of string, d: List of nat) ret res: Set of cargas
	var localidades: list of string
	var localidad: string
	var combustinle: nat
	var i: nat
	
	localidades:= copy_list(l)
	i:= 0
	
	// Agrego la primera carga
	res.cant:= 1
	res.localidades:= empty_list()
	// Agrego la localidad a la lista y la elimino
	addr(s.localidades, head(localidades))
	tail(localidades)
	combustible:= A
	i:= i + 1
	
	while(length(localidades) > 1) do
		localidad:= head(localidades)
		tail(localidades)
		combustible:= combustible - index(d,i)
		
		// Criterio de seleccion
		if combustible < index(d,i+1) then
			addr(res.localidades, c)
			res.cant:= res.cant + 1
			combustible:= A
		fi
		i:= i + 1
	od
	destroy_list(localidades)
end fun
	
```

# Problema de las ballenas

En numerosas oportunidades se ha observado que cientos de ballenas nadan juntas hacia la costa y quedan varadas en la playa sin poder moverse. Algunos sostienen que se debe a una pérdida de orientación posiblemente causada por la contaminación sonora de los océanos que interferiría con su capacidad de inter-comunicación. En estos casos los equipos de rescate realizan enormes esfuerzos para regresarlas al interior del mar y salvar sus vidas.

Se encuentran n ballenas varadas en una playa y se conocen los tiempos s1,s2,...,sn que cada ballena es capaz de sobrevivir hasta que la asista un equipo de rescate. Dar un algoritmo voraz que determine el orden en que deben ser rescatadas para salvar el mayor número posible de ellas, asumiendo que llevar una ballena mar adentro toma tiempo constante t, que hay un único equipo de rescate y que una ballena no muere mientras está siendo regresada mar adentro.

```c
- Criterio de seleccion: La ballena con menos tiempo restante de vida

- Datos
	- n ballenas
	- tiempos de vida s1,..., sn
	- tiempo t que lleva salvar a una ballena

- La solucion sera una lista de ballnas en el orden de rescate

- Primer elijo la ballena con menor tiempo de vida, la rescato y actualizo la 
  lista de ballenas disponibles para rescatar, en el siguiente paso elijo la 
  ballena con menor tiempo de vida y vuelvo a repetir
  
  
type Ballena = tuple 
								id: Nat
								tiempo: Nat
							 end tuple
							 
							 
// Función principal que rescata ballenas en un tiempo determinado.
fun ballenas(t: Nat, ballenas: Set of Ballena) ret: rescatadas: List of Ballena
    var vivas: Set of Ballena  // Conjunto de ballenas que aún no han sido rescatadas
    var ballena: Ballena  // Variable auxiliar para almacenar la ballena seleccionada
    var tiempo_actual: Nat  // Tiempo total transcurrido durante los rescates

    // Copia el conjunto de ballenas para trabajar sin modificar el original
    vivas := copy_set(ballenas)

    // Inicializa la lista de ballenas rescatadas como vacía
    rescatadas := empty_list()

    // Inicializa el tiempo en 0
    tiempo_actual := 0

    // Mientras aún haya ballenas por rescatar
    while not is_empty_set(vivas) do
        // Selecciona una ballena según algún criterio
        ballena := elegir_ballena(vivas)
        
        // Elimina la ballena del conjunto de ballenas vivas (ya será rescatada)
        elim(vivas, ballena)

        // Agrega la ballena a la lista de rescatadas
        addr(rescatadas, ballena)

        // Aumenta el tiempo total en la cantidad dada por 't'
        tiempo_actual := tiempo_actual + t

        // Actualiza el conjunto de ballenas vivas eliminando aquellas que ya no pueden ser rescatadas
        actualizar_vivas(vivas, t)
    od

    // Limpia la memoria del conjunto de ballenas vivas
    destroy_set(vivas)
end fun

// Función que selecciona la ballena con menor tiempo disponible para el rescate
fun elegir_ballena(ballenas: Set of Ballena) ret ballena: Ballena
    var cp_ballenas: Set of Ballena  // Copia del conjunto de ballenas para no modificar el original
    var ballena: Ballena  // Variable auxiliar para iterar sobre las ballenas
    var min_tiempo: Nat  // Variable para almacenar el menor tiempo de rescate encontrado

    // Copia el conjunto de ballenas
    cp_ballenas := copy_set(ballenas)

    // Inicializa el mínimo tiempo con un valor muy grande (+infinito)
    min_tiempo := +infinito

    // Mientras haya ballenas en la copia del conjunto
    while not is_empty_set(cp_ballenas) do
        // Obtiene una ballena de la copia del conjunto
        ballena := get(cp_ballenas)
        
        // La elimina del conjunto temporal para evitar procesarla de nuevo
        elim(cp_ballenas, ballena)

        // Si esta ballena tiene el menor tiempo de rescate hasta ahora, la actualizamos
        if ballena.tiempo < min_tiempo then
            b := ballena
            min_tiempo := ballena.tiempo
        fi
    od

    // Libera la memoria del conjunto copiado
    destroy_set(cp_ballenas)
end fun

// Procedimiento que elimina ballenas del conjunto si su tiempo de rescate ha expirado
proc actualizar_vivas(in/out ballenas: Set of Ballena, in t: Nat)
    var cp_ballenas := copy_set(ballenas)  // Copia del conjunto para recorrerlo sin modificar el original
    var ballena: Ballena  // Variable auxiliar para iterar sobre las ballenas

    // Mientras haya ballenas en la copia
    while not is_empty_set(cp_ballenas) do
        // Obtiene una ballena del conjunto
        ballena := get(cp_ballenas)
        
        // La elimina de la copia temporal
        elim(cp_ballenas, ballena)

        // Si el tiempo de la ballena es menor que 't', significa que ya no puede ser rescatada
        if ballena.tiempo < t then
            elim(ballenas, ballena)  // Se elimina del conjunto original
        fi
    od

    // Libera la memoria del conjunto copiado
    destroy_set(cp_ballenas)
end fun

	
```

# Problema del telefono satelital

Sos el flamante dueño de un teléfono satelital, y se lo ofrecés a tus n amigos para que lo lleven con ellos cuando salgan de vacaciones el próximo verano. Lamentablemente cada uno de ellos irá a un lugar diferente y en algunos casos, los períodos de viaje se superponen. Por lo tanto es imposible prestarle el teléfono a todos, pero quisieras prestárselo al mayor número de amigos posible.

Suponiendo que conoces los días de partida y regreso (pi y ri respectivamente) de cada uno de tus amigos,

Cuál es el criterio para determinar, en un momento dado, a quien conviene prestarle el equipo?

Tener en cuenta que cuando alguien lo devuelve, recién a partir del día siguiente puede usarlo otro. Escribir un algoritmo voraz que solucione el problema.

```c
- Criterio de seleccion: El que me devuelva el telefono antes

- Datos: 
	- n amigos
	- p1,..., pn fechas de partida
	- r1,..., rn fechas de regreso
	- Puedo prestarlo un dia despues, osea, ri + 1

- La solucion sera un natural que me diga a cuantos amigos lo preste

- El algoritmo selecciono al amigo con menor fecha de regreso, lo presto,
  sumo a la solucion y cuando me lo devuelve actualizo la lista de amigos, 
  eliminando a aquellos que ya hayan partido
  
  
type Amigo = tuple
							nombre: string
							partida: date
							regreso: date
						 end tuple

fun prestar_tel(a: set of Amigo) ret res: nat
	var amigos: Set of Amigo
	var amigo: Amigo
	var diaActual: date
	
	amigos:= copy_set(a)
	dia_actual:= 0
	res:= 0
	
	while not is_empty_set(amigos) do
		amigo:= seleccionar_amigo(amigos)
		elim(amigos, amigo)
		res:= res + 1
		diaActual:= amigo.regreso
		actualizar_amigos(amigos, diaActual
	od
	set_destroy(amigos)
end fun
	
fun seleccionar_amigo(a: Set of Amigo, diaActual: date) ret a: Amigo
	var amigos: Set of Amigo
	var amigo: Amigo
	var dia_cerano: date
	
	amigos:= copy_set(a)
	dia_cercano:= infinito
	
	while no is_empty_set(amigos) do
		amigo:= get(amigos)
		elim(amigos, amigo)
		if amigo.regreso <= dia_cercano then
			a:= amigo
			dia_cercano:= amigo.regreso
		fi
	od
	destroy_set(amigos)
end fun

proc actualizar_amigos(in/out a: Set of amigos, in dia_actual: date)
	var cp_amigos: Set of Amigos
	var amigo: Amigo
	
	cp_amigos:= copy_set(a)
	
	while no is_empty_set(cp_amigos) do
		amigo:= get(cp_amigos)
		elim(amigos, amigo)
		if amigo.partida > dia_acutal then
			elim(a, amigo)
		fi
	od
	destroy_set(cp_amigos)
end proc
```

# Problema de las facturas

Para obtener las mejores facturas y medialunas, es fundamental abrir el horno el menor número de veces posible. Por supuesto que no siempre es fácil ya que no hay que sacar nada del horno demasiado temprano, porque queda cruda la masa, ni demasiado tarde, porque se quema.

En el horno se encuentran n piezas de panadería (facturas, medialunas, etc). Cada pieza i que se encuentra en el horno tiene un tiempo mínimo necesario de cocción ti y un tiempo máximo admisible de cocción Ti.

Si se la extrae del horno antes de ti quedará cruda y si se la extrae después de Ti se quemará.

Asumiendo que abrir el horno y extraer piezas de él no insume tiempo, y que ti ≤ Ti para todo i ∈ {1, ... , n}, qué criterio utilizaría un algoritmo voraz para extraer todas las piezas del horno en perfecto estado (ni crudas ni quemadas), abriendo el horno el menor número de veces posible?

```c
- Criterio de seleccion: Saco primero la pieza que menos tarde en quemarse

- Datos
	- n piezas
	- t1,...,tn tiempos minimos de coccion
	- T1,...,Tn tiempos maximos de coccion
	- cada pieza tiene un intervalo [ti,Ti] de coccion

- La solucion sera un natural que me indique cuantas veces abro el horno para 
  cocinar en perfecto estado todas las piezas
  
- Elijo la pieza que deba sacar del horno antes de quemarse, verifico tambien
  que otras piezas se encuentren en el intervalo de coccion y tambien las saco
  
  
type Factura = tuple
								id: String
								min: Nat
								max: Nat
							 end tuple

// PRE: ti <= Ti
fun horno(f: Set of Factura) ret h: Nat
	var cp_facturas: Set of Factura
	var factura: Factura
	vae t_actual: Nat
	
	cp_facturas:= copy_set(f)
	t_actual:= 0
	h:= 0
	
	// Mientras queden piezas en el horno
	while not is_empty_set(cp_facturas) do
		factura:= elegir_factura(cp_facturas)
		elim(cp_facturas, factura)
		t_actual:= factura.max
		elim_cocinadas(f, t_actual)
		h:= h + 1
	od
	destroy_set(cp_facturas)
end fun

fun elegir_factura(f: Set of Factura) ret factura: Factura
	var cpf: Set of Factura
	var fac: Factura
	var min: Nat
	
	min:= infinito
	cpf:= copy_set(f)
	
	while not is_empty_set(cpf) do
		fac:= get(cpf)
		elim(cpf, fac)
		if fac.max <= min then
			factura:= fac
			min:= fac.max
		fi
	od
	destroy_set(cpf)
end fun

proc elim_cocinadas(in/out f: Set of Factura, t: Nat)
	var cpf: Set of Factura
	var factura: Factura
	
	cpf:= copy_set(f)
	
	while not is_empty_set(cpf) do
		factura:= get(cpf)
		elim(cpf, factura)
		if factura.min <= t then
			elim(f, factura)
		fi
	od
	destroy_set(cpf)
end fun
// POST: no hay facuras tal que p.min <= t
```

# Problema del submarino

Un submarino averiado descansa en el fondo del océano con n sobrevivientes en su interior. Se conocen las cantidades c1, ... , cn de oxígeno que cada uno de ellos consume por minuto. El rescate de sobrevivientes se puede realizar de a uno por vez, y cada operación de rescate lleva t minutos.

a) Escribir un algoritmo que determine el orden en que deben rescatarse los sobrevivientes para salvar al mayor número posible de ellos antes de que se agote el total C de oxígeno.

b) Modificar la solución anterior suponiendo que por cada operación de rescate se puede llevar a la superficie a m sobrevivientes (con m ≤ n).

```c
- Datos:
	- n sobrevivientes
	- Cada sobreviviente consume c1,...,cn oxigeno
	- Se puede resvatar un solo superviviente por vez
	- Cada recate lleva t tiempo
	- C oxigeno restante

- Criterio de seleccion: El sobreviviente que mas oxigeno consuma

- La solucion sera una lista de sobrevivientes rescatados en orden

type sobreviviente = tuple
											nombre: String
											c: Nat
										 end tuple

fun sub(s: Set of Sobreviviente, C: Nat, t: Nat) ret res: List of Sobreviviente
	var cps: Set of Sobreviviente
	var sobreviviente: Sobreviviente
	var oxres: Nat
	
	cps:= copy_set(s)
	oxres:= C
	res:= empty_list()
	
	while not is_empty_set(cps) do
		sobreviviente:= elegit_sobreviviente(cps)
		elim(cps, sobreviviente)
		addr(res, sobreviviente)
		actualizar_oxigeno(cps, t, oxres)
	od
	set_destroy(cps)
end fun

fun elegir_sobreviviente(s: Set of Sobreviviente) res s: Sobreviviente
	var cps: Set of Sobreviviente
	var sobreviviente: Sobreviviente
	var max_consum: Nat
	
	cps:= copy_set(s)
	max_consum:= -infinito
	
	while not is_empty_set(cps) do
		sobreviviente:= get(cps)
		elim(cps, sobreviviente)
		if sobreviviente.c >= max_consum then
			s:= sobreviviente
			max_consum:= sobreviviente.c
		fi
	od
	destroy_set(cps)
end fun

fun actualizar_oxigeno(s: Set of Sobreviviente, t: Nat, oxres: Nat) ret res: Nat
	var cps: Set of Sobreviviente
	var sobreviviente: Sobreviviente
	
	cps:= copy_set(s)
	res:=  0
	
	while not is_empty_set(cps) then
		sobreviviente:= get(cps)
		elim(cps, sobreviviente)
		res:= res - (sobreviviente.c * t)
	od
	destroy_set(cps)
end fun
```

# Problema de la limonada

(sobredosis de limonada) Es viernes a las 18 y usted tiene ganas de tomar limonada 
con sus amigos. Hay n bares cerca, donde cada bar i tiene un precio Pi de la pinta de limonada y un horario de happy hour Hi, medido en horas a partir de las 18 (por ejemplo, si el happy hour del bar i es hasta las 19, entonces Hi = 1), en el cual la pinta costará un 50% menos. Usted toma una cantidad fija de 2 pintas por hora y no se considera el tiempo de moverse de un bar a otro. Se desea obtener el menor dinero posible que usted puede gastar para tomar limonada desde las 18 hasta las 02 am (es decir que usted tomará 16 pintas) eligiendo en cada hora el bar que más le convenga.

```c
- El problema nos da los siguientes datos:
    - n bares
    - P1,...,Pn precios de la limonada
    - H1,...,Hn horas de happy hour a partir de las 18hs
    - Pi = Pi/2 en horas de happy hour
    - 2 pintas por hora
    - 8hs tomando limonada  

- Criterio de selección: el bar que tenga el precio más económico en una hora dada

- La solución será un entero que representa el menor precio que debo pagar por tomar
  limonada desde las 18hs hasta las 02am

- En el algorítmo elijo por cada hora el bar que esté en período de happy hour y que
  tenga la pinta de limonada más económica y sumo el precio de 2 pintas al resultado
  final, actualizo la hora y vuelvo a repetir el proceso hasta que se hagan la 1am y
  deba elegir el último bar 

type bar = tuple
              H: nat
              P: nat
           end tuple

fun limonada(b: set of bar, n: nat) ret res: nat
    var bares: set of nat
    var bar: bar
    var h_actual: nat

    bares:= copy_set(b)
    h_actual:= 18
    res:= 0

    while(h_actual < n) do
        bar:= elegir_bar(bares, h_actual)   {- eligo el bar con menor precio que esté en happy hour -}
        res:= res + bar.P                   {- el happy_hour nos deja al 50% la limonada, basta con sumar el precio real de una sola -}
        h_actual:= h_actual + 1             {- actualizo la hora -}
    od
    destroy_set(bares)
end fun

{- PRE: not is_empty_set(b) -}
fun elegir_bar(b: set of bar, h: nat) ret res: bar
    var bares: set of nat
    var bar: bar
    var precio_min: nat
    bares:= copy_set(b)
    precio_min:= infinito
    
    while(not is_empty_set(bares)) do
        bar:= get(bares)
        elim(bares, bar)

        {-
            elijo el bar que esté en horario de happy hour
            (horario de happy hour <= hora actual)
            y que tenga el menor precio de la pinta
        -}
        if (bar.H + 18 <= h ∧ bar.P < precio_min) then
            res:= bar
            precio_min:= bar.P

        {- caso que ningun bar tenga happy hour -}
        else if (bar.P * 2 < precio_min) then
            res:= bar
            precio_min:= bar.P * 2
        fi
    od
    destroy_set(bares)
end fun
```