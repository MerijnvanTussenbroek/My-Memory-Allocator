#include "main.h"

#include <stdio.h>

int main()
{

    int *test1, *test2;

    test1 = (int *)myMalloc(sizeof(int));

    printBuffer();

    test2 = (int *)myMalloc(sizeof(int) * 2);

    printBuffer();

    if(test1 == NULL)
        return 1;

    if(test2 == NULL)
        return 1;

    *test1 = 16;

    //printBuffer();

    *test2 = 256;

    //printf("%d\n", *test1);

    //printf("%d\n", *test2);

    //printBuffer();


    printf("Program ended without crashing\n");
    return 0;
}
