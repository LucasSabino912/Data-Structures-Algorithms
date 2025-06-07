
# Backtracking

A veces no hay un criterio de selección voraz que garantice optimalidad. Por ejemplo: problema de la moneda para conjuntos de denominaciones arbitrarios o problema de la mochila con objetos no fraccionables.

En este caso, si se elige un fragmento de solución se puede ser necesario “volver hacia atrás” (**backtrack**) sobre esa elección e intentar otro fragmento

En la practica, estamos hablando de considerar todas las selecciones posibles e intentar cada una de ellas para saber cual conduce a la solución óptima (Backtracking = Fuerza bruta)

A diferencia de la técnica voraz, siempre hay una solución.

En general son algoritmos ineficientes, aunque a veces no se conozca mejor alternativa

### **Problema de la moneda**

- Sean d1,…, dn las denominaciones de las monedas, todas mayores que 0.
- No se asume que esten ordenadas
- Se dispone de una cantidad infinita de monedas de c/denominacion
- Se desea pagar un monto k de manera exacta utilizando **el menor numero de monedas posibles**

Dado un conjunto n de denominaciones y un monto k a pagar, recursiva mente iremos probando con cada denominacion para pagar el monto, si una denominacion es factible, pruebo usarla o no. Para ello calculo el resultado en cada caso y luego obtengo el minimo

La solución la obtenemos llamando a cambio(k, C)

**Condiciones base:**

- Si k = 0, se retorna S = 0 porque no se necesitan monedas.
- Si C está vacío y k > 0, se retorna S = inf porque no hay solución.

**Llamadas recursivas:** Se elige una moneda c de C y se elimina del conjunto para crear C_aux.

**Se evalúan dos casos:**

- Si c ≤ k (la moneda se puede usar): Se considera la mejor opción entre:
    - Usar la moneda c (sumando 1 al resultado de cambio(k - c, C)).
    - No usar la moneda c y probar con el conjunto C_aux.
- Si c > k (la moneda no se puede usar): Se llama a cambio(k, C_aux) sin incluir c.

Definición con función recursiva:

```c
Tengo i monedas para pagar un monto j
Tengo di denominaciones

cambio(i,j) = 
	| 0        si j = 0 // Ya pague
	| inf      si j > 0 && i = 0 // No tengo monedas pero si monto restante
	| cambio (i-1, j)   si di > j > 0 && i > 0 // no elijo esa moneda 
	// Elijo la moneda, minimo entre no elegirla y si elegirla (+1 a la sol.)
	| min(Cambio(i - 1, j), 1 + Cambio(i, j-di))       si j ≥ di > 0 && i > 0
	
```

### Problema de la panaderia

Una panadería recibe *n* pedidos por importes *m1,...,mn*, pero sólo queda en depósito una cantidad *H* de harina en buen estado. Sabiendo que los pedidos requieren una cantidad *h1,...,hn* de harina *(respectivamente)*, determinar el máximo importe que es posible obtener con la harina disponible.

```c
Datos:
 - n pedidos
 - H harina
 - los pedidos requieren h1, ..., hn harina
 - los pedidos tienen m1, ..., mn importes

Determinar el maximo importe que es posible obtener con H harina

Tengo i cantidad total de pedidos
Tengo j cantidad total de harina

panaderia(i, j) = 
	| 0                  si i = 0 o j = 0   // No tenfo pedidos o harina
	| panaderia(i-1,j)   si i > 0 && hi > j // NO elijo el pedido
	| max(panaderia(i-1, j), mi + panaderia(i-1,j-hi) si i > 0 && j > hi > 0 
	// Busco el maximo entre no elegir el pedido o elegirlo
La llamada recursiva que resuelve sera panaderia(n, H)
```

### Problema del globo aerostatico

