

#include <stdlib.h>
#include <stdio.h>
#include "eke.h"


int main(int argc, char* argv[])
{

    if (argc != 2) { // argc is 2 if program name and one argument passed
        printf("Error: Expected one parameter.\n");
        return EXIT_FAILURE;
    }
    // argv can be altered. This is allowed by C standard but remember not to overrun it!

    int sort_result = eke_sort(argv[1]);
    
    if (sort_result != 0) {
        printf("Failed at %s", &argv[1][sort_result]);
        return EXIT_FAILURE;
    }

    // SUCCESS!
    printf("%s", argv[1]);
    return EXIT_SUCCESS;
}
