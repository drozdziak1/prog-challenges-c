/*
 * 01 - Higher/Lower, heads/tails
 *
 * Author: Stanisław Drozd <drozdziak1@gmail.com>
 */
#define _DEFAULT_SOURCE // for bsd/stdlib.h

#include <stdio.h>      // printf()
#include <stdlib.h>     // srand(), rand()
#include <time.h>       // time()
#include <string.h>     // strlen()
#include <limits.h>     // for bsd/stdlib.h
#include <bsd/stdlib.h> // strtonum()
#include <errno.h>      // errno
#include <string.h>     // strcmp()

static const char* bin_name;

void print_help(void);

int main(int argc, char* argv[])
{
    bin_name = argv[0]; // for print_help()
    srand(time(NULL));

    // For displaying all errors at once
    const char *count_err, *min_err, *max_err;

    int min, max, count;

    switch (argc) { // parse args based on their quantity

    case 4:
        count = (int)strtonum(argv[3], INT_MIN, INT_MAX, &count_err);

        if (count_err)
            printf("Count is %s\n", count_err);

    case 3:
        min = (int)strtonum(argv[1], INT_MIN, INT_MAX, &min_err);

        if (min_err)
            printf("Min is %s\n", min_err);

        max = (int)strtonum(argv[2], INT_MIN, INT_MAX, &max_err);

        if (max_err)
            printf("Max is %s\n", max_err);

        if (errno)
            exit(1);

        break;

    case 1: // "default" behavior
        min = 0;
        max = 1;
        count = 1;
        break;

    default:
        print_help();
        exit(1);
    }

    // Provide correct spelling depending on count
    printf("Your random number%s:\n", (count > 1) ? "s" : "");

    // Spit number(s) out in the desired range
    for (int i = 0; i < count; i++)
        printf("%d ", rand() % (max - min + 1) + min);

    return 0;
}

void print_help(void)
{
    puts("01 - Higher/Lower, heads/tails\n"
         "This thing is supposed to return [count] (1 by default)\n"
         "integers between [bottom] and [top], 0 and 1 by default.\n");

    printf("Usage: %s [bottom top] [count]", bin_name);
}
