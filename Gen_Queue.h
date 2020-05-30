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

typedef struct
{
    int index;
    void* Data

}Element;

typedef  struct
{
    int size;
    int sizeLimit;
    int frontIdx;
    int rearIdx;
    Element* Elements;

}BufferQueue;


void init_BufferQueue(BufferQueue* inQ, int bufferSize);                     // Create and Initialize Queue

bool isEmpty(BufferQueue* inQ);         // Check if Queue is Empty, returns True if Queue is empty or False otherwise.
bool isFull(BufferQueue* inQ);          // Check if Queue is Full, returns True if Queue is full, or False otherwise.

bool enqueue(BufferQueue* inQ, Element inElement);              // Enqueue, returns true if Enqueue is success.
Element dequeue(BufferQueue* inQ);                              // Dequeue (Request), returns dequeue-ed (Request)

Element peekFirst(BufferQueue* inQ);    // Returns a copy of the First Element in Queue
Element peekLast(BufferQueue* inQ);     // Returns a copy of the Last Element in Queue

void printAll(BufferQueue* inQ);

#endif //GENERIC_QUEUE_GEN_QUEUE_H
