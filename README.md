# Generic-Queue-C
Generic Queue implementation using Array in C (C99)

==========================================================================================
Structures:
==========================================================================================
(BufferQueue) is Queue with a size limit.
      > size        - (int) representing current Queue size. 
      > sizeLimit   - (int) representing number of elements Queue can hold.
      > rearIdx     - (int) the index of last stored element. 0 when initialized.
      > Elements    - (Element*) Element pointer will hold all elements. 
      > initialized - (bool) true if the Queue is initialized, false otherwise.
 ==========================================================================================
(Element) - Each Element of Queue. 
      > index     - (int) index of the element in Queue.
      > Data      - (void*) void pointer holding the generic data. 
==========================================================================================
