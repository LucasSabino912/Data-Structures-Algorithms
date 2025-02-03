# Practico 2.1 - Tipos concretos

# Ejercicio 1

Escribir un algoritmo que dada una matriz a:**array** [*1..n,1..m*] **of int** calcule el elemento mínimo.

Escribir otro algoritmo que devuelva un arreglo **array**[*1..n*] con el mínimo de cada fila de la matriz a.

```c
fun minMatriz(a:arrray[1..n,1..m] of int) ret min: int
	var i,j: nat
	min:= a[1,1]
	for i:= 1 to n do
		for j:= 1 to m do
			if a[i,j] < min then
				min:= a[i,j]
			fi
		od
	of
end fun
```

```c
fun minFila(a:array[1..n,1..m]) ret f[1..n] of int
	var i,j,min: nat
	for i:= 1 to n do
		min:= a[i,1]
		f[1]:= min
		for j:= 2 to m do
			if a[i,j] < min then
				min:= a[i,j]
			fi
		od
		f[i]:= min
	od
end fun
```

# Ejercicio 2

Dados los tipos enumerados

```
type mes = enumerate
                enero
                febrero
                ...
                diciembre
           end enumerate
```

```
type clima = enumerate
                Temp
                TempMax
                TempMin
                Pres
                Hum
                Prec
             end enumerate
```

El arreglo med:**array**[1980..2016,enero..diciembre,1..28,Temp..Prec] **of nat** es un arreglo multidimensional que contiene todas las mediciones estadísticas del clima para la ciudad de Córdoba desde el 1/1/1980 hasta el 28/12/2016. Por ejemplo, med[2014,febrero,3,Pres] indica la presión atmosférica que se registró el día 3 de febrero de 2014. Todas las mediciones están expresadas con números enteros. Por simplicidad asumiremos que todos los meses tienen 28 días.

- a) Dar un algoritmo que obtenga la menor temperatura mínima (TempMin) histórica registrada en la ciudad de Córdoba según los datos del arreglo.
- b) Dar un algoritmo que devuelva un arreglo que registre para cada año entre 1980 y 2016 la mayor temperatura máxima (TempMax) registrada durante ese año.
- c) Dar un algoritmo que devuelva un arreglo que registre para cada año entre 1980 y 2016 el mes de ese año en que se registró la mayor cantidad mensual de precipitaciones (Prec).
- d) Dar un algoritmo que utilice el arreglo devuelto en el inciso anterior (además de med) para
obtener el año en que ese máximo mensual de precipitaciones fue mínimo (comparado con los de otros años).
- e) Dar un algoritmo que obtenga el mismo resultado sin utilizar el del inciso (c).

```c
fun TempMin(med:**array**[1980..2016,enero..diciembre,1..28,Temp..Prec])
ret min: int
	min:=[1980,enero,1,Temp]
	for año:= 1980 to 2016 do
		for mes:= enero to diciembre do
			for dia:= 1 to 28 do
				if med[i,j,k,Temp] < min then
					min:= med[i,j,k,Temp]
				fi
			od
		od
	od
end fun 
```

```c
fun TempMax(med:**array**[1980..2016,enero..diciembre,1..28,Temp..Prec])
ret temp_max_max:array[1..n] of int
var max: int
	for año:= 1980 to 2016 do
		temp_max:= med[año,1,1,Temp]
		for mes:= enero to diciembre do
			for dia:= 1 to 28 do
				if med[año,mes,dia,Temp] < max then 
					max:= med[año,mes,dia,Temp]
				fi
			od
		od
		max:= temp_max[año,mes,dia,Temp]
	od
end fun 
```

```c
fun mes_may_prec_año(a:array[1980..2016,enero..diciembre,1..28,Temp..Prec] of nat)
   ret res:array[1980..2016] of string
   var res_tmp, prec_mes: int
   for año:= 1980 to 2016 do
      res_tmp:= 0
      for mes:= enero to diciembre do
         {- reinicio el contador de precipitaciones para el nuevo mes -}
         prec_mes:= 0
         {- cuento las precipitaciones del mes -}
         for dia:= 1 to 28 do
            prec_mes:= prec_mes + a[año,mes,dia,Prec]
         od
         {- si el mes donde esuvimos iterando tieme mas precipitaciones,
         pasa a ser el resultado temporal (o permanente si no hay otro
         mes con mas precipitaciones) que guardamos en el arreglo y la
         cantidad de precipitaciones es el nuevo numero a comparar -}
         if(res_tmp < prec_mes) then
            res[año]:= mes
            res_tmp:= prec_mes
      od
   od
end proc
```

