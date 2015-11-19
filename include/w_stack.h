#ifndef _STACK_H_
#define _STACK_H_

#include "w_list.h"

typedef struct list_t Stack;

extern Stack *w_stack_create(void);
extern void w_stack_destroy(Stack *stack);

extern void w_stack_push(Stack **stack, void *data);
extern void w_stack_pop(Stack **stack);
extern void *w_stack_top(Stack **stack);

extern void w_stack_print(Stack *stack);

#endif // _STACK_H_
