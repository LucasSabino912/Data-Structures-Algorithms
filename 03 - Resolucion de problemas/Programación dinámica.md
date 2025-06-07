# Programacion dinamica

La programacion dinamica es un metodo para transformar una definicion recursiva, como un problema de backtracking, en una definicion iterativa, a traves de una **tabla de valores**

El objetico es evitar la reiteracion de computos, un ejemplo seria la definicion de la secuencia de Fibonacci

```c
fn =
	|n     n ≤ 1
	|fn-1 + fn-2     n > 1
```

Esta funcion recursiva es exponencial, la razon es que el calculo de fn lleva a calcular:

2 veces fn-2, 3 veces fn-3, 5 veces fn-4, etc.

**¿Como evitar tantos recalculos?**

Llevando una tabla de valores calculados comenzando desde los casos base.

Sea f un arreglo de 0 a n:

- f[0]:= 0
- f[1]:= 1
- f[2]:= f[0] + f[1]
- f[3]:= f[2] + f[1]

**Fibonacci a traves de una tabla**

```c
{ PRE: n > 1 }
fun fib(n: nat) ret r: nat
	var f: array[0..n] of nat
	f[0]:= 0
	f[1]:= 1
	for i:= 2 to n do
		f[i]:= f[i-1] + f[i-2]
	od
	r:=f[n]
end fun
```

Este algoritmo paso de ser exponencial a ser lineal O(n)

**Problema de la moneda**

```
cambio(i,j) =
	| 0        j = 0
	| inf      j > 0 && i = 0
	| min(cambio(i-1,j), 1+cambio(i,j-di)    j >= d1 > 0 && i > 0
```

Este problema puede llegar a ser exponencial debido a las dos llamadas recursivas que tiene el último caso.

- Habiendo dos parámetros, la tabla sera una matriz en vez de un vector como en el caso de Fibonacci
- Los casos base corresponden al llenado de la primera columna y primera fila de la matriz

```c
fun cambio(d:array[1..n] of nat, k: nat) ret r: nat
	var cam: array[0..n,0..k] of nat
	for i:=0 to n do cam[i,0]:=0 od
	for j:=0 to k do cam[0,1]:=inf od
	for i:=1 to n do
		for j:1 to k do
			if d[i] > j then
				cam[i,j]:= cam[i-1,j]
			else
				cam[i,j]:= min(cam[i-1,j], 1 + cam[i,j-d[i]])
			di
		od
	od
	r:=cam[n,k]
end fun
```

**Problema de la mochila**

```c
fun mochila(v:array[1..n] of valor, w:array[1..n] of nat, W: nat) ret r: Valor
	var moch:array[0..n,0..W] of Valor
	for i:= to n do moch[i,0]:=0 od
	for j:= to W do moch[0,j]:=0 od
	for i:=1 to n do
		for j:=1 to W do
			if w[i] > j then
				moch[i,j]:= max(moch[i-1,j],v[i]+moch[i-1],j-w[i]])
			fi
		od
	od
	r:=moch[n,W]
end fun
```

### Problema del cambio

Dar una definición de la función cambio utilizando la técnica de programación dinámica a partir de la siguiente definición recursiva (backtracking):

```c
cambio(i, j) = 
| 0                     si j = 0
| infinito              si j > 0 ∧ i = 0
| min q∈{0,1,...,j÷di} (q + cambio(i−1, j−q ∗ di))   si j > 0 ∧ i > 0
```

```c
fun cambio (monedas: array[1..n] of nat, c: nat) ret res: nat
    var a: array[0..n,0..c] of nat
    
    for i:= 0 to n do a[i,0]:= 0        {- el monto a devolver es 0 -}
    for i:= 0 to c do a[0,i]:= infinito {- tengo que devolver cambio, no tengo monedas -}

    for i:= 1 to n do
        for j:= 1 to c do
            a[i,j]:= min q∈{0,1,...,j÷di} (q + cambio(i−1, j−q ∗ di))
        od
    od
    res:= a[n,c]
end fun

```

