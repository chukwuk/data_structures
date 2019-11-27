/*
 * This file contains the definition of the interface for a dynamic array.
 * You can find descriptions of the dynamic array functions, including their
 * parameters and their return values, in dynarray.c.
 *
 * You should not modify this file.
 */

#ifndef __DYNARRAY_H
#define __DYNARRAY_H

/*
 * Structure used to represent a dynamic array.
 */
//struct dynarray;
struct store_data {
  int priority;
  void* value;
};
struct dynarray {
  struct store_data* data;
  int size;
  int capacity;
};
/*
 * Dynamic array interface function prototypes.  Refer to dynarray.c for
 * documentation about each of these functions.
 */
struct dynarray* dynarray_create();
void dynarray_free(struct dynarray* da);
int dynarray_size(struct dynarray* da);
void dynarray_insert(struct dynarray* da, void* val, int prio);
void dynarray_remove(struct dynarray* da);
struct store_data  dynarray_get(struct dynarray* da, int idx);
void dynarray_set(struct dynarray* da, int idx, void* val);
void re_arr_aft_ins(struct dynarray* da);
void re_arr_aft_removal(struct dynarray* da);
int dynarray_get_prio(struct dynarray* da, int idx);
void swap_function(struct dynarray* da, int* parent, int* child);
#endif
