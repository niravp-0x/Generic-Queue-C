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
#include <stdbool.h>

void init_BufferQueue(BufferQueue* inQ, int bufferSize)
{
    inQ->size = 0;
    inQ->sizeLimit = bufferSize;
    inQ->frontIdx = inQ->rearIdx = -9;
    inQ->Queue = (Element*) malloc((bufferSize * sizeof(Element*)))
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
        printf("[Overflow] Queue is Full!%*cQueue: [ %d / %d ]\n", 10, ' ', inQ->size,inQ->sizeLimit);
        printf("%*cRequest not added to Queue.\n", 11,' ');
        printf(SPACER);

        return false;   //  Enqueue : Not success.
    }
    else if (isEmpty(inQ))
    {
        inQ->frontIdx = inQ->rearIdx = 0;           // Front = Rear = 0 (index = 0)
        *(inQ->Elements + inQ->rearIdx) = inElement; // Dereference Rear THEN Store Element.
        inQ->size++;                                // Queue size increment by 1

        //printLoadSuccess(inQ, inElement);           // Prints success message.

        return true;    // Enqueue : Success.
    }
    else
    {

        inQ->rearIdx++;                                 // Rear increment by 1
        *(inQ->Elements + inQ->rearIdx) = inElement;     // Dereference Rear THEN Store Request.
        inQ->size++;                                    // Queue size increment by 1

        //printLoadSuccess(inQ, inElement);               // Prints success message.

        return true;    // Enqueue : Success.
    }
}