### Problema de la panaderia

```c
Datos:
	- n pedidos
	- hi harina
	- mi importes

panaderia(i, j) = 
	| 0                  si i = 0 o j = 0   // No tengo pedidos o harina
	| panaderia(i-1,j)   si i > 0 && hi > j // NO elijo el pedido
	| max(panaderia(i-1, j), mi + panaderia(i-1,j-hi) si i > 0 && j > hi > 0 

fun panaderia(harinas: array[1..n] of nat, importes: array[1..n] of nat, H: nat) ret res: nat
  // Creamos una tabla a[0..n, 0..H] donde:
  // a[i,j] representa la máxima ganancia usando los primeros i pedidos con j unidades de harina
  var a: array[0..n, 0..H] of nat

  // Caso base 1: con 0 pedidos, no importa cuánta harina tenga, la ganancia es 0
  for j := 0 to H do 
    a[0, j] := 0 
  od

  // Caso base 2: con 0 harina, no importa cuántos pedidos tenga, la ganancia también es 0
  for i := 0 to n do 
    a[i, 0] := 0 
  od

  // Recorremos cada pedido desde el 1 al n
  for i := 1 to n do
    // Recorremos cada cantidad de harina desde 1 hasta H
    for j := 1 to H do
      if harinas[i] > j then
        // Si el pedido i necesita más harina que la disponible (j), no lo podemos usar
        // Copiamos el mejor resultado que teníamos sin este pedido
        a[i, j] := a[i - 1, j]
      else
        // Si podemos usar el pedido i, tenemos dos opciones:
        // 1. No usarlo: ganancia = a[i - 1, j]
        // 2. Usarlo: ganancia = importe del pedido + ganancia con lo que queda de harina
        // Tomamos la mejor de las dos
        a[i, j] := max(a[i - 1, j], importes[i] + a[i - 1, j - harinas[i]])
      fi
    od
  od

  // El resultado óptimo está en la celda [n, H] de la tabla
  res := a[n, H]
end fun

```

### Problema del globo aerostatico

Usted se encuentra en un globo aerostático sobrevolando el océano cuando descubre que empieza a perder altura porque la lona está levemente dañada. Tiene consigo *n* objetos cuyos pesos *p1,...,pn* y valores *v1,...,vn* conoce. Si se desprende de al menos *P* kilogramos logrará recuperar altura y llegar a tierra firme, y afortunadamente la suma de los pesos de los objetos supera holgadamente *P*. Cuál es el menor valor total de los objetos que necesita arrojar para llegar sano y salvo a la costa?

```c
Datos: 
	- n objetos
	- p1,...,pn pesos
	- v1,...,vn valores
	- Debo desprenderme de P kilogramos

globo(i,j) = 
	| 0        si j <= 0
	| inf      si i = 0 & j > 0
	| globo(i-1,j) si i > 0 & pi > j
	| min(globo(i-1,j), vi + globo(i-1,j-pi)) si i > 0 && j >= pi
	

fun globo(pesos: array[1..n] of nat, valores: array[1..n] of nat, P: nat) ret res: nat
  var a: array[0..n, 0..P] of nat

  // Caso base: para cualquier peso j, con 0 objetos el valor total es infinito (no puedo alcanzar j)
  for j := 0 to P do a[0, j] := infinito od
  // Caso base: con 0 peso requerido (j = 0), siempre puedo "cumplir" sin tirar nada
  for i := 0 to n do a[i, 0] := 0 od
  // Llenamos la tabla a[i, j] = menor valor para alcanzar peso j usando los primeros i objetos
  for i := 1 to n do
    for j := 1 to P do
      if pesos[i] > j then
        // No puedo tirar este objeto (demasiado pesado), copio el valor anterior
        a[i, j] := a[i - 1, j]
      else
        // Elijo entre no usar el objeto o usarlo (y sumar su valor + lo que falta)
        a[i, j] := min(a[i - 1, j], valores[i] + a[i - 1, j - pesos[i]])
      fi
    od
  od
  res := a[n, P]
end fun
```