```c
fun min_prec_mes(a:array[1980..2016,enero..diciembre,1..28,Temp..Prec] of nat)
   ret res_año: int
   var meses: array[1980..2016] of string
   var prec_meses: array[1980..2016] of string
   meses:= mes_may_prec_año(a)
   for año:= 1980 to 2016 do
      {- calculo la cantidad de precipitaciones de cada mes -}
      for dia:= 1 to 28 do
         prec_mes:= prec_mes + a[año,meses[año],dia,Prec]
      od
      {- guardo en un arreglo los valores -}
      prec_meses[año]:= prec_mes
   od
   {- teniendo el arreglo de precipitaciones, calculo cual es el minimo -}
   var min_prec: int
   min_prec:= prec_meses[1980]
   res_año:= 1980
   {- si hay un mes con menor numero de precipitaciones que el anterior del arreglo:
      guardo el numero de precipitaciones en una variable temporal (para hacer las 
      proximas comparaciones). guardo el año en la variable a retornar -}
   for año:= 1981 to 2016 do
      if(prec_meses[año] < min_prec) then
         min_prec:= prec_meses[año]
         res_año:= año
      fi
   od
end fun
```

```c
fun min_prec_mes_2(a:array[1980..2016,enero..diciembre,1..28,Temp..Prec] of nat) 
   ret res:array[1980..2016] of int
   {- primer algoritmo, guardo en un arreglo los meses de cada año con
      mayor numero de precipitaciones-}
   var res_tmp, prec_mes: int
   for año:= 1980 to 2016 do
      res_tmp:= 0
      for mes:= enero to diciembre do
         prec_mes:= 0
         for dia:= 1 to 28 do
            prec_mes:= prec_mes + a[año,mes,dia,Prec]
         od
         if(res_tmp < prec_mes) then
            res_parte1[año]:= mes
            res_tmp:= prec_mes
      od
   od

   {- segundo algoritmo, calculo lo mismo que el inciso anterior -}
   var meses: array[1980..2016] of string
   var prec_meses: array[1980..2016] of string
   for año:= 1980 to 2016 do
      for dia:= 1 to 28 do
         prec_mes:= prec_mes + a[año,res_parte1[año],dia,Prec]
      od
      prec_meses[año]:= prec_mes
   od
   var min_prec: int
   min_prec:= prec_meses[1980]
   res_año:= 1980
   for año:= 1981 to 2016 do
      if(prec_meses[año] < min_prec) then
         min_prec:= prec_meses[año]
         res_año:= año
      fi
   od

end proc
```

# Ejercicio 3

Dado el tipo

```
type person = tuple
                name: string
                age: nat
                weight: nat
              end tuple
```

- a) Escribir un algoritmo que calcule la edad y peso promedio de un arreglo a:**array**[*1..n*] **of person**.
- b) Escribir un algoritmo que ordene alfabéticamente dicho arreglo.

```c
fun proms(a:array[1..n] of person) ret edad_prom, peso_prom: nat
	var i: nat
	edad_prom:= 0
	peso:prom:= 0
	for i:= 0 to n do
		edad_prom:= edad_prom + a[i].age
		peso_prom:= peso_prom + a[i].weight
	od
	edad_prom:= edad_prom / n
	peso_prom:= peso_prom / n
end fun
```

```c
proc ordenar_alfabeticamente(in/out a:array[1..n] of person, in i: nat)
	for i:= 2 to n do
		insert_person(a,i)
	od
end proc

proc insert_person(in/out a:array[1..n] of person, in i: nat)
	var j: nat
	j:= 1
	while (j > i) && es_menor(a[j].name ,a[j+1].name do
		swap(a,j-1,j)
		j:= j-1
	od
end proc

fun es_menor(s1:array[1..n] of char, s2:array[1..m] of char) ret res: bool
    if(s1[1] < s2[1]) then res:= true
    else if (s2[1] < s1[1]) then res:= false
    else
        for i:= 2 to n do
            if(s1[i] < s2[i]) then res:= true
            else if (s2[i] < s1[i]) then res:= false
        od
        if (n < m) then res:= true
end fun

proc swap(in/out a:array[1..n] of person, j, j-1: nat)
	var tmp: person
	tmp:= a[j]
	a[j]:= a[j-1]
	a[j-1]:= tmp
end proc
```

