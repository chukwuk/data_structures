/*
 * This file is where you should implement your binary search tree.  It already
 * contains skeletons of the functions you need to implement (along with
 * documentation for each function).  Feel free to implement any additional
 * functions you might need.  Also, don't forget to include your name and
 * @oregonstate.edu email address below.
 *
 * Name:Kingsley Chukwuma Chukwu
 * Email:chukwuk@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

/*
 * This structure represents a single node in a BST.  In addition to containing
 * pointers to its two child nodes (i.e. `left` and `right`), it contains two
 * fields representing the data stored at this node.  The `key` field is an
 * integer value that should be used as an identifier for the data in this
 * node.  Nodes in the BST should be ordered based on this `key` field.  The
 * `value` field stores data associated with the key.
 *
 * You should not modify this structure.
 */
/*
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};
*/

/*
 * This structure represents an entire BST.  It specifically contains a
 * reference to the root node of the tree.
 *
 * You should not modify this structure.
 */
/*
struct bst {
  struct bst_node* root;
};
*/
/*
 * This function should allocate and initialize a new, empty, BST and return
 * a pointer to it.
 */
struct bst* bst_create() {
  struct bst* new_bst = malloc(sizeof(struct bst));
  new_bst->root = NULL; 
  return new_bst;
}

struct bst_node* create_node(void* val, int k) {
   struct bst_node* new_bst_node = malloc(sizeof(struct bst_node)); 
   new_bst_node->value = val;
   new_bst_node->key = k;
   new_bst_node->left = NULL;
   new_bst_node->right = NULL;
   return new_bst_node;
}

void free_nod(struct bst_node* bst_nod) {
     if (bst_nod==NULL) {
      return;
     } else {
     struct bst_node* temp = bst_nod->left;
     struct bst_node* temp_1 = bst_nod->right;
     free(bst_nod);
     free_nod(temp);
     free_nod(temp_1);
    }
}


/*
 * This function should free the memory associated with a BST.  While this
 * function should up all memory used in the BST itself, it should not free
 * any memory allocated to the pointer values stored in the BST.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   bst - the BST to be destroyed.  May not be NULL.
 */
void bst_free(struct bst* bst) {
  free_nod(bst->root);
  free(bst);
}


/*
 * This function should return the total number of elements stored in a given
 * BST.
 *
 * Params:
 *   bst - the BST whose elements are to be counted.  May not be NULL.
 */

void size(struct bst_node* bst_nod, int* k) {
   if (bst_nod==NULL) {
      return;
   } else {
     (*k)+=1;
     struct bst_node* temp = bst_nod->left;
     struct bst_node* temp_1 = bst_nod->right;
     size(temp, k);
     size(temp_1, k);
   }

}

int bst_size(struct bst* bst) {
  int k = 0;
  size(bst->root, &k);
  return k;
}

