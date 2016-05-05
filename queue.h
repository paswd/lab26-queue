#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef long long Item;

typedef struct _queue_node QueueNode;
typedef struct _queue Queue;

Queue* queue_create(void);
void queue_destroy(Queue **queue);
void queue_push(Queue *queue, Item value);
Item queue_pop(Queue *queue);
Item queue_first(Queue *queue);
//void queue_print_correct(Queue *queue);
bool queue_is_empty(Queue *queue);


#endif
