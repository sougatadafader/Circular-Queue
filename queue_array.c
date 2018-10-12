// Name: 							                                    SougataDafader
// Hours required to complete the Assignment:			        10 hours
// Did you collaborate with any students/TAs/Professors? 	No
// Did you use any external resources?				            No
// What was your favourite part of the assignment?		    I loved implementing a well-known data-structure in C language. 


// =================== Support Code =================
// Queue
//
// - Implement each of the functions.
// - Do not change any of the function declarations
//   - (i.e. queue_t* create_queue(unsigned int _capacity) should not have additional arguments)  
// ==================================================
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// The main data structure for the queue
struct queue {
	unsigned int back;	    // The next free position in the queue
							// (i.e. the end or tail of the line)
	unsigned int front;	    // Current 'head' of the queue
							// (i.e. the front or head of the line)
	unsigned int size;	    // How many total elements we have enqueued.
	unsigned int capacity;  // Number of items the queue can hold
	int* data; 		          // The 'integer' data our queue holds	
};
// Creates a global definition of 'queue_t' so we 
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on
// the heap.
queue_t* create_queue(unsigned int _capacity) {
	queue_t* myQueue = NULL;
	myQueue = (queue_t*)malloc(sizeof(queue_t));
	myQueue->data = (int*)malloc(_capacity* sizeof(int));
	myQueue->capacity = _capacity;
	myQueue->back = -1;
	myQueue->front = 0;
	myQueue->size = 0;
	return myQueue;
}

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has more space available)
int queue_empty(queue_t* q) {
	return (q->size==0);
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available)
int queue_full(queue_t* q) {
	return (q->size == q->capacity);
		
}

// Enqueue a new item
// i.e. push a new queue into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the queue is full).
int queue_enqueue(queue_t *q, int item) {
	int position = (q->back + 1) % q->capacity;
	if (q->size < q->capacity)
	{
		q->back = position;
		q->data[q->back] = item;
		q->size++;
		return 0;
	}
	else
	{
		printf("\nOverflow! Memory allocation error! \n");
		return -1;
	}
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
int queue_dequeue(queue_t *q) {
	int position = (q->front+ 1) % q->capacity;
	if (q->size>0)
	{
		int front_element = q->data[q->front];
		q->front = position;
		q->size--;
		return front_element;
	}
	else
	{
		printf("\nUnderflow! Memory deallocation error!\n");
		return -1;
	}
}


// Queue Size
// Queries the current size of a queue
// A queue that has not been previously created will crash the program.
// (i.e. A NULL q cannot return the size.)
unsigned int queue_size(queue_t* q) {
	return q->size;
}


// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the program terminates.
void free_queue(queue_t* q) {
	
	
	free(q->data);
	free(q);
}

// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1() {
	printf("\n********Running unit test 1********");
	queue_t* test1 = create_queue(3);
	printf("\nAttempting to add %d\n", 1);
	queue_enqueue(test1, 1);
	printf("Attempting to add %d\n", 2);
	queue_enqueue(test1, 2);
	printf("Attempting to add %d\n", 3);
	queue_enqueue(test1, 3);
	printf("Attempting to add %d\n", 4);
	queue_enqueue(test1, 4);
	//printf("Removing: %d\n", queue_dequeue(test1));

	free_queue(test1);
}

void unitTest2() {
	printf("\n********Running unit test 2********");
	queue_t* test2 = create_queue(2);
	printf("\nAttempting to add %d\n", 1);
	queue_enqueue(test2, 1);
	printf("Removing: %d\n", queue_dequeue(test2));
	printf("Removing: %d\n", queue_dequeue(test2));
	printf("Removing: %d\n", queue_dequeue(test2));
	free_queue(test2);
}
void unitTest3() {

	printf("\n********Running unit test 3********");
	queue_t* test1 = create_queue(3);
	printf("\nAttempting to add %d\n", 1);
	queue_enqueue(test1, 1);
	free_queue(test1);
}
// ====================================================
// ================== Program Entry ===================
// ====================================================
int main() {

	// List of Unit Tests to test your data structure	
	unitTest1();
	unitTest2();
	unitTest3();
	return 0;
}
