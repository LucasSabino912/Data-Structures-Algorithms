#ifndef _AUX_FUNC_H
#define _AUX_FUNC_H

#include <stdlib.h>
#include "weather.h"

// la mayor temperatura minima historica
int max_min_temp(WeatherTable w);

// la mayor temperatura maxima historica
int max_max_temp(WeatherTable w);

// la mayor cantidad de precipitaciones por mes
unsigned int max_rainfall(WeatherTable w);



#endif