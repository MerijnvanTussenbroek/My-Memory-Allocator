#include "memoryAllocator.h"

int bufferSize = 128;

unsigned char buffer[128];

// we divide the buffer into chunks
// these chunks will be 4 bytes
// when we allocate memory, we will allocate x + 1 chunks, where the + 1 is used to track how many chunks are used
// so if we haven't allocated any memory, and someone asks for 4 chunks, we allocate 5 chunks, and the first one is used to store the number 4
// the pointer we return will point to the chunk after the first one, so when we free, we must go back 1 chunk to check how many we used
// that way, we can free up x + 1 chunks again.

// this malloc has a limit of 254 bytes

void* myMalloc(int size)
{
    // we check if the input is valid
    if(size <= 0)
        return NULL;

    // we increase the size by 1 for the extra chunk
    size++;

    // we initialize the pointer to be the first chunk
    int pointer = 0;

    // we loop over our buffer
    while(pointer < bufferSize)
    {
        // if the spot in the buffer is empty, we check if we can use it
        if(buffer[pointer] == 0)
        {
            // we initialize a boolean to track it
            int usable = 1;

            // we loop for as long as the size requires
            for(int i = 0; i < size; i++)
            {
                // if a spot isn't empty, it means something else is using it, meaning we cannot use it

                if(pointer + i >= bufferSize)
                {
                    return NULL;
                }


                // if a spot isn't empty, it means something else is using it, meaning we cannot use it
                // but we can still gain information from it.
                // we know that the first spot taken in allocated memory stores how big the allocated memory is
                // therefore we can do the following

                if(buffer[pointer + i] != 0)
                {
                    unsigned char takenSize = buffer[pointer + i];

                    pointer += takenSize-2;

                    printf("test %d\n", (int)takenSize);

                    usable = 0;
                    break;
                }

            }

            // only if all the space is available can we use it
            if(usable == 1)
            {
                // we store how big the used space is
                buffer[pointer] = size;
                // we return the pointer
                return (void *) (&buffer[0]) + pointer + 1;
            }
        }
        else
        {
            unsigned char takenSize = buffer[pointer];

            printf("test2 %d\n", (unsigned int)takenSize);

            pointer += takenSize-1;
        }

        pointer++;
    }

    printf("You went over the buffer\n");

    // if we have looped over the entire buffer, it means there is no more spacve available and we return null
    return NULL;
}

void myFree(void* p)
{
    // we first check if the pointer isn't null'
    if(p == NULL)
        return;

    // we convert the pointer to an integer
    int pointer = ((int)p - (int)(&buffer[0]));

    // we retrieve the size we need to clean
    unsigned char size = buffer[pointer-1];

    // we set this byte itself to 0
    buffer[pointer-1] = 0;

    // we loop over the byte and set it all to 0, freeing the memory
    for(int i = 0; i < size-1; i++)
    {
        buffer[pointer + i] = 0;
    }
}

void printBuffer()
{
    printf("Printing the buffer\n");

    for(int i = 0; i < 35; i++)
    {
            printf("%u\n", buffer[i]);
    }

    printf("Done printing the buffer\n");
}
