#include "../include/w_vector.h"
#include <stdlib.h>

Vector *createVoidVector(void)
{
	Vector *v = (Vector *)calloc(1, sizeof(Vector));
	v->data = (int *)calloc(1, sizeof(int));
	v->reserved = 0;
	v->size = 1;
	v->isEmpty = TRUE;
	return v;
}

Vector *createVector(int size)
{
	Vector *v = (Vector *)calloc(1, sizeof(Vector));
	v->data = (void *)calloc(size, sizeof(int));
	v->size = size;
	v->reserved = 0;
	v->isEmpty = TRUE;
	return v;
}

void destroyVector(Vector *v)
{
	if (v)
		free(v);
}

void push_back(Vector *v, int data)
{
	if (v->size == 1 && v->isEmpty)
	{
		v->data[v->reserved] = data;
		v->isEmpty = FALSE;
		++(v->reserved);
		return;
	}
	else if (v->reserved != v->size)
	{
		v->data[v->reserved] = data;
		++(v->reserved);
		return;
	}
	else
	{
		v->data = (int *)realloc(v->data, v->size * 2 * sizeof(int));
		v->data[v->reserved] = data;
		v->size *= 2;
		++(v->reserved);
	}
}

void pop_back(Vector *v)
{
	if (v->reserved != 0)
		--(v->reserved);
	else
		v->isEmpty = TRUE;
}

int at(Vector *v, int i)
{
	if (i >= 0 && i < v->reserved)
		return v->data[i];
	return NULL;
}

void printVector(Vector *v)
{
	int i;
	for (i = 0; i < v->reserved; i++)
		printf("%d ", v->data[i]);
	printf("\n");
}
