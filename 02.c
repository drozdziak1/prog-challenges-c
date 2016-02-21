/*
 * 02 - Temperature converter
 *
 * Author: Stanisław Drozd <drozdziak1@gmail.com>
 */
#include <stdio.h>  // printf()
#include <stdlib.h> // strtod()
#include <errno.h>  // errno

#include "die.h" // die()

#define ctof(x) (x) * 1.8 + 32 // Celsius to Fahrenheit
#define ctok(x) (x) + 273      // Celsius to Kelvin

#define ftoc(x) ((x)-32) / 1.8 // Fahrenheit to Celsius
#define ftok(x) ctok(ftoc(x))  // Fahrenheit to Kelvin

#define ktoc(x) (x) - 273     // Kelvin to Celsius
#define ktof(x) ctof(ktoc(x)) // Kelvin to Fahrenheit

static void print_help(const char* bin_name);

int main(int argc, char* argv[])
{
    if (argc != 3) {

        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    char* endptr = NULL;

    errno = 0;
    float temp = strtof(argv[2], &endptr);

    if (errno || *endptr)
        die("Your temperature is not a valid number.");

    puts("Your argument converts to:");
    switch (argv[1][1]) {

    case 'c':
        printf("%.2fF\n", ctof(temp));
        printf("%.2fK\n", ctok(temp));

        break;

    case 'f':
        printf("%.2fC\n", ftoc(temp));
        printf("%.2fK\n", ftok(temp));

        break;

    case 'k':
        printf("%.2fC\n", ktoc(temp));
        printf("%.2fF\n", ktof(temp));

        break;

    default:
        die("Unknown temperature type");
    }

    return EXIT_SUCCESS;
}

static void print_help(const char* bin_name)
{
    printf("Usage: %s -c|-f|-k <temperature>\n\n", bin_name);

    puts("  -c\tconvert <temperature> from Celsius\n"
         "  -f\tconvert <temperature> from Fahrenheit\n"
         "  -h\tshow this help\n"
         "  -k\tconvert <temperature> from Kelvins\n");
}
