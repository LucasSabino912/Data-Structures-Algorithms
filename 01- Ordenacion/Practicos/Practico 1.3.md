## Ejercicio 1
Calcular el orden de complejidad de los siguientes algoritmos:

```bash
a)
proc f1 (in n: nat)
    if n ≤ 1 then skip
    else
        for i:= 1 to 8 do f1(n div 2) od
        for i:= 1 to n³ do t:= 1 od
```

Recordemos:
- a: número de llamadas recursivas
- b: relación del tamaño entre x e xi
- k: el órden de descomponer y combinar es n^k

<br>

Verifico si es divide y vencerás: 
- hay caso base (n ≤ 1) y hace algo constante (skip)
- en el caso complejo, se llama recursivamente **8 veces** con un tamaño de *n div 2*
- además de llamar recursivamente al algoritmo, hace algo constante (**n³** veces)

```bash
t(n) = cantidad de operaciones que realiza el algoritmo f1(n)
t(n) = | 0                    si n ≤ 1
       | 8 * t(n div 2) + n³  si n > 1
```

Analizo la complejidad:
- a = 8
- b = 2
- k = 3


Luego, a = b^k, pues 8 = 2³
```
Por lo tanto, el algorítmo es de órden: 
    n³log n
```
<br><br><br>



```bash
b)
proc f2 (in n: nat)
    for i:= 1 to n do
        for j:= 1 to i do t:= 1 od
    od
    if n > 0 then
        for i:= 1 to 4 do f2(n div 2) od
```

Divido el problema, analizo el primer ciclo **for**:
```bash
    for i:= 1 to n do
        for j:= 1 to i do t:= 1 od
    od
```
**No** es divide y vencerás, calculo el numero de operaciones de la forma tradicional:
```
ops(for i:= 1 to n do (for j:= 1 to i do (t:= 1) od) od)
ops(for i:= 1 to n do (for j:= 1 to i do (1) od) od)
ops(for i:= 1 to n do (Σ(j=1 to i) (1)) od)
ops((Σ(i=1 to n) (Σ(j=1 to i) (1))))
ops((Σ(i=1 to n) i))
(n*(n+1)) / 2
(n²/2) + (n/2) ≈ n²
```

Ahora me concentro en el segundo ciclo for:
```bash
    if n > 0 then
        for i:= 1 to 4 do f2(n div 2) od
```
En éste caso:
- hay un caso base (n ≤ 0) y hace algo constante (skip)
- se llama recursivamente a la funcion **4** veces con un tamaño de *n div 2*
- además de llamar recursivamente al algoritmo, hace algo constante **n²** veces (en el ciclo for anterior)

```bash
t(n) = cantidad de operaciones que realiza el algoritmo f2(n)
t(n) = | 0                        si n ≤ 0
       | 4 * f2(n div 2) + g(n)   si n > 0
```

Analizo la complejidad:
- a = 4
- b = 2
- k = 2

Luego, a = b^k, pues 4 = 2²
```
Por lo tanto, el algorítmo es de órden: 
    n²log n
```
