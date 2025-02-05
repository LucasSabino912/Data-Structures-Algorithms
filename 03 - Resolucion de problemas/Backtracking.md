# Backtracking

A veces no hay un criterio de selección voraz que garantice optimalidad. Por ejemplo: problema de la moneda para conjuntos de denominaciones arbitrarios o problema de la mochila con objetos no fraccionables. 

En este caso, si se elige un fragmento de solución se puede ser necesario “volver hacia atrás” (**backtrack**) sobre esa elección e intentar otro fragmento

En la practica, estamos hablando de considerar todas las selecciones posibles e intentar cada una de ellas para saber cual conduce a la solución óptima (Backtracking = Fuerza bruta)

A diferencia de la técnica voraz, siempre hay una solución. 

En general son algoritmos ineficientes, aunque a veces no se conozca mejor alternativa

# Problema de la moneda

- Sean d1,…, dn las denominaciones de las monedas, todas mayores que 0.
- No se asume que esten ordenadas
- Se dispone de una cantidad infinita de monedas de c/denominacion
- Se desea pagar un monto k de manera exacta utilizando **el menor numero de monedas posibles**

Dado un conjunto n de denominaciones y un monto k a pagar, recursiva mente iremos probando con cada denominacion para pagar el monto, si una denominacion es factible, pruebo usarla o no. Para ello calculo el resultado en cada caso y luego obtengo el minimo

```c
fun cambio(k: Nat, C: Set of Nat) ret S: Nat
	var c: Nat
	var C_aux: Set of Nat
	// Ya llegamos a pagar el total
	if j = 0 then
		S:= 0
	// Intento fallido (probe tantas que me quede sin monedas)
	else if is_empty(C) then
		S:= inf
	else
		C_aux:= copy_set(C)
		c:= get(C)
		elim(C_aux, c)
		if c <= j then
			S:= min(1 + cambio(j-c,C), cambio(j,C_aux)
		else 
			S:= cambio(j,C_aux)
		fi
		set_destroy(C_aux)
	fi
end fun
```

La solución la obtenemos llamando a cambio(k, C)

**Condiciones base:**

- Si k = 0, se retorna S = 0 porque no se necesitan monedas.
- Si C está vacío y k > 0, se retorna S = inf porque no hay solución.

**Llamadas recursivas:** Se elige una moneda c de C y se elimina del conjunto para crear C_aux.

**Se evalúan dos casos:**

- Si c ≤ k (la moneda se puede usar): Se considera la mejor opción entre:
    - Usar la moneda c (sumando 1 al resultado de cambio(k - c, C)).
    - No usar la moneda c y probar con el conjunto C_aux.
- Si c > k (la moneda no se puede usar):
Se llama a cambio(k, C_aux) sin incluir c.

Definición con función recursiva:

Cambio(i, j) = 

> 0                                                                          j = 0
> 

> Inf                                                                        j > 0 && i = 0
> 

> Cambio(i - 1, j)                                                   di >j > 0 && i > 0
> 

> min(Cambio(i - 1, j), 1+ Cambio(i, j-di))          j ≥ di > 0 && i > 0
> 

# Problema de la panadería

Una panadería recibe *n* pedidos por importes *m1,...,mn*, pero sólo queda en depósito una cantidad *H* de harina en buen estado. Sabiendo que los pedidos requieren una cantidad *h1,...,hn* de harina *(respectivamente)*, determinar el máximo importe que es posible obtener con la harina disponible.

```c
Datos: 
	- n pedidos 
	- importes m1,..,mn
	- H cantidad de harina
	- harina necesaria j1,..,hn
	
La funcion recursiva debe tener parametros:
	- i: importes
	- j: harina

La funcion calculara la maxima cantidad de importes i que se pueda lograr con h harina

panaderia(i,j) = | 0                        si j = 0               // no hay pedidos
								 | -inf                     si i = 0 & j > 0       // Tengo pedidos pero no harina
								 | max(mi + panaderia(i-1,j-1), panaderia (i-1,j)) // Tengo pedidos y harina
```

---

La función recursiva `panaderia(i, j)` busca **maximizar la suma de los importes** de los pedidos, respetando la **cantidad de harina disponible**.

### **Explicación de la definición recursiva**

La función `panaderia(i, j)` tiene los siguientes parámetros:

- `i`: número de pedidos considerados (desde `1` hasta `n`).
- `j`: cantidad de harina disponible (desde `0` hasta `H`).

Se define con los siguientes **casos base**:

1. **Si no hay harina disponible (`j = 0`)**
    - `panaderia(i, 0) = 0`, porque no se puede producir nada sin harina.
2. **Si no hay pedidos (`i = 0`) pero hay harina (`j > 0`)**
    - `panaderia(0, j) = -∞`, porque aunque tengamos harina, no hay pedidos para procesar.
