#include <stdio.h>  // printf()
#include <stdlib.h> // exit();
#include <errno.h>  // errno

#include "die.h"

void die(const char* message)
{
    if (errno)
        perror(message);
    else {
        printf("ERROR: %s\n", message);
        exit(EXIT_FAILURE);
    }
}
