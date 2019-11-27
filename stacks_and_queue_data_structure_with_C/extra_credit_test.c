/*
 *  * This file contains executable code for testing your queue-from-stacks
 *   * implementation.
 *    */

#include <stdio.h>
#include <stdlib.h>

#include "queue_from_stacks.h"

int main(int argc, char** argv) {
  int simfront, simback, i, n = 16, k_deq = 4, k_enq = 8;
  int* test_data;
  int** simqueue;
  struct queue_from_stacks* q;

  /*
 *    * Create array of testing data.
 *       */
  test_data = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    test_data[i] =  i * i;
  }

  /*
 *    * Create queue-from-stacks and enqueue part of the testing data into it.
 *       * Simulate a queue in the simqueue array (with current front/back kept track
 *          * of in simfront/simback).
 *             */
  q = queue_from_stacks_create();
  simqueue = malloc(n * sizeof(int*));
  simfront = simback = 0;
  printf("== Enqueueing first %d of %d values.\n", k_enq, n);
  for (i = 0; i < k_enq; i++) {
    queue_from_stacks_enqueue(q, &test_data[i]);
    simqueue[simback++] = &test_data[i];
  }
  
   int* front = queue_from_stacks_front(q);
   int* dequeued = queue_from_stacks_dequeue(q);
   int* fron = queue_from_stacks_front(q);
  
   printf("The first number is %d \n", *fron);
   queue_from_stacks_free(q);
  free(test_data);
  free(simqueue);

  return 0;

}
