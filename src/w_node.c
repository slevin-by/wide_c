#include "../include/w_node.h"
#include <stdio.h>
#include <stdlib.h>

static unsigned int currDepth = 0;

Node *w_node_create(void *data)
{
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	tmp->depth = currDepth = 0;
	return tmp;
}

int w_node_add(Node **root, Node *newNode)
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
        w_node_add(&(*root)->left, newNode);
	}
	else if ((*root)->data < newNode->data)
	{
		++currDepth;
        w_node_add(&(*root)->right, newNode);
	}
	else
		return 0;
	return 1;
}

Node *w_node_get_left(Node *node)
{
    return node->left;
}

Node *w_node_get_right(Node *node)
{
    return node->right;
}

void w_node_display(Node *root)
{
    int i;
    for (i = 0; i < root->depth; i++)
        printf(" ");
    
    printf("%d\n", root->data);
    
    if (w_node_get_left(root))
        w_node_display(w_node_get_left(root));
    if (w_node_get_right(root))
        w_node_display(w_node_get_right(root));
}

void w_node_find(Node *node, NodeFinder *finder)
{
	if (!node)
        return;
    if (node->data == finder->data)
    	finder->isFond = 1;
    w_node_find(node->left, finder);
    w_node_find(node->right, finder);
}

void *w_node_search(Node *node, void *key)
{
	if (node == NULL)
    		return NULL;
	else if (node->data == key)
    		return node;
	else
	{
    		void *left = w_node_search(node->left, key);
    		return left ? left : w_node_search(node->right, key);
	}
}

void w_node_go_prefix(Node *curr, char *format)
{
    if (!curr)
        return;
    printf(format, curr->data);
    w_node_go_prefix(curr->left, format);
    w_node_go_prefix(curr->right, format);
}
