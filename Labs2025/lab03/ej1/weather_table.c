/*
  @file weather_table.c
  @brief Weather table implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather_table.h"

/**
 * @brief Write the content of the table 'a' into stdout.
 * @param[in] a table to dump in stdout
 */
void table_dump(WeatherTable a) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                // imprimir año, mes y día
                fprintf(stdout, "%u %u %u ", year + FST_YEAR, month + 1, day + 1);

                // imprimir datos para ese día
                weather_to_file(stdout, a[year][month][day]);

                // imprimir salto de línea
                fprintf(stdout, "\n");
            }
        }
    }
}

/**
 * @brief reads a table of weather information from file
 * @details
 *
 *  Each element is read from the file located at 'filepath'.
 *  The file must exist in disk and must have its contents in a sequence of
 *  lines, each with the following format:
 *
 *   <year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>
 *
 *   Those elements are copied into the multidimensional table 'a'.
 *
 * @param a table which will contain read file
 * @param filepath file with weather data
 */

// Input:
// 1980 1 1 211 290 130 10130 54 0
// año mes dia media maxima minima presion humedad precipitaciones 

void table_from_file(WeatherTable a, const char *filepath) {
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int k_year = 0u;
    unsigned int k_month = 0u;
    unsigned int k_day = 0u;
    while (!feof(file)) {
        int res = fscanf(file, " %u %u %u ", &k_year, &k_month, &k_day);
        if (res != 3) {
            fprintf(stderr, "Invalid table.\n");
            exit(EXIT_FAILURE);
        }

        Weather weather = weather_from_file(file);

        unsigned int year_index = k_year - FST_YEAR;
        unsigned int month_index = k_month - 1;
        unsigned int day_index = k_day - 1;

        a[year_index][month_index][day_index] = weather;
    }

    fclose(file);
}

