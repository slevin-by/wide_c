#include "../include/w_queue.h"
#include <stdio.h>

Queue *w_queue_create(void)
{
    return w_list_create();
}

void w_queue_destroy(Queue *queue)
{
    w_list_destroy(queue);
}

void w_queue_push(Queue **queue, void *data)
{
    w_list_add_last(queue, data);
}

void w_queue_pop(Queue **queue)
{
    w_list_remove_at(queue, (*queue)->size-1);
}

void *w_queue_top(Queue **queue)
{
    return w_list_get_at(queue, (*queue)->size-1);
}

void w_queue_print(Queue *queue)
{
    w_list_print(queue);
}
