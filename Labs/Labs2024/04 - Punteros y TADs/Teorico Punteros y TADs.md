# Lab 4: Punteros y TADs

Un puntero es un tipo de variable especial que guarda una direccion de memoria. En C, se denotan los punteros usando el símbolo. Es decir, que una variable p declarada como int ***p,** es del tipo puntero a int.

# Operación de referenciacion (&)

Este operador obtiene la dirección de memoria de una variable. También se lo conoce como operador de dirección. Si se tiene una variable entera x declarada como int x = 3; entonces la expresión &x retornara la dirección de memoria donde esta alojado el contenido de la variable x.

Particularmente la expresión &x en este caso es del tipo int*, es decir del tipo puntero a int. Por lo tanto, se puede hacer lo siguiente:

```c
int x = 3;
int *p;

p = &x;
```

En este ejemplo entonces el puntero p guarda la dirección de memoria x y decimos que p apunta a x.

# Operación de desreferenciación (*)

Obtiene el valor de lo apuntado por el puntero. También se lo conoce como el operador de la indireccion (indirection operador). Se lo puede pensar como una operación de inspección ya que accede al valor alojado en una direccion de memoria. Si se tiene una variable de tipo **int*** llamada p, entonces la expresión *p retornara el valor entero que se aloja en la dirección de memoria que contiene p. En el ejemplo de arriba *p devuelve 3

Además si se utiliza *p del lado izquierdo de una asignación:

```c
*p = <expresion>;
```

La asignación escribirá el resultado de la expresión en la dirección de memoria apuntada por p, por lo que se cambia el valor contenido en esa dirección de memoria (sin modificar a p, que sigue apuntando el mismo lugar). Por ejemplo, si se hace la asignación

```c
int x = 3;
int *p;

p = &x;
*p = 10;
```

Sucede que p sigue apuntando al mismo lugar, pero al lugar en el que apunta p cambia de 3 a 10

Cabe aclarar que cuando se declara la variable de tipo puntero **int *p;** el símbolo ***** no actúa como operador sino que simplemente indica que la variable **p** se declara como puntero.

```c
int x = 3;
int y = 10;
y = *(&x);
```

Aquí está lo que sucede paso a paso:

1. `int x = 3;` declara una variable `x` y le asigna el valor 3.
2. `int y = 10;` declara una variable `y` y le asigna el valor 10.
3. `y = *(&x);` toma la dirección de `x` usando `&x`, luego desreferencia esa dirección usando ``, obteniendo así el valor almacenado en `x` (que es 3), y lo asigna a `y`.

Por lo tanto, después de ejecutar este código, el valor de `y` será 3.

# Constante nula de punteros(NULL)

Siempre es buena idea dar un valor inicial a las variables apenas se escriben. Para punteros existe la constante NULL, que representa una direccion de memoria nula, en la cual no se puede ni leer, ni escribir. Por ejemplo en el siguiente programa:

```c
int *p;
*p = 3;
```

es fácil imaginar que esto podría generar que el programa termine con un error (violación de segmento - *segmentation fault*) pero podría ser peor. Puede suceder que por azar en **p** se encuentre la dirección de memoria de otra variable del programa y la modifiquemos, generando un **BUG** muy difícil de rastrear.

En esta otra versión:

```c
int *p = NULL;
*p = 3;
```

el programa siempre va a fallar, y eso es bueno.

# Punteros ++

Se vio que un puntero es un tipo de variable especial que guarda una direccion de memoria. La memoria se puede pensar como un arreglo, y en ese sentido una direccion de memoria es un indice. A estos índices los escribiremos en base hexadecimal (0,  1, 2, …, 9, A, B, C, …. F) que es la base utilizada para referirse a las direcciones de memoria

Si tengo este codigo

```c
int x= 3;
int *p = NULL;
```


P apunta a NULL y el lugar de memoria vale 0x00, y p es guardado en la memoria tambien. Ahora si yo cambio el codigo y defino a p como: 

```c
p = &x
```


la expresión &x hace referencia a la dirección de memoria 0x05, entonces luego de la asignación, el puntero p apunta a la dirección de memoria 0x05, es decir, p simplemente tiene ese valor asignado. Notar que p, al ser una variable, su valor tambien esta en algún lugar de la memoria (en la dirección 0x09)

# Operadores de indexación y flecha

- Indexación (p[n]): Permite obtener el valor que hay en la memoria moviéndose n lugares hacia adelante desde la dirección de memoria guardada en p, Por ej, p[0] es quivalente a *p
- Acceso indirecto (→): Si p es un puntero a una estructura p→member es un atajo a (*p).member (asumiendo que la estructura tiene un campo llamado member)

# Arreglos y punteros

Cuando se declara una variable de tipo arreglo inr arr[4], hay dos formas de obtener la dirección de memoria del primer elemento:

- Usando el operador de referenciacion: &arr[0]
- Usando el nombre del arreglo: arr

```c
int arr[4] = {1,9,8,6};
int *p = NULL;
p = &arr[0]; // usando operador &
p = arr; // Usando directamente le nombre de la variable
```

¿Qué diferencia hay entre **p** y **arr**?

Circunstancialmente se puede usar a **p** para acceder a los elementos del arreglo **arr** ya que **p[i]** y **arr[i]** van a devolver exactamente el mismo valor. Sin embargo, más adelante en el código se puede reutilizar a **p** para que apunte a otra variable, por ejemplo haciendo **p = &x;** (suponiendo que tenemos declarada a **int x;**). Por otro lado, aunque con la expresión **arr** obtenemos la dirección de memoria del primer elemento del arreglo, **arr** no es un puntero ya que no es posible hacer

# TADS

### Encapsulamiento

Cuando definimos un TAD es deseable garantizar **encapsulamiento**, es decir, que solamente se pueda acceder y/o modificar su estado a través de las operaciones provistas. Esto no siempre es trivial ya que los tipos abstractos estan implementados en base a los tipos concretos del lenguaje. Entonces es importante que además de separar la especificación e implementacion se garantice que quien utilice el TAD no pueda acceder ala representación interna y operar con los tipos de manera descontrolada. Si el encapsulamiento se logra sera posible cambiar la implementacion del TAD sin tener que modificar ningún otro modulo que lo utilice.

No todos los lenguajes brindan las mismas herramientas para lograr una implementacion opaca y se debe usa el mecanismo apropiado según sea el caso.

### Métodos de TADs

En el diseño de los tipos abstractos de datos, aparecen los **constructores**, **operaciones** y **destructores**, que se declaran como funciones o procedimientos. Los procedimientos en C no existen como tales, por lo que se usan las funciones sin retorno, de tipo *void*, es decir, funciones que no devuelven ningún valor al llamarlas. A veces se buscara evitar procedimientos con una variable de salida usando directamente una función para simplificar y evitar asi usar punteros extras

# Tipos de TADs

### TAD par

### TAD contador

### TAD lista