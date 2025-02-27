# Divide y venceras

Las recurrencias surgen al analizar algoritmos recursivos, como el merge sort. Elconteo de operaciones copia la recursion del algoritmoy se vuelve recursivo tambien, por ej; maximo de comparaciones del merge sort, es un ejemplo de algoritmo divide y venceras

Y este un ejemplo de recurrencia divide y venceras

t(n) = | 0                                    si n e {0,1} 

     | t(n/2) + t(n/2) + n-1     si n >1

# Divide y venceras

en los algoritmos divide y venceras hay una solucion para los casos sencillos, para los complejos, se divide o descompone el problema en subproblemas:

- Cada subproblema es de igual naturaleza que el original
- El tamaño del subproblema es una fraccion del original
- Se resuelven los subproblemas apelando al mismo algoritmo

Todas esas soluciones se combinan para obtener una solucion del original

## Forma general del algoritmo

```c
fun DyV ret y
	if x suficientemente pequeño o simple then y:= ad_oc(x)
	else descomponer x en X1, X2,..., Xa
		for:= 1 to a do yi:= DyV(Xi) od
		combinar Y1,Y2,...,Ya para pobtener la solucion y de x
	fi
end fun
```

Normalmente los Xi son fraxxiones de x:

|Xi| = |Xi| / b, para algun b fijo mayor que 1

### Ejemplos de algoritmos divide y venceras

Merge sort:

- “x simple” = fragmento de arreglo de longitud 0 o 1
- “descomponer” = partir al medio (b = 2)
- a = 2
- “combinar” = intercalar

Quick sort:

- “x simple” = fragmento de arreglo de longiutd 0 o 1
- “descomponer” = separar los menores de los mayores (b = 2)
- a = 2
- “combinar” = yuxtaponer

## Binary search

```c
{Pre: 1 <= lft <= n+1 && 0 <= rgt <= n && a ordenado}
fun binary_search_rec (a:array[1..n] of T, x:T, lft, rgt: nat) ret i:nat
		var mid: nat
		if lft > rgt then
				i:= 0
		else if lft <= rgt then
				mid:= (lft+rgt)/2
				if x < a[mid] then
						i:= binary_search_rec(a, x, lft, mid-1)
				else if x = a[mid] then
						i:= mid
				else if x > a[mid] then
						i:= binary_search_rec(a, x, mid+1, rgt)
				fi
		fi
end fun
{Post: (i = 0 => x no esta en a[lft, rgt]) && (i != 0 => x = a[i]}

{Pre: n >= 0}
fun binary_search (a:array[1..n] of T, x:T) ret i:nat
		i:= binary_search_rec(a, x, 1, n)
end fun
{Post: (i = 0 => x no esta en a) && (i != 0 => x = a[i]}
```
