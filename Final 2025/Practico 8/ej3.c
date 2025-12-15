/*Sus amigos quedaron encantados con el teléfono satelital, para las 
próximas vacaciones ofrecen pagarle un alquiler por él. Además del día de partida
 y de regreso (*pi* y *ri*) cada amigo ofrece un monto *mi* por día. 
 Determinar el máximo valor alcanzable alquilando el teléfono. */

/*
Datos: 
 - n amigos
 - p1,...,pn partida
 - r1,...,rn regreso
 - mi monto por dia
*/

// i amigos
// d dia actual


tel(i,d) = 
    | 0              si i = 0
    | tel(i-1,d)     si i > 0 & pi > d 
    | max(tel(i-1,d), mi * (ri-pi+1) + tel(i-1, pi + d))
 