### Problema del teléfono setelital

Sus amigos quedaron encantados con el teléfono satelital, para las próximas vacaciones ofrecen pagarle un alquiler por él. Además del día de partida y de regreso (*pi* y *ri*) cada amigo ofrece un monto *mi* por día. Determinar el máximo valor alcanzable alquilando el teléfono.

```c
Datos: 
 - n amigos
 - p1,...,pn partida
 - r1,...,rn regreso
 - monto mi por dia

tel(i, d) =
  | 0                                       si i = 0
  | tel(i - 1, d)                           si ri > d  // No puedo usar al amigo i, se pasa del día d
  | max(tel(i - 1, d), mi * (ri - pi + 1) + tel(i - 1, pi - 1))  si ri ≤ d

La llamada recursiva sera tel(n,D)

fun tel(p: array[1..n], r: array[1..n], m: array[1..n], D: nat) ret res: nat
  var a: array[0..n, 0..D] of nat

  // Inicialización: con 0 amigos, la ganancia es 0 en todos los días
  for d := 0 to D do
    a[0, d] := 0
  od

  // Llenamos la tabla
  for i := 1 to n do
    for d := 0 to D do
      if r[i] > d then
        // No puedo alquilar al amigo i porque no cabe en los días disponibles
        a[i, d] := a[i - 1, d]
      else
        // Calculo la ganancia si uso al amigo i
        ganancia := m[i] * (r[i] - p[i] + 1)
        // Mejor caso entre no usarlo y usarlo
        a[i, d] := max(a[i - 1, d], ganancia + a[i - 1, p[i] - 1])
      fi
    od
  od

  res := a[n, D]
end fun
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

fun art(v: array[1..n] of nat, MA: array[1..n] of nat, MB: array[1..n] of nat, A: nat, B: nat) ret res: nat
  var a: array[0..n, 0..A, 0..B] of nat

  // Caso base: sin productos, el valor alcanzable es 0 para cualquier cantidad de materia prima
  for j := 0 to A do
    for k := 0 to B do
      a[0, j, k] := 0
    od
  od

  // Llenar tabla dinámica
  for i := 1 to n do
    for j := 0 to A do
      for k := 0 to B do
        if MA[i] > j || MB[i] > k then
          // No puedo usar el producto i porque no tengo suficiente materia prima
          a[i, j, k] := a[i - 1, j, k]
        else
          // Elijo entre usar o no usar el producto i
          a[i, j, k] := max(a[i - 1, j, k], v[i] + a[i - 1, j - MA[i], k - MB[i]])
        fi
      od
    od
  od

  res := a[n, A, B]
end fun
	
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

fun mochila(w: array[1..n] of nat, v: array[1..n] of nat, W1: nat, W2: nat) ret res: nat
  var a: array[0..n, 0..W1, 0..W2] of nat

  // Caso base: con 0 objetos, el valor es 0 sin importar la capacidad
  for j := 0 to W1 do
    for k := 0 to W2 do
      a[0, j, k] := 0
    od
  od

  // Llenar la tabla de abajo hacia arriba
  for i := 1 to n do
    for j := 0 to W1 do
      for k := 0 to W2 do
        if w[i] > j and w[i] > k then
          // No puedo poner el objeto i en ninguna mochila
          a[i, j, k] := a[i - 1, j, k]
        else
          // Opciones posibles:
          // 1. No usar el objeto i
          sin_usar := a[i - 1, j, k]
          // 2. Usarlo en la mochila 1 (si entra)
          usar_en_1 := -1
          if w[i] <= j then
            usar_en_1 := v[i] + a[i - 1, j - w[i], k]
          fi
          // 3. Usarlo en la mochila 2 (si entra)
          usar_en_2 := -1
          if w[i] <= k then
            usar_en_2 := v[i] + a[i - 1, j, k - w[i]]
          fi
          // Elegir la mejor opción
          a[i, j, k] := max(sin_usar, usar_en_1, usar_en_2)
        fi
      od
    od
  od

  res := a[n, W1, W2]
end fun

```
