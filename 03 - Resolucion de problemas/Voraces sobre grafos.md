# Algoritmos voraces sobre grafos

## Árbol generador de costo mínimo

Sea G = (V, A) un grafo conexo no dirigido con un costo no negativo asociado a cada arista. Se dice que T subcjto de A es un árbol generado (intuitivamente un tendido) si el grafo (V, T) es conexo y no contiene ciclos. 

Su costo es la suma de los costos de sus aristas y buscamos un T que su costo sea minimo

Ejemplo

![1000001379.png](Tecnicas%20de%20programacion%201fa0420d28ff8039aa58cbced6d753b0/1000001379.png)

![1000001380.png](Tecnicas%20de%20programacion%201fa0420d28ff8039aa58cbced6d753b0/1000001380.png)

## Algoritmo de Prim

Se parte desde un vértice origen y se va extendiendo el tendido a partir de ahí.

En cada paso se una el tendido ya existente con alguno de los vértices no alcanzados, seleccionando la arista de menor costo capaz de incorporar un nuevo vertice

### Implementacion del algoritmo de Prim

```c
type Vertex = Nat

type Edge = tuple
							v1: Vertex
							v2: Vertex
							cost: nat
						end tuple

type Graph = tuple 
							vertices: Set of Vertex
							edges: Set of Edge
						 end tuple

fun prim(G: Graph, k: Vertex) ret T: Set of Edge	var C
	var c: Edge
	var C: Set of Edge 
	C:= copy_set(G.vertices)
	elim(C,k)
	T:= empty_set()
	
	while not is_empty_set(C) do
		c:= "selecciono arista de costo minimo tal que
				c.v1 b C y c.b2 notb C, ó c.v2 b C y c.v1 notb C"
		if member(c.c1,C) then
			elim(C,c.v1)
		else 
			elim(C,c.v2) 
			add(C,c.v2)
		fi
	od
end fun
```

## Camino de costo mínimo

Sea G = (V, A) un grafo dirigido con costos no negativos y v uno de sus vértices, se busca obtener los caminos de menor costo desde v hacia cada uno de los demás vertices

## Algoritmo de Dijkstra

El algoritmo de Dijkstra realiza una secuencia de n pasos donde n es el numero de vértices. En cada paso aprende el camino de menor costo desde v a un nuevo vertice, tras esos n pasos, conoce los costos de los caminos de menor costo a cada uno de los vertices

Asumiremos que el grafo viene dado por un cjto de vertices V= {1, 2, …, n} y los costos por una matriz L: array[1..n,1..n] of nat, que en L[i,j] mantiene el costo de la arista que va de i a j

```c
fun Dijkstra(L:array[1..n,1..n] of nat, v: nat) ret D:array[1..n] of nat
	var c: Nat
	var C: Set of Nat
	
	for i:= 1 to n do
		add(C,i)
	od
	elim(C,v)
	for j:= 1 to n do
		D[j]:= L[v,j]
	od
	while not is_empty_set(C) do
		c:= "elijo elemento c de C t1 D[c] sea minimo"
		elim(C,c)
		for j in C do
			D[j]:= min(D[j],D[c]+L[c,j]) 
		od
	od
end fun
```

Usted quiere irse de vacaciones y debe elegir una ciudad entre K posibles que le interesan. Como no dispone de mucho dinero, desea que el viaje de ida hacia la ciudad pueda realizarse con a lo sumo L litros de nafta.

Dar un algoritmo que, dado un grafo representado por una matriz E: array[1..n,1..n] of Nat, donde el elemento E[i,j] indica el costo en litros de nafta necesario para ir desde la ciudad i hasta la ciudad j; un conjunto C de vértices entre 1 y n, representando las ciudades que quieren visitarse; un vértice v, representando la ciudad de origen del viaje; y un natural L, indicando la cantidad de litros de nafta total que puede gastar; devuelva un conjunto D de aquellos vértices de C que puede visitar con los L litros.

```c
fun puedo_visitar(E: array[1..n,1..n] of nat, C: set of nat, L: nat) ret D: set of nat
    var costos: array[1..n] of nat
    var C_copy: set of nat
    var ciudad: nat

    costos:= Dijkstra(E, v)
    C_copy:= copy_set(C)
    D:= emptyset()

    while (not is_empty_set(C_copy)) do
        ciudad:= get(C_copy)
        elim(C_copy, ciudad)
        {- si puedo llegar con L litros, lo agrego a la solución -}
        if (costos[ciudad] <= L) then add(D, ciudad) fi
    od
    destroy_set(C_copy)
end fun
```

