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

extern Node *w_node_create(void *data);
extern int w_node_add(Node **root, Node *newNode);

extern Node *w_node_get_left(Node *node);
extern Node *w_node_get_right(Node *node);

extern void w_node_display(Node *root);

extern void w_node_find(Node *node, NodeFinder *finder);
extern void w_node_search(Node *node, void *req_data);

extern void w_node_go_prefix(Node *curr, char *format);

#endif // _NODE_H_
