 /* A linked list implementation of a queue. */
 /* * Most of the code is taken from textbook:
  *     "A Book on C" by Al Kelley and Ira Pohl */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY   0
#define FULL    10000

typedef unsigned int        data;
typedef enum {false, true}  boolean;

struct elem {           /* an elemnt in the queue */
    data  d;
    struct elem  *next;
};

typedef struct elem     elem;
struct queue {
    int  cnt;           /* count of the elements */
    elem  *front;       /* ptr to the front element */
    elem  *rear;        /* ptr to the rear element */
};

typedef struct queue   queue;
void    initialize(queue *q);
void    enqueue(data d, queue *q);
data    dequeue(queue *q);
boolean empty(const queue *q);
boolean full(const queue *q); 
