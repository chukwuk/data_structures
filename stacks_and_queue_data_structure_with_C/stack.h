/*
 * This file contains the definition of the interface for the stack you'll
 * implement.  You can find descriptions of the stack functions, including
 * their parameters and their return values, in stack.c.  You should not
 * modify anything in this file.
 */

#ifndef __STACK_H
#define __STACK_H

#include <assert.h>

#include "list.h"


/*
 * Structure used to represent a stack.
 */
//struct stack;

struct stack {
  struct list* list;
};

/*struct stack* stack_create () {
  struct stack* h = malloc(sizeof(struct stack));
  h->list = list_create(); 
  return h;
}

*/
/*
 * Stack interface function prototypes.  Refer to stack.c for documentation
 * about each of these functions.
 */
struct stack* stack_create();
void stack_free(struct stack* stack);
int stack_isempty(struct stack* stack);
void stack_push(struct stack* stack, void* val);
void* stack_top(struct stack* stack);
void* stack_pop(struct stack* stack);
void* stack_last(struct stack* stack);
#endif
