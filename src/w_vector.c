#include "../include/w_vector.h"
#include <stdlib.h>

Vector *w_vector_create_void(void)
{
	Vector *v = (Vector *)calloc(1, sizeof(Vector));
	v->data = (int *)calloc(1, sizeof(int));
	v->reserved = 0;
	v->size = 1;
    v->isEmpty = 1;
	return v;
}

Vector *w_vector_create(int size)
{
	Vector *v = (Vector *)calloc(1, sizeof(Vector));
	v->data = (void *)calloc(size, sizeof(int));
	v->size = size;
	v->reserved = 0;
    v->isEmpty = 1;
	return v;
}

void w_vector_destroy(Vector *v)
{
	if (v)
		free(v);
}

void w_vector_push_back(Vector *v, int data)
{
	if (v->size == 1 && v->isEmpty)
	{
		v->data[v->reserved] = data;
        v->isEmpty = 0;
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

void w_vector_pop_back(Vector *v)
{
	if (v->reserved != 0)
		--(v->reserved);
	else
        v->isEmpty = 1;
}

int w_vector_get_at(Vector *v, int i)
{
	if (i >= 0 && i < v->reserved)
		return v->data[i];
	return NULL;
}

int w_vector_set_at(Vector *v, int i, int data)
{
    if (i >= 0 && i <= v->reserved)
    {
        v->data[i] = data;
        v->isEmpty = 0;
        v->reserved++;
        return 1;
    }
    else
        return 0;
}

void w_vector_print(Vector *v)
{
	int i;
	for (i = 0; i < v->reserved; i++)
		printf("%d ", v->data[i]);
	printf("\n");
}
