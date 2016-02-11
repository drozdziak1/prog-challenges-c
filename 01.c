/*
 * 01 - Higher/Lower, heads/tails
 *
 * Author: Stanisław Drozd <drozdziak1@gmail.com>
 */
#include <stdio.h>   // printf()
#include <stdlib.h>  // srand(), rand()
#include <time.h>    // time()
#include <ctype.h>   // isdigit()
#include <limits.h>  // INT_MAX, INT_MIN
#include <stdbool.h> // bool
#include <errno.h>   // errno
#include <string.h>  // strlen()

static char* bin_name;

void print_help(void);
void arg_validate(char* arg); // for easier reading
void die(const char* message);

int main(int argc, char* argv[])
{
    bin_name = argv[0]; // for print_help()
    srand(time(NULL));

    int min = 0, max = 1, count = 1;

    for (int i = 0; i < count; i++)
        // Spit out a number in the desired range
        printf("%d\n", rand() % (max - min + 1) + min);

    arg_validate("234");
    arg_validate("2432983409809803");

    /*print_help();*/

    return 0;
}

void print_help(void)
{
    puts("01 - Higher/Lower, heads/tails");
    puts("This thing is supposed to return [count] (1 by default)");
    puts("integers between [bottom] and [top], 0 and 1 by default.");
    printf("Usage: %s [count] [bottom top]", bin_name);
}

// TODO: Determine if the argument is okay to cram into an int reliably
void arg_validate(char arg[])
{
    for (int i = 0; i < strlen(arg); i++) { // Make sure we're dealing with a number

        if (!isdigit(arg[i])) {

            printf("%s:\n", arg);
            die("argument is not a number");
        }
    }

    if (atoi(arg) <= INT_MIN) {

        printf("%s:\n", arg);
        die("argument below range");
    }

    if (atoi(arg) >= INT_MAX) {

        printf("%s:\n", arg);
        die("argument above range");
    }
}

void die(const char* message)
{
    if (errno) {
        perror(message);
    }
    else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}
