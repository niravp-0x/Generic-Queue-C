/*
 * Project : Generic Queue
 * FILE : Gen_Queue.h
 *
 * Author : Nirav PANCHAL
 * Contact : nirav.xv@gmail.com
 *
 * Header.h file for the generic queue.
 * Queue structure and methods declaration.
 *
 */

#ifndef GENERIC_QUEUE_GEN_QUEUE_H
#define GENERIC_QUEUE_GEN_QUEUE_H

#include<stdbool.h>
#define SPACER "----------------------------------------------------------------\n"

/*
 Can be implemented if need to

#define MIN_BUFFER 8            // Minimum buffer size limit
#define MAX_BUFFER 264          // Maximum buffer size limit



typedef struct
{
    int x;
    int y;
    char* det;
}Boom;
*/

typedef struct
{
    int index;
    void* Data;

}Element;

typedef  struct
{
    int size;
    int sizeLimit;
    int rearIdx;
    Element* Elements;
    bool initialized;

}BufferQueue;

void freeMe(BufferQueue* inQ);

int userSetBufferLimit();               // Prompts user to set the buffer size limit and returns

void init_BufferQueue(BufferQueue* inQ, int bufferSize);       // Create and Initialize Queue

bool isEmpty(BufferQueue* inQ);         // Check if Queue is Empty, returns True if Queue is empty or False otherwise.
bool isFull(BufferQueue* inQ);          // Check if Queue is Full, returns True if Queue is full, or False otherwise.

bool enqueue(BufferQueue* inQ, Element inElement);              // Enqueue, returns true if Enqueue is success.
bool dequeue(BufferQueue* inQ, Element* deqElement);            // Dequeue (Request), returns dequeue-ed (Request)

void printMessage(char* operation, Element* inElement);

Element peekFirst(BufferQueue* inQ);    // Returns a copy of the First Element in Queue
Element peekLast(BufferQueue* inQ);     // Returns a copy of the Last Element in Queue

void printAll(BufferQueue* inQ);

#endif //GENERIC_QUEUE_GEN_QUEUE_H

