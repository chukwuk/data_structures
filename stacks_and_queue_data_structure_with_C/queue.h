/*
 * This file contains the definition of the interface for the queue you'll
 * implement.  You can find descriptions of the queue functions, including
 * their parameters and their return values, in queue.c.  You should not
 * modify anything in this file.
 */

#ifndef __QUEUE_H
#define __QUEUE_H
#include "dynarray.h"

/*
 * Structure used to represent a queue.
 */
//struct queue;
struct queue {
  struct dynarray* array;
};



/*
 * Queue interface function prototypes.  Refer to queue.c for documentation
 * about each of these functions.
 */
struct queue* queue_create();
void queue_free(struct queue* queue);
int queue_isempty(struct queue* queue);
void queue_enqueue(struct queue* queue, void* val);
void* queue_front(struct queue* queue);
void* queue_dequeue(struct queue* queue);

#endif
