#ifndef _TREE_H_
#define _TREE_H_

#include "w_node.h"

typedef struct tree_t {
    Node *root;
    unsigned int nodeNumber;
} Tree;

extern Tree *createTree(void *rootData);
extern int addToTree(Tree *tree, void *data);
extern void printTree(Tree *tree);

extern int findInTree(Tree *tree, void *data);

extern void treeGoPrefix(Tree *tree, char *format);

#endif // _TREE_H_
