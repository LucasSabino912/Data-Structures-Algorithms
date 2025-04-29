#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "weather.h"
#include "weather_table.h"

// la mayor temperatura minima historica
int max_min_temp(WeatherTable w){   
    int max = INT_MIN;

    for(int year = 1980, year < YEARS; year++){
        for (int month = 1; month < MONTHS; month++){
            for (int day = 1; day < DAYS; day++){
                if (w[year][month][day]._min_temp > max){
                    max = w[year][month][day]._min_temp;
                }
            }
        }
    }

    return max;
}

// la mayor temperatura maxima historica
int max_max_temp(WeatherTable w){
    int max = INT_MIN;

    for (int year = 1980; year < YEARS; year++){
        for(int month = 1; month < MONTHS; month++){
            for(int day = 1; day < DAYS; day++){
                if(w[year][month][day]._max_temp > max){
                    max = w[year][month][day]._max_temp;
                }
            }
        }
    }

    return max;
}

// la mayor cantidad de precipitaciones por mes
#include <stdbool.h>
#include <limits.h>  // Para INT_MIN
#include "weather.h"
#include "weather_table.h"

// la mayor temperatura minima historica
int max_min_temp(WeatherTable w) {
    int max = INT_MIN;

    for (unsigned int year = 0; year < YEARS; ++year) {
        for (unsigned int month = 0; month < MONTHS; ++month) {
            for (unsigned int day = 0; day < DAYS; ++day) {
                if (w[year][month][day]._min_temp > max) {
                    max = w[year][month][day]._min_temp;
                }
            }
        }
    }

    return max;
}

// la mayor temperatura maxima historica
int max_max_temp(WeatherTable w) {
    int max = INT_MIN;

    for (unsigned int year = 0; year < YEARS; ++year) {
        for (unsigned int month = 0; month < MONTHS; ++month) {
            for (unsigned int day = 0; day < DAYS; ++day) {
                if (w[year][month][day]._max_temp > max) {
                    max = w[year][month][day]._max_temp;
                }
            }
        }
    }

    return max;
}

// la mayor cantidad de precipitaciones por mes
void max_rainfall_per_year(WeatherTable w) {
    month_t result[YEARS]
    for (unsigned int year = 0; year < YEARS; ++year) {
        unsigned int max_rain = 0;
        month_t max_month = january;

        for (unsigned int month = 0; month < MONTHS; ++month) {
            unsigned int monthly_rain = 0;

            for (unsigned int day = 0; day < DAYS; ++day) {
                monthly_rain += w[year][month][day]._rainfall;
            }

            if (monthly_rain > max_rain || month == january) {
                max_rain = monthly_rain;
                max_month = (month_t)month;
            }
        }

        result[year] = max_month;
    }
}

