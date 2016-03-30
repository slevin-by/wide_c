#ifndef _TREE_H_
#define _TREE_H_

#include "w_node.h"

typedef struct tree_t {
    Node *root;
    unsigned int nodeNumber;
} Tree;

extern Tree *w_tree_create(void *rootData);
extern void w_tree_destroy(Tree *tree);
extern int w_tree_add(Tree *tree, void *data);
extern void w_tree_print(Tree *tree);

extern int w_tree_find(Tree *tree, void *data);

extern void w_tree_go_prefix(Tree *tree, char *format);

#endif // _TREE_H_
