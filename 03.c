/*
 * 03 - Calculate age in seconds with leap years
 *
 * Author: Stanisław Drozd <drozdziak1@gmail.com>
 *
 */

#define _XOPEN_SOURCE // For strptime()

#include <stdio.h>   // printf()
#include <stdlib.h>  // exit() abs()
#include <time.h>    // struct tm, time(), strptime()
#include <math.h>    // abs(), labs()
#include <stdbool.h> // bool

#include "die.h" // die()

// NOTE: On DATE_FMT change, edit print_help() accordingly
#define DATE_FMT "%Y-%m-%d"
#define sectoy(x) ((x) / (365.25 * 24 * 60 * 60)) // Seconds to years

void print_help(const char* bin_name);

int main(int argc, char** argv)
{
    struct tm birthday = {
        // Guarantee output reliability
        .tm_sec = 0,
        .tm_min = 0,
        .tm_hour = 0,
    };

    time_t seconds;
    int years;
    bool secs_positive; // For human-readable output

    if (argc != 2) {

        print_help(argv[0]);
        exit(argc > 2 ? argv[1][1] != 'h' : 1);
    }

    if (strptime(argv[1], DATE_FMT, &birthday) == '\0') {

        print_help(argv[0]);
        putchar('\n');
        die("Your date is invalid!");
    }

    seconds = time(NULL) - mktime(&birthday);
    secs_positive = (seconds > 0);
    seconds = labs(seconds); // We don't want this signed in output

    years = abs((int)sectoy(seconds)); // Same here

    if (!seconds) {
        puts("You managed to be born this very second. Happy birthday!");
        exit(0);
    }

    printf("%s ca. %ld second%s, that is, %d year%s.\n",
        secs_positive ? "Your age is" : "You'll be born in", // Past vs. future birth date
        (long)seconds,
        (seconds - 1) ? "s" : "", // For plural seconds
        years,
        (years - 1) ? "s" : ""); // For plural years

    return 0;
}

void print_help(const char* bin_name)
{
    puts("Convert an Y-m-d formatted date of birth to seconds\n");

    printf("Usage: %s Y-m-d\n", bin_name);
    puts("  Y - year e.g. 1965\n"
         "  m - month e.g. 05 for May\n"
         "  d - day e.g. 14");
}
