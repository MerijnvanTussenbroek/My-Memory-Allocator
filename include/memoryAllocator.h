#define NULL 0

#include <stdio.h>

void* myMalloc(int size);

void myFree(void* p);

void* myMallocWithChunk(int size);

void myFreeWithChunk(void* p);

void printBuffer();
