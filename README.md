# Circular-Queue
Implementation of Circluar Queue. This was part of an assignment of Computer System coursework. 

# Building Data Structures - Queue
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/450px-Data_Queue.svg.png" alt="Queue picture">

A 'queue' data structure is analogous to waiting in line at a grocery store. The first person to the checkout counter is served, followed by the next person, and then the next until the line is empty. A queue is what is known as a 'first-in first-out' (FIFO) data structure. Thus queues have a strict policy about how information is stored and accessed.
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
## Part 1 - Queue implementation as an array (Ring Buffer).

A circular buffer has a fixed sized, or maximum number of elements that it can hold. This is advantageous if we know how many elements are typically stored in a data structure (If we do not know, then a queue with a linked list implemetation is needed). 

For more information on the Circular buffer, see here: https://en.wikipedia.org/wiki/Circular_buffer

This animation below gives an idea about how the data structure 'wraps' around. Think about what mathematical operator could be useful in your implementation when enqueuing and dequeuing items in your queue.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif)


You *may* also consider writing some unit tests to test your implementation. You can include those in your submission, but we will have our own test suite.

----------------------------------------------------------------------------------------------------------------------------------------

## Part 2 - Why is a ring buffer/circular queue useful?

A queue is a line or a sequence based on a particular order. The first item inserted in the queue is at the first place, the next item is placed behind it, and so on. The main objective of maintaining a queue architecture is that the element at the first position always comes out first. 
The main advantage of a ring or circular buffer is that existing items doesn't need to be shuffled around everytime a new item is added. 
This saves O(n) time since that is the time required to shuffle or shift n elements. The queue architechture also makes sure that the first job gets executed first, which is very important in case of any OS. Also the limited memory makes sure that the memory is constrained and does not consume more than required memory. Even though, that leads to a disadvantage as only finite number (fixed size of buffer) of processes, that is less than or equal to capacity of the queue can be processed. If the queue is full and we try to add another process, then it will throw an error, and the new process will have to wait until a space becomes free inside the queue. 
  Also reading and writing of data using direct memory access, increases the efficiency of any task. 
  
  Circular buffers should be used for processing tasks in a FIFO manner, whereas any non-circular buffers are better suited for processing tasks in LIFO manner. In terms of OS, this is important as users expect the first job that was executed to processed first.
  
