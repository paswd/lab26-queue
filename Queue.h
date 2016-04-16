#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef struct _queue_node QueueNode;
typedef struct _queue Queue;

typedef long long Item;

Queue* queue_create(void);
void queue_destroy(Queue* queue);
void queue_push(Queue* queue, Item value);
Item queue_pop(Queue* queue);
Item queue_first(Queue* queue);

#endif