/*
 * This function should insert a new key/value pair into the BST.  The key
 * should be used to order the key/value pair with respect to the other data
 * stored in the BST.  The value should be stored along with the key, once the
 * right location in the tree is found.
 *
 * Params:
 *   bst - the BST into which a new key/value pair is to be inserted.  May not
 *     be NULL.
 *   key - an integer value that should be used to order the key/value pair
 *     being inserted with respect to the other data in the BST.
 *   value - the value being inserted into the BST.  This should be stored in
 *     the BST alongside the key.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void bst_insert(struct bst* bst, int key, void* value) {
  if (bst->root==NULL) {
     bst->root = create_node(value, key);
     return;
  }
  struct bst_node* temp = bst->root;
  if (key < bst->root->key) {
         if (bst->root->left !=NULL) {
         bst->root = bst->root->left; 
         bst_insert(bst, key, value);
         } else {
         bst->root->left = create_node(value, key);
         return;
         }
   }  else if (key >= bst->root->key) {
       if (bst->root->right !=NULL) {
         bst->root = bst->root->right;
         bst_insert(bst, key, value); 
       }  else { 
        bst->root->right = create_node(value, key);
        return;
       }
   } 
   bst->root = temp;
   return;

}

void inorder(struct bst_node* bst) {
// struct bst_node* temp = bst->root;
 if (bst!= NULL) 
    { 
        inorder(bst->left);
        int* h = bst->value; 
        printf("%d \n", * h); 
        inorder(bst->right); 
    } 
}

void remove_leaf_node(struct bst_node* parent, struct bst_node* nod, int key, struct bst* bst) {
        if (parent == NULL) {
           bst->root = NULL;
           free(nod);
        } else {
           if (parent->left == nod)  {
            parent->left = NULL;
            free(nod);
           } else {  
             parent->right = NULL;
             free(nod);
          }
       
 }
 }
void remove_node_1_child(struct bst_node* parent, struct bst_node* nod, int key, struct bst* bst) {
      if (parent == NULL) {
         if (nod->right == NULL) {
           bst->root = bst->root->left;
           free(nod);
      }   else {
          bst->root = bst->root->right;
          free(nod);
      }
      } else {
       if (parent->left == nod) {
          if (nod->right == NULL) {
           parent->left = nod->left;
           free(nod);
          } else {
          parent->left = nod->right;
          free(nod);
      }

      } else {
          if (nod->right == NULL) {
           parent->right = nod->left;
           free(nod);
          } else {
          parent->right = nod->right;
          free(nod);
         
         }
       }
     }
}

struct bst_node* most_left_node(struct bst_node* find_left) {
      struct bst_node* temp = find_left->right;
      while (temp->left!=NULL) {
         temp = temp->left;
      }
      return temp;
}

struct bst_node* parent_most_left_node(struct bst_node* find_left) {
      struct bst_node* temp  = find_left->right;
      struct bst_node* parent = NULL;
      while (temp->left!=NULL) {
         parent = temp;
         temp = temp->left;
      }
      return parent;
}


void remove_node_2_child_with_parent(struct bst_node* parent, struct bst_node* nod, int key) {
    if (parent->left == nod) {
          if (parent_most_left_node(nod) == NULL) {
             parent->left  = most_left_node(nod); parent->left->left = nod->left;
             free(nod);
          } else {
            parent->left  = most_left_node(nod);
            struct bst_node* p = parent_most_left_node(nod);
            p->left = parent->left->right;
            parent->left->left = nod->left;  parent->left->right = nod->right;
            free(nod);
          }
     }   else if (parent->right == nod) {
           if (parent_most_left_node(nod) == NULL) {
             parent->right  = most_left_node(nod); parent->right->left = nod->left;
             free(nod);
            } else {
            parent->right  = most_left_node(nod);
            struct bst_node* p = parent_most_left_node(nod);
            p->left = parent->right->right;
            parent->right->left = nod->left;  parent->right->right = nod->right;
          free(nod);
     }
     }

}

void remove_node_2_child_without_parent(struct bst_node* parent, struct bst_node* nod, int key, struct bst* bst) {
     struct bst_node* right = bst->root->right;
     struct bst_node* left = bst->root->left;
      if (parent_most_left_node(nod) == NULL) {
         bst->root = most_left_node(nod);
         bst->root->left = left;
         free(nod);
       } else {
       struct bst_node* p = parent_most_left_node(nod);
       struct bst_node* s = most_left_node(nod);
       p->left = s->right;
       s->right = right;
       s->left = left;
       bst->root = s;
       free(nod);
       }
}
/*
struct bst* list_iterator_create(struct bst* list) {
  struct bst* iter = malloc(sizeof(struct bst));
  iter = list;
  return iter;
}

void list_iterator_free(struct bst* iter) {
  free(iter);
}*/


void remove_node_2_child(struct bst_node* parent, struct bst_node* nod, int key, struct bst* bst) {
     if (parent == NULL) {
       remove_node_2_child_without_parent(parent, nod, key, bst);
     } else {
         remove_node_2_child_with_parent(parent, nod, key);
      } 
    
}

/*
 * This function should remove a key/value pair with a specified key from a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should remove the first one it encounters (i.e. the one closest to
 * the root of the tree).
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair to be removed from the BST.
 */
void bst_remove(struct bst* bst, int key) {
  struct bst_node* nod = bst->root;
  struct bst_node* parent = NULL;
  while(nod!=NULL) {
  if (nod->key == key) {
   if (nod->left == NULL && nod->right == NULL) {
       //printf("the node key is %d\n",nod->key);
       remove_leaf_node(parent, nod, key, bst);
    } else if ((nod->left == NULL && nod->right != NULL) || (nod->left != NULL && nod->right == NULL)) {
       remove_node_1_child( parent,  nod,  key,  bst);
    } else if ((nod->left != NULL && nod->right != NULL) )  {  
         remove_node_2_child (parent,  nod,  key,  bst);    
    }    
   break;    
  } else if (key<nod->key) {
    parent = nod;
    nod = nod->left;
  } else {
   parent = nod;
   nod = nod->right;
  }
  }

  return;
}

/*
 * This function should return the value associated with a specified key in a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should return the first one it encounters (i.e. the one closest to
 * the root of the tree).  If the BST does not contain the specified key, this
 * function should return NULL.
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair whose value is to be returned.
 *
 * Return:
 *   Should return the value associated with the key `key` in `bst` or NULL,
 *   if the key `key` was not found in `bst`.
 */
void* bst_get(struct bst* bst, int key) {
  struct bst_node* nod = bst->root;
  while(nod!=NULL) {
  if (nod->key == key) {
    return nod->value;
  } else if (key<nod->key) {
    nod = nod->left;
  } else {
   nod = nod->right;
  }
  }
  //int k = 1;
  //void* u = &k;
  return NULL;
}
