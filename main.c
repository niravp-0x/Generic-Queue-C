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


/*        Boom* xxxx;
        xxxx->x = 2;
        xxxx->y = 5;
        xxxx->det = "Ello";

        enQ.Data = (void*)xxxx;
        enqueue(&testQ, enQ);
*/
        int i = 0;

        for (i = 0; i < 10; i++)
        {
            char* str = "String";

            enQ.index = i;
            enQ.Data = str;

            enqueue(&testQ, enQ);
        }

        printAll(&testQ);

        /* deq */

        printf("\n %s Emptying Q by Dequeue..  \n", SPACER );

        int siz = testQ.size;
        for(i = 0; i < siz; i++)
        {
            dequeue(&testQ, &deQ);
        }

        printAll(&testQ);


        printf("\n%s %*c End of the Program \n%s", SPACER, 20, ' ', SPACER);
    }

    return 0;
}
