#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "w_common.h"

typedef struct vector_t {
	int *data;
	int size;
	int reserved;
	int isEmpty;
} Vector;

extern Vector *createVoidVector(void);
extern Vector *createVector(int size);
extern void destroyVector(Vector *v);

extern void push_back(Vector *v, int data);
extern void pop_back(Vector *v);

extern int at(Vector *v, int i);

extern void printVector(Vector *v);

#endif // _VECTOR_H_
