#include "../include/w_tree.h"
#include <stdlib.h>

Tree *createTree(void *rootData)
{
    Tree *new_tree = (Tree *)malloc(sizeof(Tree));
    new_tree->root = createNode(rootData);
    new_tree->nodeNumber = 1;
    
    return new_tree;
}

int addToTree(Tree *tree, void *data)
{
    ++(tree->nodeNumber);
    return addNode(&(tree->root), createNode(data));
}

void printTree(Tree *tree)
{
    displayNodes(tree->root);
}

boolean findInTree(Tree *tree, void *data)
{
    NodeFinder finder;
    finder.data = data;
    finder.isFond = FALSE;
    
    findNode(tree->root, &finder);
    
    return finder.isFond;
}

void treeGoPrefix(Tree *tree, char *format)
{
    nodeGoPrefix(tree->root, format);
}
