#include "Gen_Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    // Generic Queue with size Limit
    BufferQueue intQueue;       // Integer Queue
    BufferQueue structQueue;    // Structure Queue
    BufferQueue stringQueue;    // String Queue

    int bufferSizeLimit;    // size Limit - can be set manually or get from user.

    bufferSizeLimit = userSetBufferLimit();         // Asks user to set buffer size limit  - (Max number of elements Queue can hold)

    init_BufferQueue(&intQueue, bufferSizeLimit);         // initialize bufferQueue
    init_BufferQueue(&structQueue, bufferSizeLimit);      // initialize bufferQueue
    init_BufferQueue(&stringQueue, bufferSizeLimit);      // initialize bufferQueue

    if(intQueue.initialized)
    {
        int i;

        // TestStruct variable as Element - testing
        Element enqTest, deqTest;
        TestStruct* testVariable;

            testVariable->xPos = 5;
            testVariable->yPos = 5;
            testVariable->detail = "This is test Variable data.";

            enqTest.Data = (void*) testVariable;
            enqueue(&structQueue, enqTest);
            dequeue(&structQueue, &deqTest);
        printMessage(&deqTest);


        // String as Element - testing
        Element enqStr, deqStr;
            for (i = 0; i < 10; i++)
            {
                char* str = "String";
                enqStr.index = i;
                enqStr.Data = str;
                enqueue(&stringQueue, enqStr);
            }
        printAll(&stringQueue);


        // Int as Element - testing
        Element enqInt, deqInt;
            for (i = 0; i < 10; i++)
            {
                enqInt.index = i;
                enqInt.Data = (int)i+1;
                enqueue(&intQueue, enqInt);
            }
        printInts(&intQueue);


        /**********************************************************************************
         *                                  deq                                           *
         **********************************************************************************/

       printf("\n %s Emptying Q by Dequeue...  \n", SPACER );

        int siz = intQueue.size;

        for(i = 0; i < siz; i++)
        {
            dequeue(&intQueue, &deqInt);
        }
        printAll(&intQueue);
        printf("\n%s %*c End of the Program \n%s", SPACER, 20, ' ', SPACER);
    }

    return 0;
}
