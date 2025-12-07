/* Ordena los arreglos del ejercicio 4 utilizando el algoritmo de ordenacion por insercion. Mostra en
cada paso de iteracion las comparaciones e intercambios realizados hasta ubicar el elemento en su
posicion. */

Para cada i = 2..n: key := a[i]; j := i-1; mientras j >= 1 y a[j] > key hacer a[j+1] := a[j]; j := j-1; luego a[j+1] := key.

Indico cada comparación a[j] > key? (y si da true hago el shift) y muestro el arreglo tras los shifts y después de insertar la clave.


(a) [7, 1, 10, 3, 4, 9, 5]  (n = 7)

Array inicial: [7, 1, 10, 3, 4, 9, 5]

i = 2, key = 1, j = 1

Comparación: a[1]=7 > 1? → sí → shift a[2] := a[1]. Arreglo tras shift: [7,7,10,3,4,9,5].

j pasa a 0 → fin del while. Insertar key en a[1] := 1.
Resultado iteración: [1,7,10,3,4,9,5].


i = 3, key = 10, j = 2

Comparación: a[2]=7 > 10? → no → no shifts. Insertar key en a[3] (sin cambio).
Resultado: [1,7,10,3,4,9,5].


i = 4, key = 3, j = 3

a[3]=10 > 3? → sí → shift a[4]:=10 → [1,7,10,10,4,9,5]. j=2.

a[2]=7 > 3? → sí → shift a[3]:=7 → [1,7,7,10,4,9,5]. j=1.

a[1]=1 > 3? → no → fin. Insertar key en a[2]:=3.
Resultado: [1,3,7,10,4,9,5].


i = 5, key = 4, j = 4

a[4]=10 > 4? → sí → shift a[5]:=10 → [1,3,7,10,10,9,5]. j=3.

a[3]=7 > 4? → sí → shift a[4]:=7 → [1,3,7,7,10,9,5]. j=2.

a[2]=3 > 4? → no → fin. Insertar key en a[3]:=4.
Resultado: [1,3,4,7,10,9,5].


i = 6, key = 9, j = 5

a[5]=10 > 9? → sí → shift a[6]:=10 → [1,3,4,7,10,10,5]. j=4.

a[4]=7 > 9? → no → fin. Insertar key en a[5]:=9.
Resultado: [1,3,4,7,9,10,5].


i = 7, key = 5, j = 6

a[6]=10 > 5? → sí → shift a[7]:=10 → [1,3,4,7,9,10,10]. j=5.

a[5]=9 > 5? → sí → shift a[6]:=9 → [1,3,4,7,9,9,10]. j=4.

a[4]=7 > 5? → sí → shift a[5]:=7 → [1,3,4,7,7,9,10]. j=3.

a[3]=4 > 5? → no → fin. Insertar key en a[4]:=5.
Resultado final: [1,3,4,5,7,9,10].





(b) [5, 4, 3, 2, 1]  (n = 5)

Array inicial: [5,4,3,2,1]

i = 2, key = 4, j = 1

a[1]=5 > 4? → sí → shift a[2]:=5 → [5,5,3,2,1]. j=0. Insertar a[1]:=4.
Resultado: [4,5,3,2,1].


i = 3, key = 3, j = 2

a[2]=5 > 3? → sí → shift a[3]:=5 → [4,5,5,2,1]. j=1.

a[1]=4 > 3? → sí → shift a[2]:=4 → [4,4,5,2,1]. j=0. Insertar a[1]:=3.
Resultado: [3,4,5,2,1].


i = 4, key = 2, j = 3

a[3]=5 > 2? → sí → shift a[4]:=5 → [3,4,5,5,1]. j=2.

a[2]=4 > 2? → sí → shift a[3]:=4 → [3,4,4,5,1]. j=1.

a[1]=3 > 2? → sí → shift a[2]:=3 → [3,3,4,5,1]. j=0. Insertar a[1]:=2.
Resultado: [2,3,4,5,1].


i = 5, key = 1, j = 4

a[4]=5 > 1? → sí → shift a[5]:=5 → [2,3,4,5,5]. j=3.

a[3]=4 > 1? → sí → shift a[4]:=4 → [2,3,4,4,5]. j=2.

a[2]=3 > 1? → sí → shift a[3]:=3 → [2,3,3,4,5]. j=1.

a[1]=2 > 1? → sí → shift a[2]:=2 → [2,2,3,4,5]. j=0. Insertar a[1]:=1.
Resultado final: [1,2,3,4,5].



---

(c) [1, 2, 3, 4, 5]  (ya ordenado)

Array inicial: [1,2,3,4,5]

i = 2, key = 2, j = 1

a[1]=1 > 2? → no → sin shifts. Resultado: [1,2,3,4,5].


i = 3, key = 3, j = 2

a[2]=2 > 3? → no → sin shifts. Resultado: [1,2,3,4,5].


i = 4, key = 4, j = 3

a[3]=3 > 4? → no → sin shifts. Resultado: [1,2,3,4,5].


i = 5, key = 5, j = 4

a[4]=4 > 5? → no → sin shifts. Resultado final: [1,2,3,4,5].