# Ejercicio 4

Dados dos punteros p,q: **pointer to int**

- a) Escribir un algoritmo que intercambie los valores referidos sin modificar los valores de p y q.
- b) Escribir otro algoritmo que intercambie los valores de los punteros.

```c
proc swap_val(in/out p,q: pointer to int)
	var tmp: int
	tmp:= p
	p:= q
	q:= tmp
end proc
```

```c
proc swap_val(in/out p,q: pointer to int)
	var tmp: int
	tmp:= *p
	*p:= *q
	*q:= tmp
end proc
```

# Ejercicio 5

Dados dos arreglos a,b: **array**[*1..n*] **of nat** se dice que a es “lexicográficamente menor” que b sii
existe k ∈ {1...n} tal que a[k] < b[k], y para todo i ∈ {1...k−1} se cumple a[i] = b[i]. En otras palabras, si en la primera posición en que a y b difieren, el valor de a es menor que el de b. También se dice que a
 es “lexicográficamente menor o igual” a b sii a es lexicográficamente 
menor que b o a es igual a b.

- a) Escribir un algoritmo lex_less que recibe ambos arreglos y determina si a es lexicográficamente menor que b.

```c
fun lex_less(a,b: array[1..n] of nat) ret res: bool
     var i: nat
     i:= 1
     while (a[i] = b[i] ^ i < n) do
          i:= i + 1
     od
     res:= a[i] < b[i]
end fun
```

- b) Escribir un algoritmo lex_less_or_equal que recibe ambos arreglos y determina si a es lexicográficamente menor o igual a b.

```c
fun lex_less_or_equal(a,b: array[1..n] of nat) ret res: bool
     var i: nat
     i:= 1
     while (a[i] = b[i] ^ i < n) do
          i:= i + 1
     od
     res:= a[i] ≤ b[i]
end fun
```

- c) Dado el tipo enumerado

```c
type ord = enumerate
                igual
                menor
                mayor
           end enumerate
```

Escribir un algoritmo lex_compare que recibe ambos arreglos y devuelve valores en el tipo ord.

```c
fun lex_compare(a,b: array[1..n] of nat) ret res: ord
     var i: nat
     i:= 1
     while (a[i] = b[i] ^ i < n) do
          i:= i + 1
     od
     if(a[i] < b[i]) then 
	     res:= menor
     else if (a[i] = b[i]) then 
	     res:= igual
     else 
	     res:= mayor
     fi
end fun
```

# Ejercicio 6

Escribir un algoritmo que dadas dos matrices a,b: **array**[*1..n,1..m*] **of nat** devuelva su suma.

Recordemos que la suma de dos matrices es la suma coordenada a coordenada:

```c
fun suma(a,b:array[1..n,1..m] of int) ret s:array[1..n,1..m]
	var i,j: nat
	for i:= 1 to n do 
		for j:= 1 to m do
			s[i,j]:= a[i,j] + b[i,j]
		od
	od
end fun
```

# Ejercicio 7

Escribir un algoritmo que dadas dos matrices a: **array**[*1..n,1..m*] **of nat** y b: **array**[*1..m,1..p*] **of nat** devuelva su producto.

```c
fun producto_matrices(a: array[1..n,1..m] of nat, b: array[1..m,1..p] of nat)
ret res: array[1..n,1..p] of nat
    for i:= 1 to n do           {- filas de a, filas de res -}
        for j:= 1 to p do       {- columnas de b, columnas de res -}
            res[i,j] := 0       {- reinicio el contador para una nueva posición -}
            for k:= 1 to m do   {- columnas de a, filas de b -}
                res[i,j]:= res[i,j] + (a[i,k] * b[k,j])
            od
        od
    od
end fun
```