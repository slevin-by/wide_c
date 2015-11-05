#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "jlist.h"

typedef struct list_t Queue;

extern Queue *createQueue(void);
extern void destroyQueue(Queue *queue);

extern void queue_push(Queue **queue, void *data);
extern void queue_pop(Queue **queue);
extern void *queue_top(Queue **queue);

extern void printQueue(Queue *queue);

#endif // _QUEUE_H_
