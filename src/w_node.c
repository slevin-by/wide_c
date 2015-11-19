#include "../include/w_node.h"
#include <stdio.h>
#include <stdlib.h>

static unsigned int currDepth = 0;

Node *createNode(void *data)
{
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	tmp->depth = currDepth = 0;
	return tmp;
}

int addNode(Node **root, Node *newNode)
{
	if (!(*root))
	{
		*root = newNode;
		newNode->depth = currDepth + 1;
		return;
	}
	else if ((*root)->data > newNode->data)
	{
		++currDepth;
	    addNode(&(*root)->left, newNode);
	}
	else if ((*root)->data < newNode->data)
	{
		++currDepth;
	    addNode(&(*root)->right, newNode);
	}
	else
		return 0;
	return 1;
}

Node *getLeft(Node *node)
{
    return node->left;
}

Node *getRight(Node *node)
{
    return node->right;
}

void displayNodes(Node *root)
{
    int i;
    for (i = 0; i < root->depth; i++)
        printf(" ");
    
    printf("%d\n", root->data);
    
    if (getLeft(root))
        displayNodes(getLeft(root));
    if (getRight(root))
        displayNodes(getRight(root));
}

void findNode(Node *node, NodeFinder *finder)
{
	if (!node)
        return;
    if (node->data == finder->data)
    	finder->isFond = 1;
    findNode(node->left, finder);
    findNode(node->right, finder);
}

void nodeGoPrefix(Node *curr, char *format)
{
    if (!curr)
        return;
    printf(format, curr->data);
    nodeGoPrefix(curr->left, format);
    nodeGoPrefix(curr->right, format);
}
