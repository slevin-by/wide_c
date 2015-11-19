#include "../include/w_tree.h"
#include <stdlib.h>

Tree *w_tree_create(void *rootData)
{
    Tree *new_tree = (Tree *)malloc(sizeof(Tree));
    new_tree->root = w_node_create(rootData);
    new_tree->nodeNumber = 1;
    
    return new_tree;
}

int w_tree_add(Tree *tree, void *data)
{
    ++(tree->nodeNumber);
    return w_node_add(&(tree->root), w_node_create(data));
}

void w_tree_print(Tree *tree)
{
    w_node_display(tree->root);
}

int w_tree_find(Tree *tree, void *data)
{
    NodeFinder finder;
    finder.data = data;
    finder.isFond = 0;
    
    w_node_find(tree->root, &finder);
    
    return finder.isFond;
}

void w_tree_go_prefix(Tree *tree, char *format)
{
    w_node_go_prefix(tree->root, format);
}
