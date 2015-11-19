#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "w_list.h"

typedef struct list_t Queue;

extern Queue *w_queue_create(void);
extern void w_queue_destroy(Queue *queue);

extern void w_queue_push(Queue **queue, void *data);
extern void w_queue_pop(Queue **queue);
extern void *w_queue_top(Queue **queue);

extern void w_queue_print(Queue *queue);

#endif // _QUEUE_H_
