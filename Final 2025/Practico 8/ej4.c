/* Una panadería recibe n pedidos por importes m1,...,mn, pero sólo queda 
en depósito una cantidad H de harina en buen estado. Sabiendo que los pedidos 
requieren una cantidad h1,...,hn de harina, determinar el máximo importe 
que es posible obtener con la harina disponible */

/* 
Datos:
 - n pedidos
 - H harina
 - los pedidos requieren h1 ... hn harina
 - los pedidos tienen m1 ... mn importes
*/

// Tengo i cantidad total de pedidos
// Tengo j cantidad total de harina

panaderia(i,j) = 
    | 0                      si i = 0
    | panaderia(i-1,j)       si i > 0 && hi > j // No elijo el pedido
    | max(panaderia(i-1,j)), mi + panaderia(i-1,j-hi)