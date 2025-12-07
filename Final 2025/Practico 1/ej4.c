/* Ordena los siguientes arreglos, utilizando el algoritmo de ordenacion por seleccion visto en clase.
Mostra en cada paso de iteracion cual es el elemento seleccionado y como queda el arreglo despues de cada intercambio. */
(a) [7, 1, 10, 3, 4, 9, 5]  (n = 7)

Array inicial: [7, 1, 10, 3, 4, 9, 5]

1. i = 1 (buscar mínimo en posiciones 1..7): mínimo = 1 (posición 2).
Intercambio pos1 ↔ pos2.
Resultado: [1, 7, 10, 3, 4, 9, 5]


2. i = 2 (buscar mínimo en 2..7): mínimo = 3 (posición 4).
Intercambio pos2 ↔ pos4.
Resultado: [1, 3, 10, 7, 4, 9, 5]


3. i = 3 (buscar mínimo en 3..7): mínimo = 4 (posición 5).
Intercambio pos3 ↔ pos5.
Resultado: [1, 3, 4, 7, 10, 9, 5]


4. i = 4 (buscar mínimo en 4..7): mínimo = 5 (posición 7).
Intercambio pos4 ↔ pos7.
Resultado: [1, 3, 4, 5, 10, 9, 7]


5. i = 5 (buscar mínimo en 5..7): mínimo = 7 (posición 7).
Intercambio pos5 ↔ pos7.
Resultado: [1, 3, 4, 5, 7, 9, 10]


6. i = 6 (buscar mínimo en 6..7): mínimo = 9 (posición 6).
Intercambio pos6 ↔ pos6 (sin cambio).
Resultado: [1, 3, 4, 5, 7, 9, 10]



Arreglo final ordenado: [1, 3, 4, 5, 7, 9, 10]


---

(b) [5, 4, 3, 2, 1]  (n = 5)

Array inicial: [5, 4, 3, 2, 1]

1. i = 1 (1..5): mínimo = 1 (posición 5).
Intercambio pos1 ↔ pos5.
Resultado: [1, 4, 3, 2, 5]


2. i = 2 (2..5): mínimo = 2 (posición 4).
Intercambio pos2 ↔ pos4.
Resultado: [1, 2, 3, 4, 5]


3. i = 3 (3..5): mínimo = 3 (posición 3).
Intercambio pos3 ↔ pos3 (sin cambio).
Resultado: [1, 2, 3, 4, 5]


4. i = 4 (4..5): mínimo = 4 (posición 4).
Intercambio pos4 ↔ pos4 (sin cambio).
Resultado: [1, 2, 3, 4, 5]



Arreglo final ordenado: [1, 2, 3, 4, 5]


(c) [1, 2, 3, 4, 5]  (n = 5, ya ordenado)

Array inicial: [1, 2, 3, 4, 5]

1. i = 1 (1..5): mínimo = 1 (pos 1). Intercambio pos1↔pos1 → [1, 2, 3, 4, 5]


2. i = 2 (2..5): mínimo = 2 (pos 2). Intercambio pos2↔pos2 → [1, 2, 3, 4, 5]


3. i = 3 (3..5): mínimo = 3 (pos 3). Intercambio pos3↔pos3 → [1, 2, 3, 4, 5]


4. i = 4 (4..5): mínimo = 4 (pos 4). Intercambio pos4↔pos4 → [1, 2, 3, 4, 5]



Arreglo final: [1, 2, 3, 4, 5] (sin cambios porque ya estaba ordenado)
