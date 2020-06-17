/*
 * Project : Generic Queue
 * FILE : Gen_Queue.c
 *
 * Author : Nirav PANCHAL
 * Contact : nirav.xv@gmail.com
 *
 * Source.c file for the generic queue.
 * Queue structure and methods implementations.
 *
 */

#include "Gen_Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int userSetBufferLimit()
{
    bool valid = false;
    int userInput = 0;

    printf("%s Please enter the size limit for queue :", SPACER);
    scanf("%d", &userInput);

    if (userInput == 0)
    {
        printf("%s [Error]   Invalid input for :     Queue[ size_limit ] \n "
               "\n  -> input should be a number > 0. (greater than zero)"
               "\n  -> Size limit is maximum number of elements queue can hold.\n", SPACER);
        fflush(stdin);

        userSetBufferLimit();
    }
    else
    {
        return userInput;
    }

}

void init_BufferQueue(BufferQueue* inQ, int bufferSize)
{
    if(bufferSize > 0)
    {
        inQ->size = 0;
        inQ->sizeLimit = bufferSize;
        inQ->rearIdx = -9;
        inQ->Elements = (Element *) malloc(( bufferSize * sizeof(Element) ));
        inQ->initialized = true;
    }
    else
    {
        printf("[Warning] Set limit is 0! Queue is not initialized. \n");
        inQ->initialized = false;
    }

}

void freeMe(BufferQueue* inQ)
{
    int i;
    int sizeLim = inQ->size;
    printf("Before Free : %d \n", inQ->Elements->Data);
    printf("Before Free : %d \n", ((inQ->Elements)+1)->Data);
 //   free(inQ->Elements);
//    for(i=0; i<sizeLim; i++)
//    {
        free(((inQ->Elements)+1));
 //   }

    printf("Before Free : %d \n", ((inQ->Elements)+1)->Data);
}

bool isEmpty(BufferQueue* inQ)
{
    if(inQ->size == 0)  // If the size of Queue is 0,
    {
        return true;    // then Queue is empty. Return true (1).
    }
    else
    {
        return false;   // Queue is not empty. Return false (0).
    }
}

bool isFull(BufferQueue* inQ)
{
    if(inQ->size == (inQ->sizeLimit))   // If the size of Queue reaches to the size limit.
    {
        return true;    // Queue is Full. Return true (1).
    }
    else
    {
        return false;   // Queue is not full. Return false (0).
    }
}

bool enqueue(BufferQueue* inQ, Element inElement)
{
    /*
     * IF (Q is full)
     *      THEN    Show No Success!
     * ELSE IF (Q is Empty)
     *      THEN    Store. Show success.
     * Else
     *      Then    Update index, Store. Show success.
     */
    if(isFull(inQ))
    {
        printf("\n%s [Overflow] Queue is Full!%*cQueue: [ %d / %d ]\n", SPACER, 20, ' ', inQ->size,inQ->sizeLimit);
        printf("%*cElement not added to Queue.\n", 12,' ');
        printf(SPACER);


        return false;   //  Enqueue : Not success.
    }
    else if (isEmpty(inQ))
    {
        inQ->rearIdx = 0;           // Front = Rear = 0 (index = 0)
        *(inQ->Elements + inQ->rearIdx) = inElement; // Dereference Rear THEN Store Element.
        inQ->size++;                                // Queue size increment by 1

        //printLoadSuccess(inQ, inElement);           // Prints success message.
       // printMessage("Enqueue Success", &inElement);
       /*
        int xx = (int) (((Boom*)inElement.Data)->x);
        int yy = (int) (((Boom*)inElement.Data)->y);

       printf("\n Your variable --> [x,y]    ---- (String) \n"
                      "                  [ %d , %d ] ----  %s \n", xx, yy, (char*)((Boom*)inElement.Data)->det);

       */
        return true;    // Enqueue : Success.
    }
    else
    {

        inQ->rearIdx++;                                 // Rear increment by 1
        *(inQ->Elements + inQ->rearIdx) = inElement;     // Dereference Rear THEN Store Request.
        inQ->size++;                                    // Queue size increment by 1

        //printLoadSuccess(inQ, inElement);               // Prints success message.
        printMessage("Enqueue Success", &inElement);
        return true;    // Enqueue : Success.
    }
}

bool dequeue(BufferQueue* inQ, Element* deqElement)
{
    if(isEmpty(inQ))
    {
        printf("\n %s", SPACER);
        printf("[Underflow] Queue is Empty!          Queue: [ %d / %d ]"
               "\n            Nothing in Queue to remove.\n",inQ->size,inQ->sizeLimit);
        printf(SPACER);

        return false;
    }
    else
    {
        *deqElement = *(inQ->Elements);        // Taking Request from first index (FRONT)

        // If there is only one element in Queue.
        // Then it needs to be reset after taking that remaining one element out.
        if(inQ->size == 1)
        {
            inQ->rearIdx = -9;  // No element should exist in Queue. So resetting index.
        }
        else
        {
            int i;
            for(i=0; i < (inQ->size-1); i++)
            {
                // Shift all elements to the left.
                *(inQ->Elements + i) = *(inQ->Elements + i + 1);
            }

            inQ->rearIdx--;     // Rear end is decreased by 1
        }

        inQ->size--;        // size of Queue is decreased by 1

        // printAll(inQ);
        return true;
    }
}

void printMessage(char* operation, Element* inElement)
{
    printf("\n%s[%s]\n %*c Element - %s     Index : %d", SPACER, operation, 10, ' ', inElement->Data, inElement->index);
}

void printAll(BufferQueue* inQ)
{
    int i;

    if(inQ->size != 0)
    {
        printf("\n%s Displaying current Queue : \n\n",SPACER);
        for (i = 0; i < (inQ->size); i++)
        {
            char* str = ((inQ->Elements + i)->Data);
            int ix = ((inQ->Elements + i)->index);

            printf("     #(%d) Element : \" %s \"      at index : %d    \n", i, str, ix);

            /*
            If need to display output vertically aligned.

            if(i > 9 && i < 100)
            {
                printf("    #(%d) Element : \" %s \"      at index : %d \n", i, str, ix);
            }
            else if (i > 99)
            {
                printf("   #(%d) Element : \" %s \"      at index : %d \n", i, str, ix);
            }
            else
            {
                printf("     #(%d) Element : \" %s \"      at index : %d \n", i, str, ix);
            }

            */
        }
    }
    else
    {
        printf("\n%s Q is empty!  Nothing to show.\n",SPACER);
    }

}