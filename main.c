#include "Gen_Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    BufferQueue testQ;      // Generic Queue with size Limit
    int bufferSizeLimit;    // size Limit - can be set manually or get from user.

    bufferSizeLimit = userSetBufferLimit();         // Asks user to set buffer size limit  - (Max number of elements Queue can hold)

    init_BufferQueue(&testQ, bufferSizeLimit);      // initialize bufferQueue

    if(testQ.initialized)
    {
        Element enQ, deQ;
        int i = 0;

        for (i = 0; i < 12; i++)
        {
            char* str = "String";

            enQ.index = i;
            enQ.Data = str;
            
            enqueue(&testQ, enQ);
        }

        printAll(&testQ);

        printf("END");
    }

    return 0;
}
