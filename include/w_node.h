#ifndef _NODE_H_
#define _NODE_H_

typedef struct node_finder_t {
	void *data;
	int isFond;
} NodeFinder;

typedef struct node_t {
	void *data;
	struct node_t *left;
	struct node_t *right;
	
	unsigned int depth;
} Node;

extern Node *createNode(void *data);
extern boolean addNode(Node **root, Node *newNode);

extern Node *getLeft(Node *node);
extern Node *getRight(Node *node);

extern void displayNodes(Node *root);

extern void findNode(Node *node, NodeFinder *finder);

extern void nodeGoPrefix(Node *curr, char *format);

#endif // _NODE_H_