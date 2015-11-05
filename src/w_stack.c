#include "../include/w_stack.h"
#include <stdio.h>

Stack *createStack(void)
{
    return createList();
}

void destroyStack(Stack *stack)
{
    destroyList(stack);
}

void stack_push(Stack **stack, void *data)
{
    addFirstToList(stack, data);
}

void stack_pop(Stack **stack)
{
    removeFromListAt(stack, 0);    
}

void *stack_top(List **stack)
{
    return getListDataAt(stack, 0);
}

void printStack(Stack *stack)
{
    printList(stack);
}
