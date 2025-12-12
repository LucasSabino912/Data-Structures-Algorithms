/* Ejercicio 3

Dado el tipo

type person = tuple
                name: string
                age: nat
                weight: nat
              end tuple

Escribir un algoritmo que calcule la edad y peso promedio de un arreglo a:array[1..n] of person.

Escribir un algoritmo que ordene alfabéticamente dicho arreglo. */

// a
fun edadPesoProm (a:array[1..n] of person)
    var sumaEdad, promEdad: int
    var sumaPeso, promPeso: int

    sumaEdad:= 0
    sumaPeso:= 0

    for p:= 1 to n do
        sumaEdad:= sumaEdad + a[p].age
        sumaPeso:= sumaPeso + a[p].weight
    od

    promEdad:= sumaEdad / n;
    promPeso:= sumaPeso / n;
end fun

// b
fun ordenarArreglo (a:array[1..n] of person)
    var ordenado: bool
    ordenado:= false
    while ordenado = false do
        ordenado = true
        for p:= 1 to n do
            if a[p].name > a[p+1].name then
                swap(a, p, p+1)
                ordenado:= false
            fi
        od
    od
end fun

