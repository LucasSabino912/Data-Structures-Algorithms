// Algoritmos voraces
/* Es el siglo XX y no existe Netflix ni ningún servicio de TV por demanda. En esta época la gente contrata servicio de TV por cable 
donde te envían un librito con la programación de cada canal día por día.

Como el fin de semana estará lloviendo, planeás encerrarte a ver películas. Del librito de programación seleccionaste 
n películas que te interesan (que se transmiten en distintos canales) y para cada película i, con 1 <= i<n, tenés el 
horario de comienzo ca y de final fi. Por supuesto no podés ver dos películas a la vez. 

Debés encontrar cuáles de las n películas vas a ver, de manera que la cantidad sea máxima. */

type Pelicula = tuple
                  ca: int
                  fi: int
                end tuple

// La solucion sera una lista ordenada de peliculas
// Criterio de seleccion: selecciono las peliculas que terminen antes

fun peliculas(C: Set of Pelicula) ret l: List of Pelicula
    var C_aux: Set of Pelicula
    var hora: int
    var p: Pelicula

    hora := 0
    C_aux := copy_set(C)
    l := empty_list(l)

    while not is_empty_set(C_aux) do
        p := seleccionar_pelicula(C_aux)
        elim(C_aux, p)

        if p.ca >= hora then
            addl(l, p)
            hora := p.fi
            actualizar_peliculas(C_aux, hora)
        fi
    od

    destroy_set(C_aux)
end fun


fun seleccionar_pelicula(C: Set of Pelicula) ret p: Pelicula
    var C_aux: Set of Pelicula
    var p: Pelicula
    var min: int

    C_aux:= copy_set(C)
    min:= +inf

    while not is_empty_set(C_aux) do
        p:= get(C_aux)
        elim(C_aux, p)
        if p.fi < min then
            min:= p.fi
            pelicula:= p
        fi
    od

    destroy_set(C_aux)
end fun

proc actualizar_peliculas(in/out C: Set of Pelicula, in h: int)
    var C_aux: Set of Pelicula
    var p: Pelicula
    
    C_aux:= copy_set(C)

    while not is_empty_set(C_aux) do
        p:= get(C_aux)
        elim(C_aux, p)
        if p.fi < h then
            elim(C, p)
        fi
    od

    destroy_set(C_aux)
end proc






// Backtracking
/* En una localidad cordobesa, vive el José Agustín Goytisolo quien, apenado por los padecimientos de la mayoría de los vecinos, 
decide comprometerse en solucionarlos postulándose a la intendencia. Gracias a su entusiasmo y creatividad, en pocos minutos 
enumera una larga lista de N propuestas para realizar. Pronto descubre que a pesar de que cada una de ellas generaría 
una satisfacción popular P1, P2, ., PN también provocaría desagrado 91, 92, qN en el sector más acomodado de la sociedad local. 
En principio, el desagrado de cada propuesta es insignificante en número de votos ya que la alta sociedad no es muy numerosa. 
Pero a José le interesa cuidar 'su relación con este sector, ya que el mismo tiene suficientes recursos como para dificultar su 
triunfo en caso de proponérselo. 

Pronto descubre que las propuestas elaboradas son demasiadas para ser publicitadas: 
tantas propuestas (N) gener-arían confusión en el electorado. Esto lo lleva a convencerse de seleccionar solamente 
K de esas N propuestas (KN). Se dispone, entonces, a seleccionar K de esas N propuestas de forma tal que la suma de satisfacción */

prop(i, k) =
    | 0                                                     si k = 0
    | -inf                                                  si i = 0 and k > 0
    | max( prop(i-1, k), (P[i] - q[i]) + prop(i-1, k-1) )   si i > 0 and k > 0