3. **Si hay pedidos y harina (`i > 0, j > 0`)**
    - Aquí tenemos dos opciones:
        1. **Tomar el pedido `i`** si hay suficiente harina:
            - Sumamos el importe `mᵢ` del pedido `i` y restamos la harina `jᵢ` que usa.
            - La recursión continúa con `panaderia(i-1, j-jᵢ)`, evaluando los pedidos anteriores con la harina restante.
        2. **No tomar el pedido `i`**:
            - La recursión continúa con `panaderia(i-1, j)`, considerando los pedidos anteriores sin usar `i`.

---

### **Ejemplo de ejecución**

Supongamos:

- `n = 3` pedidos con importes `{5, 10, 15}`
- Harina necesaria `{2, 2, 3}`
- `H = 3` de harina disponible.

**Llamada inicial:** `panaderia(3, 3)`

1. Pedido `3` (importe `15`, harina `3`):
    - Puede tomarse → `15 + panaderia(2, 0)`.
    - O no tomarse → `panaderia(2, 3)`.
2. `panaderia(2, 0)`:
    - `j = 0`, entonces `0`.
3. `panaderia(2, 3)`:
    - Pedido `2` (importe `10`, harina `2`):
        - Puede tomarse → `10 + panaderia(1, 1)`.
        - O no tomarse → `panaderia(1, 3)`.
4. `panaderia(1, 1)`:
    - Pedido `1` (importe `5`, harina `2`):
        - No se puede tomar (harina insuficiente), entonces `panaderia(0,1) = -∞`.
5. `panaderia(1, 3)`:
    - Pedido `1` (importe `5`, harina `2`):
        - Puede tomarse → `5 + panaderia(0, 1) = -∞`.
        - O no tomarse → `panaderia(0, 3) = -∞`.

---

# Problema del globo aerostático

Usted se encuentra en un globo aerostático sobrevolando el océano cuando descubre que empieza a perder altura porque la lona está levemente dañada. Tiene consigo *n* objetos cuyos pesos *p1,...,pn* y valores *v1,...,vn* conoce. Si se desprende de al menos *P* kilogramos logrará recuperar altura y llegar a tierra firme, y afortunadamente la suma de los pesos de los objetos supera holgadamente *P*. Cuál es el menor valor total de los objetos que necesita arrojar para llegar sano y salvo a la costa?

```c
Datos: 
	- n objetos
	- p1,...,pn pesos
	- v1,...,vn valores
	- peso maximo P < p1+...+pn

i: objetos
j: peso a perder

Hallar el menor valor total de los objetos

globo(i,j) = | 0             si i = 0 // no tengo objetos
						 | inf           si j > 0 & i = 0 // no tengo objetos y tengo peso a perder
						 | min(vi + globo(i-1,j-1), globo(i-1, j) // Tengo objetos
						 

La llamada a la funcion sera globo(n,P) 
```

## **Explicación de la función recursiva**

La función `globo(i, j)` tiene los siguientes parámetros:

- `i`: número de objetos considerados (desde `1` hasta `n`).
- `j`: peso objetivo que se debe alcanzar o reducir.

### **Casos base**

1. **Si no hay objetos (`i = 0`)**
    - `globo(0, j) = 0` si `j = 0`, porque no hay nada que optimizar.
    - `globo(0, j) = ∞` si `j > 0`, porque no hay objetos para alcanzar `j`, lo que indica una solución imposible.
2. **Si hay objetos (`i > 0`) y peso (`j > 0`)**, hay dos opciones:
    1. **Tomar el objeto `i`**
        - Se suma su valor `vᵢ` y se llama recursivamente con `globo(i-1, j-1)`, restando `1` unidad de `j`.
    2. **No tomar el objeto `i`**
        - Se llama recursivamente con `globo(i-1, j)`, dejando `j` sin cambios.

# Problema del telefono satelital

Sus amigos quedaron encantados con el teléfono satelital, para las próximas vacaciones ofrecen pagarle un alquiler por él. Además del día de partida y de regreso (*pi* y *ri*) cada amigo ofrece un monto *mi* por día. Determinar el máximo valor alcanzable alquilando el teléfono.

```c
Datos:
    - n amigos
    - p1,...,pn días de partida
    - r1,...,rn días de regreso
    - m1,...,mn monto por día

La función recursiva debe tener parámetros:
    - d: día actual

La función calculará el máximo monto alcanzable por el alquiler del teléfono

amigos(d) = | 0                                              si d = 0    // ya se fueron todos de vacaciones y me devolvieron el teléfono
            | max(mi * (pi-ri) + amigos(ri+1), amigos(d+1))  si d >= pi  // aún no salió de vacaciones el amigo que se más tarde sale

dónde mi * (pi - ri) es el precio al que le alquilo el teléfono a un amimgo

La llamada principal que obtiene el resultado es amigos(n)
```

La función amigos(d) representa el máximo monto que se puede obtener desde el día d en adelante.

- Casos base
    - Si d = 0 (ya se fueron todos y devolvieron el teléfono):
        No hay más dinero por ganar → amigos(0) = 0.
