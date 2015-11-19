#include "../include/w_stack.h"
#include <stdio.h>

Stack *createStack(void)
{
    return w_list_create();
}

void destroyStack(Stack *stack)
{
    w_list_destroy(stack);
}

void stack_push(Stack **stack, void *data)
{
    w_list_add_first(stack, data);
}

void stack_pop(Stack **stack)
{
    w_list_remove_at(stack, 0);    
}

void *stack_top(List **stack)
{
    return w_list_get_at(stack, 0);
}

void printStack(Stack *stack)
{
    w_list_print(stack);
}
