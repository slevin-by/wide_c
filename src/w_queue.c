#include "../include/w_queue.h"
#include <stdio.h>

Queue *createQueue(void)
{
    return createList();
}

void destroyQueue(Queue *queue)
{
    destroyList(queue);
}

void queue_push(Queue **queue, void *data)
{
    addLastToList(queue, data);    
}

void queue_pop(Queue **queue)
{
    removeFromListAt(queue, (*queue)->size-1);
}

void *queue_top(Queue **queue)
{
    return getListDataAt(queue, (*queue)->size-1);
}

void printQueue(Queue *queue)
{
    printList(queue);
}