- Si d >= pᵢ (todavía hay amigos que no han salido de vacaciones):
    
    Se evalúan dos opciones:
    
    - Alquilar el teléfono a un amigo i que viaja en pᵢ y regresa en rᵢ, Se sigue con amigos(rᵢ + 1), que representa los días después de que i devuelva el teléfono
    - No alquilar el teléfono a i, Se sigue con amigos(d+1), evaluando los siguientes amigos. Paso al procimo dia y vuelvo a llamar a la funcion para que chequee al proximo amigo

# Problema del artesano

Un artesano utiliza materia prima de dos tipos: A y B. Dispone de una cantidad *MA* y *MB* de cada una de ellas. Tiene a su vez pedidos de fabricar *n* productos *p1,...,pn* (uno de cada uno). Cada uno de ellos tiene un valor de venta *v1,...,vn* y requiere para su elaboración cantidades *a1,...,an* de materia prima de tipo *A* y *b1,...,bn* de materia prima de tipo *B*. Cuál es el mayor valor alcanzable con las cantidades de materia prima disponible?

```c
Datos:
	- n productos
	- p1,...,pn productos
	- v1,...,vn valores de venta
	- requiere a1,...,an materia prima A
	- requiere b1,...,bn materia prima B

Mayor valor alcanzable con las cantidades de materia prima

i = producto
a = materia prima a
b = materia prima b

arte(i, a, b) = 
| 0                                               i = 0
| -inf                                            i > 0 && (a = 0 || b = 0)
| max(pi + arte(i-1,a-ai,b-bi), arte(i-1, a, b)   i > 0 && a > 0 && b > 0 

La llamada recursiva seria arte(n, A, B)
```

# Problema de las mochilas

En el problema de la mochila se buscaba el máximo valor alcanzable al seleccionar entre *n* objetos de valores *v1,...,vn* y pesos *w1,...,wn*, respectivamente, una combinación de ellos que quepa en una mochila de capacidad *W*. Si se tienen dos mochilas con capacidades *W1* y *W2*, cuál es el valor máximo alcanzable al seleccionar objetos para cargar en ambas mochilas?

```c
Datos:
	- n objetos
	- v1,...,vn valores
	- w1,...,wn valores
	- dos mochilas de capacidad W1, y W2

i : objetos
j : mochila 1
k : mochila 2

mochila(i, j, k) =
| 0                 si i = 0
| -inf              si i > 0 && (j < 0 || k < 0)
| mochila(i-1,j,k)  si j > 0 && k > 0
| max(vi + (mochila(i-1,j-1,k), mochila(i-1,j,k-1)  // Lo meto en alguna de las dos

La llamada a la funcion sera mochila(n,W1,W2)
```

# Problema del juego de mesa

El juego ↖U↑P↗ consiste en mover una ficha en un tablero de *n* filas por *n* columnas desde la fila inferior a la superior. La ficha se ubica al azar en una de las casillas de la fila inferior y en cada movimiento se desplaza a casillas adyacentes que estén en la fila superior a la actual, es decir, la ficha puede moverse a:

• la casilla que está inmediatamente arriba,

• la casilla que está arriba y a la izquierda (si la ficha no está en la columna extrema izquierda),

• la casilla que está arriba y a la derecha (si la ficha no está en la columna extrema derecha).

Cada casilla tiene asociado un número entero cij (i,j = 1,...,n) que indica el puntaje a asignar cuando la ficha esté en la casilla. El puntaje final se obtiene sumando el puntaje de todas las casillas recorridas por la ficha, incluyendo las de las filas superior e inferior. Determinar el máximo y el mínimo puntaje que se puede obtener en el juego.

```c
Datos: 
	- tablero nxn
	- Puedo mover la ficha:
		- Arriba = tablero(i+1,j)
		- Arriba izquierda = tablero(i+1,j-1)
		- Arriba derecha = tablero(i+1,j+1)
	- Puntaje de la casilla cij
	
Puntaje final: suma de todas las casillas recorridas por la ficha

up_max(i,j) = | cij                         si i = n            // llegué a la fila superior
              | -infinito                   si j < 1 ∨ j > n    // me salí del tablero por los costados
              | cij + max(up_max(i+1,j-1),
                          up_max(i+1,j),
                          up_max(i+1,j+1))  si i < n            // aún no llegué a la fila superior

La llamada principal que obtiene el resultado es up_max(1,j)

La función up_min calculará el mínimo puntaje que se puede obtener al finalizar el juego 

up_min(i,j) = 
| cij                si i = n         // llegué a la fila superior
| infinito               si j < 1 ∨ j > n // me salí del tablero por los costados
| cij + min(up_min(i+1,j-1),
            up_min(i+1,j),
            up_min(i+1,j+1))  si i < n  // aún no llegué a la fila superior

La llamada principal que obtiene el resultado es up_min(1,j)
```