Usted se encuentra en un globo aerostático sobrevolando el océano cuando descubre que empieza a perder altura porque la lona está levemente dañada. Tiene consigo *n* objetos cuyos pesos *p1,...,pn* y valores *v1,...,vn* conoce. Si se desprende de al menos *P* kilogramos logrará recuperar altura y llegar a tierra firme, y afortunadamente la suma de los pesos de los objetos supera holgadamente *P*. Cuál es el menor valor total de los objetos que necesita arrojar para llegar sano y salvo a la costa?

```c
Datos: 
	- n objetos
	- p1,...,pn pesos
	- v1,...,vn valores
	- Debo desprenderme de P kilogramos

Debo desprenderme de los objetos buscando llegar al peso P y perder el minimo
valor posible en objetos

i objetos 
j peso

Cuando j llegue a 0, es que ya llegue al minimo peso para desprenderme

globo(i,j) = 
	| 0        si j <= 0
	| inf      si i = 0 & j > 0
	| globo(i-1,j) si i > 0 & pi > j
	| min(globo(i-1,j), vi + globo(i-1,j-pi)) si i > 0 && j >= pi
	
La llamada sera globo(n,P)
```

### Problema del teléfono setelital

Sus amigos quedaron encantados con el teléfono satelital, para las próximas vacaciones ofrecen pagarle un alquiler por él. Además del día de partida y de regreso (*pi* y *ri*) cada amigo ofrece un monto *mi* por día. Determinar el máximo valor alcanzable alquilando el teléfono.

```c
Datos: 
 - n amigos
 - p1,...,pn partida
 - r1,...,rn regreso
 - monto mi por dia
 
Determinar el maximo valor alcanzable alquilando el telefono
i amigos
d dia actual

tel(i,d) = 
	| 0              si i = 0
	| tel(i-1,d)     si pi > d
	| max(tel(i-1,d), 
	mi.(ri-pi+1) + tel(i-1,pi) + d) 
	si i > 0 & pi <= d

La llamada recursiva sera tel(n,D)
```

### Problema del artesano

Un artesano utiliza materia prima de dos tipos: A y B. Dispone de una cantidad *MA* y *MB* de cada una de ellas. Tiene a su vez pedidos de fabricar *n* productos *p1,...,pn* (uno de cada uno). Cada uno de ellos tiene un valor de venta *v1,...,vn* y requiere para su elaboración cantidades *a1,...,an* de materia prima de tipo *A* y *b1,...,bn* de materia prima de tipo *B*. Cuál es el mayor valor alcanzable con las cantidades de materia prima disponible?

```c
Datos:
 - n productos p1,..,pn
 - v1,..,vn valores
 - a1,..,1n y b1,..,bn materia prima 

Hallar el mayor valor alcanzable con la materia prima disponible
i productos
a materia prima A
b materia prima B

a(i,a,b) = 
	| 0          si i = 0
	| a(i-1,a,b) si ai > a || bi > b
	| max(a(i-1,a,b), vi + a(i-1,a - ai,b - bi)) si i > 0 && a >= ai && b >= bi 

La llamada recursiva sera a(n,A,B)
```

### Problema de la mochila

En el problema de la mochila se buscaba el máximo valor alcanzable al seleccionar entre *n* objetos de valores *v1,...,vn* y pesos *w1,...,wn*, respectivamente, una combinación de ellos que quepa en una mochila de capacidad *W*. Si se tienen dos mochilas con capacidades *W1* y *W2*, cuál es el valor máximo alcanzable al seleccionar objetos para cargar en ambas mochilas?

```c
Datos:
 - n objetos
 - v1,..,vn valores
 - w1,..,wn pesos
 - W1 y W2 mochilas de capacidad W

Se debe buscar el maxumo valor alcanzable al selecionar objetos de ambas mochilas

i objetos
j capacidad W1
k capacidad W2

mochila(i,j,k) = 
	| 0                 si i = 0 || (j = 0 && k = 0)
	| mochila(i-1,j,k)  si wi > j && wi > k
	| max(mochila(i-1,j,k), 
	  vi + mochila(i-1,j-wi,k),
	  vi + mochila(i-1,j,k-wi),   si wi <= j || wi <= k
	  
La llamada principal ser mochila(n,W1,W2)
```


