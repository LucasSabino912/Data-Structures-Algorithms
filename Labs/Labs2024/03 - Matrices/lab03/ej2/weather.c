/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

Weather weather_from_file(FILE* file)
{
    Weather weather;
    int res = fscanf(file, "%d %d %d %u %u %u", &weather._average_temp,
                                                &weather._max_temp,
                                                &weather._min_temp,
                                                &weather._pressure,
                                                &weather._moisture,
                                                &weather._rainfall);
    if(res != AMOUNT_OF_WEATHER_VARS){
      fprintf(stderr, "amount o weather vars incorrect");
    }
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}

/*
typedef struct _weather
{
    int _average_temp;
    int _max_temp;
    int _min_temp;
    unsigned int _pressure;
    unsigned int _moisture;
    unsigned int _rainfall;
} Weather;
*/