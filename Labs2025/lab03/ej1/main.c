/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 */
char *parse_filepath(int argc, char *argv[]) {
    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    return argv[1];
}

/**
 * @brief Main program function
 */
int main(int argc, char *argv[]) {
    char *filepath = parse_filepath(argc, argv);

    WeatherTable table;
    table_from_file(table, filepath);

    // Mostrar la tabla completa
    table_dump(table);

    // Máxima temperatura mínima histórica
    int maxMinTemp = max_min_temp(table);
    printf("\nMáxima temperatura mínima histórica: %d\n", maxMinTemp);

    // Máxima temperatura máxima histórica
    int maxMaxTemp = max_max_temp(table);
    printf("Máxima temperatura máxima histórica: %d\n", maxMaxTemp);

    // Mes de mayor precipitación por año
    month_t max_rainfall_months[YEARS];
    max_rainfall_per_year(table, max_rainfall_months);

    printf("Mes con más precipitaciones por año:\n");
    for (unsigned int i = 0; i < YEARS; ++i) {
        printf("Año %u: mes %u\n", FST_YEAR + i, max_rainfall_months[i] + 1); // +1 para mostrar meses desde 1 a 12
    }

    return EXIT_SUCCESS;
}
