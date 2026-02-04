#include "main.h"

#include <stdio.h>

int main()
{


    int *test1, *test2, *test3, *test4, *test5;

    test1 = (int *)myMalloc(sizeof(int));

    test2 = (int *)myMalloc(sizeof(int) * 2);

    test3 = (int *)myMalloc(sizeof(int));

    test4 = (int *)myMalloc(sizeof(int) * 3);

    *test1 = 2147483640;

    test2[0] = 2147483640;
    test2[1] = 2147483640;

    *test3 = 2147483640;

    test4[0] = 2147483640;
    test4[1] = 2147483640;
    test4[2] = 2147483640;

    myFree(test2);

    test2 = (int *)myMalloc(sizeof(int));

    printBuffer();

    test5 = (int *)myMalloc(sizeof(int));

    printBuffer();

    myFree(test3);

    test3 = (int *)myMalloc(sizeof(int) * 2);

    myFree(test1);
    myFree(test2);
    myFree(test3);
    myFree(test4);
    myFree(test5);

    printBuffer();

    printf("Program ended without crashing\n");
    return 0;
}
