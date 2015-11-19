#include "../include/w_queue.h"
#include <stdio.h>

Queue *createQueue(void)
{
    return w_list_create();
}

void destroyQueue(Queue *queue)
{
    w_list_destroy(queue);
}

void queue_push(Queue **queue, void *data)
{
    w_list_add_last(queue, data);
}

void queue_pop(Queue **queue)
{
    w_list_remove_at(queue, (*queue)->size-1);
}

void *queue_top(Queue **queue)
{
    return w_list_get_at(queue, (*queue)->size-1);
}

void printQueue(Queue *queue)
{
    w_list_print(queue);
}
