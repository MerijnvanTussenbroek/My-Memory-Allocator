#include "memoryAllocator.h"

#define NULL 0

int bufferSize = 4096;

char buffer[4096];

// we divide the buffer into chunks
// these chunks will be 4 bytes
// when we allocate memory, we will allocate x + 1 chunks, where the + 1 is used to track how many chunks are used
// so if we haven't allocated any memory, and someone asks for 4 chunks, we allocate 5 chunks, and the first one is used to store the number 4
// the pointer we return will point to the chunk after the first one, so when we free, we must go back 1 chunk to check how many we used
// that way, we can free up x + 1 chunks again.

void* myMalloc(int size)
{
    // we increase the size by 1 for the extra chunk
    size++;

    // we initialize the pointer to be the first chunk
    int pointer = 0;

    // we check if the input is valid
    if(size <= 0)
        return NULL;

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
                if(buffer[pointer + i] != 0)
                {
                    usable = 0;
                    break;
                }
            }

            // only if all the space is available can we use it
            if(usable == 1)
            {
                // we store how big the used space is
                buffer[pointer] = size - 1;
                // we return the pointer
                return (void *)pointer + 1;
            }
        }
        pointer++;
    }

    // if we have looped over the entire buffer, it means there is no more spacve available and we return null
    return NULL;
}

void myFree(void* p)
{
    // we first check if the pointer isn't null'
    if(p == NULL)
        return;

    // we convert the pointer to an integer
    int pointer = (int)p;

    // we retrieve the size we need to clean
    int size = (int)buffer[pointer-1];

    // we set this byte itself to 0
    buffer[pointer-1] = 0;

    // we loop over the byte and set it all to 0, freeing the memory
    for(int i = 0; i < size; i++)
    {
        buffer[pointer + i] = 0;
    }
}
