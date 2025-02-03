# Arboles binarios de busqueda

Un árbol binario es una estructura de datos que consiste en nodos que almacenan un elemento y dos subestructuras, que a la vez pueden ser otro nodo, o vacío

**Constructores**: 

- Árbol vacío
- Nodo consistente de un elemento de algún tipo T y dos arboles

**Botánica y genealogía**: en la foto podemos ver un nodo

- Un **nodo** es un árbol no vacío
- Tiene **raíz, subarbol izquierdo y subarbol derecho**
- A los subarboles se los llama **hijos** (izquierdo y derecho)
- Y al nodo se le dice **padre** de sus hijos
- Una hoja es un nodo con los dos hijos vacios
- Se define **camino, altura, profundidad y nivel**

**Niveles**: 

- En el nivel 1 hay a lo sumo 1 nodos
- En el nivel 2 hay a lo sumo 2 nodos
- En el nivel 3 hay a lo sumo 4 nodos
- En un árbol de altura n hay a lo sumo
    
    2ˆ0 + 2ˆ1 + … 2ˆ(n-1) = 2ˆn - 1 nodos
    

Podemos recorrer un árbol indicando el camino desde la raíz.

Un camino lo podemos representar como una secuencia donde cada elemento nos indica si debo bajar a la izquierda o a la derecha

# Especificación del TAD árbol binario

```c
type Direction = enumerate
											left
											right
								 end enumerate
								 
type Path =  List of Direction

spec Tree of T where 

constructors
	fun empty_tree() ret t: Tree of T
	{- crea un arbol vacio -}
	
	fun node(tl: Tree od T, e: T, tr: Tree of T)
																ret t: Tree of T
	{- crea un nodo con el elemento e y los subarboles tl y tr -}

operations
	fun is_empty_tree(t: Tree of T) ret b: bool
	{- devuelve true si el arbol es vacio -}
	
	fun root(t: Tree of T) ret e: T
	{- deuelve el elemento que se encuentra en 
		 la raiz de t -}
	{- PRE: not is_empty_tree(t) -}
	
	fun left(t: Tree of T) ret tl: Tree of T
	{- devuelve el subarbol izquierdo de t -}
	{- PRE: not is_empty_tree(t) -}

	fun right(t: Tree of T) ret tl: Tree of T
	{- devuelve el subarbol derecho de t -}
	{- PRE: not is_empty_tree(t) -}

	fun height(t: Tree of T) ret n: nat 	
	{- Devuelve la distancia que haye entre la raiz
		 de t y la hoja mas profunda -}
	
	fun is_path(t: Tree of T, p: Path) ret b: bool
	{- devuelve true si p es un camino valido de t -}
	
	fun subtree_at(t: Tree of T, p: Path) ret e: T
	{- devuelve el elemento que se encuentra al
		 recorrer el camino p en t -}
	{- PRE: is_path(t,p) -}	
	
implement Tree of T where

type Node of T = tuple
								left: pointer to (Node of T)
								value: T
								right: pointer to (Node of T)
								 end tuple

type Tree od T = pointer to (Node of T)

fun empty_tree() ret t: Tree of T
	t:= null
end fun					 

fun node(tl: Tree of T, e: T, tr: Tree of T)
															ret t: Tree of T
	alloc(t)
	t->value:= e
	t->left:= tl
	t->right:= tr
end fun
```

# Arboles binarios de búsqueda

- Son casos particulares de arboles binarios
- Son arboles binarios en donde la informacion esta organizada de forma tal que el siguiente algoritmo permite buscar de forma eficiente un elemento:
    - El elemento buscado se compara con la raíz de t
        - Si es el mismo, la búsqueda finaliza
        - Si es menor que la raíz, la búsqueda se restringe al subarbol izquierdo de t con el mismo algoritmo
        - Si es mayor que la raíz, la búsqueda se restringe al subarbol derecho t con el mismo algoritmo
- Si el árbol esta “balanceado”, es un algoritmo logaritmico

Para que este algoritmo funcione, t debe cumplir lo siguiente:

- Los valores alojados en el subarbol izquierdo de t deben ser menores que el alojado en la raíz de t
- Los valores alojados en el subarbol derecho de t deben ser mayores que el alojado en la raíz de t
- Estás dos condiciones deben darse para todos los subarboles de t

Si se cumplen estas condiciones, decimos que t es un árbol **binario de búsqueda,** o **ABB**

### Agregar un elemento en un ABB

Si quiero agrega un elemento e a un ABB t de manera de mantener la propiedad debo realizar el siguiente procedimiento recursivo:

- Si t es vacío, formo el nodo que consta del elemento e y los dos subarboles vacios
- En caso contrario, comparo el elemento e con la raíz del árbol t
- Si e es menor que la raíz, lo agrego al subarbol izquierdo
- Si e es mayor o igual que la raíz, lo agrego al subarbol derecho