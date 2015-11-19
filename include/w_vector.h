#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct vector_t {
	int *data;
	int size;
	int reserved;
	int isEmpty;
} Vector;

extern Vector *w_vector_create_void(void);
extern Vector *w_vector_create(int size);
extern void w_vector_destroy(Vector *v);

extern void w_vector_push_back(Vector *v, int data);
extern void w_vector_pop_back(Vector *v);

extern int w_vector_get_at(Vector *v, int i);
extern int w_vector_set_at(Vector *v, int i, int data);

extern void w_vector_print(Vector *v);

#endif // _VECTOR_H_
