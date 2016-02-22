/*
 * 03 - Calculate age in seconds with leap years
 *
 * Author: Stanisław Drozd <drozdziak1@gmail.com>
 *
 */

#define _XOPEN_SOURCE // for strptime()

#include <stdio.h>   // printf()
#include <stdlib.h>  // exit() abs()
#include <time.h>    // struct tm, time(), strptime()
#include <math.h>    // abs(), labs()
#include <stdbool.h> // bool

#include "die.h" // die()

#define DATE_FMT "%Y-%m-%d"
#define sectoy(x) ((x) / (365.25 * 24 * 60 * 60)) // seconds to years

void print_help(char* bin_name);

int main(int argc, char** argv)
{
    struct tm birthday = {
        .tm_sec = 0,
        .tm_min = 0,
        .tm_hour = 0,
    };

    time_t seconds;
    int years;
    bool secs_positive; // for formatting the output human-readably;

    if (argc != 2 || argv[1][1] == 'h') {

        print_help(argv[0]);
        exit(1);
    }

    if (strptime(argv[1], DATE_FMT, &birthday) == '\0') {

        print_help(argv[0]);
        die("Your date is invalid");
    }

    seconds = time(NULL) - mktime(&birthday);
    secs_positive = (seconds > 0);
    seconds = labs(seconds);

    years = abs((int)sectoy(seconds));

    if (!seconds) {
        puts("You managed to be born this very second. Happy birthday!");
        exit(0);
    }

    printf("%s %ld second%s, that is, %d year%s.\n",
        secs_positive ? "Your age is" : "You'll be born in", // future vs. past birth date
        (long)seconds,
        (seconds - 1) ? "s" : "", // for plural seconds
        years,
        (years - 1) ? "s" : ""); // for plural years

    return 0;
}

void print_help(char* bin_name)
{
    puts("Convert an Y-m-d formatted date of birth to seconds\n");

    printf("Usage: %s Y-m-d\n", bin_name);
    puts("  Y - year e.g. 1965\n"
         "  m - month e.g. 05 for May\n"
         "  d - day e.g. 14");
}
