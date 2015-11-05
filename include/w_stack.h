#ifndef _STACK_H_
#define _STACK_H_

#include "jlist.h"

typedef struct list_t Stack;

extern Stack *createStack(void);
extern void destroyStack(Stack *stack);

extern void stack_push(Stack **stack, void *data);
extern void stack_pop(Stack **stack);
extern void *stack_top(Stack **stack);

extern void printStack(Stack *stack);

#endif // _STACK_H_
