#include "../include/w_stack.h"
#include <stdio.h>

Stack *w_stack_create(void)
{
    return w_list_create();
}

void w_stack_destroy(Stack *stack)
{
    w_list_destroy(stack);
}

void w_stack_push(Stack **stack, void *data)
{
    w_list_add_first(stack, data);
}

void w_stack_pop(Stack **stack)
{
    w_list_remove_at(stack, 0);    
}

void *w_stack_top(List **stack)
{
    return w_list_get_at(stack, 0);
}

void w_stack_print(Stack *stack)
{
    w_list_print(stack);
}
