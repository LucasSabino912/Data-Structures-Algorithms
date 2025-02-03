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

## Voraces Sobre Grafos

### Arbol Generador de Costo Minimo

Sea G = (V, A) un grafo conexo no dirigido con un
costo no negativo asociado a cada arista.

Se dice que T ⊆ A es un árbol generador
si el grafo (V, T) es conexo y no contiene ciclos

Su costo es la suma de los costos de sus aristas.

Se busca T tal que su costo sea mínimo.

Hay 2 grandes ideas para encontrar el árbol generador de costo minimo:

- **Prim**: se parte desde un vértice origen y se va extendiendo a partir de ahí
  - en cada paso se une el tendido ya existente con alguno de los vértices aún no alcanzados, seleccionando la arista de menor costo capaz de incorporar un nuevo vértice

- **Kruskal**

#### Prim: Implementación

Podemos representar los grafos como una tupla con dos conjuntos:
uno para los vértices y otro para las aristas

```cs
type Vertex = Nat;

type Edge = tuple
              v1: Vertex
              v2: Vertex
              cost: Nat
            end tuple;

type Graph = tuple
              vertices: Set of Vertex
              edges: Set of Edge
            end tuple;  

fun Prim(G: Graph, i: Vertex) ret T: Set of Edge
  //  las aristas de G son los candidatos

  //  c: Candidate
  var e: Edge
  var V: Set of Vertex
  
  //  se crea una copia del set para administrar vértices no visitados
  V := copy_set(G.vertices)

  //  se elimina el vértice inicial, ya fué visitado
  elim(V, i)

  //  se inicializa la solución
  T := empty_set()
  
  //  se añade el vértice inicial a la solución
  add(T, i)

  //  hasta que todos los vértices hayan sido visitados
  do (not is_empty_set(V)) ->
    
    /**  
     * selecciono una arista tal que uno solo de sus extremos esté en el set
     * un vértice es visitado y el otro no
     * 
     * quedando este conjunto como posibles candidatos
     * {(e.v1 ∈ V ∧ e.v2 ∉ V) ∨ (e.v1 ∉ V ∧ e.v2 ∈ V)}
     *  
     * elijo de ese conjunto la arista con menor costo
     */
    e := "selecciono arista de costo minimo tal que (e.v1 ∈ V ∧ e.v2 ∉ V) ∨ (e.v1 ∉ V ∧ e.v2 ∈ V)"
    
    //  elimino el vértice visitado por e
    if member(e.v1, V) ->
      elim(V, e.v1)
    else
      elim(V, e.v2)
    fi

    //  agrego e a la respuesta
    add(T, e)
  od
end fun
```

### Camino de Costo Minimo

Sea G = (V, A) un grafo dirigido con costos no negativos
en sus aristas, y sea v ∈ V uno de sus vértices.

Se busca obtener los caminos de menor costo desde v
hacia cada uno de los demás vértices.

#### Dijkstra

El algoritmo de Dijkstra realiza una secuencia de n pasos,
donde n es el número de vértices

En cada paso, “aprende” el camino de menor costo desde
v a un nuevo vértice.

Marca a ese nuevo vértice

Tras esos n pasos, conoce los costos de los caminos de
menor costo a cada uno de los vértices del grafo.

##### El Algoritmo

- Asumiremos que el grafo viene dado por un conjunto de vértices
  - `V = {1, ..., n}`

- y los costos por una matriz
  - `L: array[1..n, 1..n] of Nat`
  - `L[i, j]` mantiene el costo de la arista que va de `i` a `j`
  - En caso de no haber ninguna arista de `i` a `j`, `L[i, j] = ∞`.
  - `L[i, i] = 0`

- Esta versión del algoritmo , halla sólo el **costo** del camino, en vez de hallar el camino de costo mínimo  
  - Hallará el **costo del camino de costo mínimo** desde un vértice `v`

- El resultado estará dado por un arreglo
  - `D: array[1..n] of Nat` (se asume costo natural)
  - en `D[j]` se guarda el costo de `v` a `j`

```cs
fun Dijkstra(L: array[1..n, 1..n] of Vertex, v: Vertex) ret D: array[1..n] of Nat
  
  //  C es el conjunto de los vértices que todavía desconocemos cuál es el camino de menor costo
  var C: Set of Vertex
  var c: Vertex
  
  //  Se inicializa el set C con todos los vértices
  for i := 1 to n do add(C, i) od

  //  Se elimina el vértice inicial de C
  elim(C, v)

  //  Se inicializa la solución con los valores iniciales de los costos desde v
  for j := 1 to n do D[j] := L[v, j] od

  //  hasta que todos los vértices hayan sido visitados
  do (not is_empty_set(C))→
    
    //  visito el vértice de menor costo que todavía no haya sido visitado
    c := “elijo elemento c de C tal que D[c] sea mínimo”

    //  elimino el vértice visitado por c
    elim(C, c)

    //  actualizo los costos teniendo en cuenta el nuevo vértice visitado
    for j in C do 
      /**  
       * me quedo con el mínimo entre el costo actual, o 
       * la suma entre el costo al nuevo vértice y el costo del nuevo vértice a los otros
       */
      D[j] := min(D[j], D[c] + L[c, j]) 
    od
  od
end fun
```

