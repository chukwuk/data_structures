/*
 * This file contains the definition of the interface for the binary search
 * tree you'll implement.  You should not modify anything in this file.  You
 * can find descriptions of the binary search tree functions, including their
 * parameters and their return values, in bst.c.
 */

#ifndef __BST_H
#define __BST_H

/*
 * Structure used to represent a binary search tree.
 */
//struct bst;
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};

struct bst {
  struct bst_node* root;
};


/*
 * Binary search tree interface function prototypes.  Refer to bst.c for
 * documentation about each of these functions.
 */
struct bst* bst_create();
struct bst_node* create_node(void* val, int k);
void bst_free(struct bst* bst);
int bst_size(struct bst* bst);
void bst_insert(struct bst* bst, int key, void* value);
void bst_remove(struct bst* bst, int key);
void* bst_get(struct bst* bst, int key);
void inorder(struct bst_node* bst);
void size(struct bst_node* bst_nod, int* k);
void free_nod(struct bst_node* bst_nod);
void remove_leaf_node(struct bst_node* parent, struct bst_node* nod, int key, struct bst* bst);
void remove_node_1_child(struct bst_node* parent, struct bst_node* nod, int key, struct bst* bst);
void remove_node_2_child(struct bst_node* parent, struct bst_node* nod, int key, struct bst* bst);
struct bst_node* most_left_node(struct bst_node* find_left);
struct bst_node* parent_most_left_node(struct bst_node* find_left);
void remove_node_2_child_with_parent(struct bst_node* parent, struct bst_node* nod, int key);
void remove_node_2_child_without_parent(struct bst_node* parent, struct bst_node* nod, int key, struct bst* bst); 
//struct bst* list_iterator_create(struct bst* list);
//void list_iterator_free(struct bst* iter);
#endif
