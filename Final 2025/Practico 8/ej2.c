/* Usted se encuentra en un globo aerostático sobrevolando el océano cuando descubre que 
empieza a perder altura porque la lona está levemente dañada. Tiene consigo *n* objetos cuyos pesos 
*p1,...,pn* y valores *v1,...,vn* conoce. Si se desprende de al menos *P* kilogramos 
logrará recuperar altura y llegar a tierra firme, y afortunadamente la suma de los pesos de 
los objetos supera holgadamente *P*. 

Cuál es el menor valor total de los objetos que necesita arrojar para llegar sano y salvo a la costa? */

/*
Datos: 
 - n objetos
 - p1,...,pn pesos
 - v1,...,vn valores
 - Debo desprenderme de P kilogramos  */

// i objetos
// j peso

globo(i,j) = 
    | 0            si j <= 0
    | inf          si i = 0 & j > 0 
    | globo(i-1,j) si i > 0 & pi > j
    | min(globo(i-1,j), vi + globo(i-1,j-pi)) si i > 0 && j >= pi