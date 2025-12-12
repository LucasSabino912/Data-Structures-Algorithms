/* Dados los tipos enumerados

type mes = enumerate
                enero
                febrero
                ...
                diciembre
           end enumerate

type clima = enumerate
                Temp
                TempMax
                TempMin
                Pres
                Hum
                Prec
             end enumerate

El arreglo med:array[1980..2016,enero..diciembre,1..28,Temp..Prec] of nat es un arreglo multidimensional 
que contiene todas las mediciones estadísticas del clima para la ciudad de Córdoba desde el 1/1/1980 hasta el 28/12/2016. 
Por ejemplo, med[2014,febrero,3,Pres] indica la presión atmosférica que se registró el día 3 de febrero de 2014. 
Todas las mediciones están expresadas con números enteros. Por simplicidad asumiremos que todos los meses tienen 28 días.

- a) Dar un algoritmo que obtenga la menor temperatura mínima (TempMin) histórica registrada en la ciudad de Córdoba según los datos del arreglo.
- b) Dar un algoritmo que devuelva un arreglo que registre para cada año entre 1980 y 2016 la mayor temperatura máxima (TempMax) registrada durante ese año.
- c) Dar un algoritmo que devuelva un arreglo que registre para cada año entre 1980 y 2016 el mes de ese año en que se registró la mayor cantidad mensual de precipitaciones (Prec).
- d) Dar un algoritmo que utilice el arreglo devuelto en el inciso anterior (además de med) para
obtener el año en que ese máximo mensual de precipitaciones fue mínimo (comparado con los de otros años).
- e) Dar un algoritmo que obtenga el mismo resultado sin utilizar el del inciso (c). */

// a
fun minTempCba (a:array[] of int) ret tempMin: int
   TempMin = +inf

   for año:= 1980 to 2016 do
      for mes:= enero to diciembre do
         for dia:= 1 to 28 do
            if a[año,mes,dia,TempMin] < min then
               min := a[año,mes,dia,TempMin]
            fi
         od
      od
   od
end fun

// b
fun maxTempToArray (a:array[] of int) ret maxs: array[1980..2016]
   for i:= 1980 to 2016 do
      maxs[año]:= a[año,1,1,Temp]
      for mes:= enero to diciembre do
         for dia:= 1 to 28
            if a[año,mes,dia,TempMax] > maxs[año] then
               maxs[año] = a[año,mes,dia,TempMax]
            fi
         od
      od
   od
end fun

// c
fun maxTempMonthToArray (a:array[] of int) ret maxs: array[1980..2016]
   for i:= 1980 to 2016 do
      mejor:= -inf
      for mes:= enero to diciembre do
         sumMes:= 0
         for dia:= 1 to 28 do
            sumaMes:= sumaMes + a[año,mes,dia,Prec]

            if sumaMes > mejor then
               mejor:=  sumaMes
               maxs[año]:= mes
            fi
         od
      od
   od
end fun

// d
fun añoMinMaxPrec (a:array[] of int, maxs:a[]) ret añoMin: int
   menor:= +inf

   for año:= 1980 to 2016 do
      suma:= 0

      for dia:= 1 to 28 do 
         suma:= suma + a[año, maxs[año], dia, Prec]

         if suma < menor then
            menor:= suma
            añoMin:= año
         fi

      od
   od
end fun