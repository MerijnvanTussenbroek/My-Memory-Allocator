#include "main.h"

#include <stdio.h>

int main()
{
    int* test;

    test = (int *)myMalloc(sizeof(int));

    *test = 1;

    printf("location: %p\n", (void *)test);

    printf("number: %d\n", *test);

    *test = 1;

    printf("number: %d\n", *test);

    *test = 4;

    printf("number: %d\n", *test);

    *test = 256;

    printf("number: %d\n", *test);

    printf("Program ended without crashing\n");
    return 0;
}
