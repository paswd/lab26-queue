#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "queue.h"

#define QUEUE_NO_ERRORS              0 
#define QUEUE_STACK_OVERFLOW  (1u << 0)
#define QUEUE_STACK_UNDERFLOW (1u << 1)
#define QUEUE_EMPTY 	-9000000000000000000

struct _queue_node {
	Item value;
	QueueNode *next;
};

struct _queue {
	QueueNode *first;
	QueueNode *last;
	int error;
};

Queue *queue_create(void)
{
	Queue *nw = (Queue *) calloc(1, sizeof(Queue));
	nw->first = NULL;
	nw->last = NULL;
	nw->error = 0;
	return nw;
}

void queue_destroy(Queue **queue)
{
	QueueNode *node_del = (*queue)->first;
	while (node_del) {
		QueueNode *tmp = node_del->next;
		free(node_del);
		node_del = tmp;
	}
	free(*queue);
	*queue = NULL;
}

void queue_push(Queue *queue, Item value)
{
	QueueNode *nw = (QueueNode *) calloc(1, sizeof(QueueNode));
	if (!nw) {
		queue->error = 1;
		return;
	}
	//printf("PUSH: TRUE\n");
	nw->value = value;
	nw->next = NULL;
	if (queue->last != NULL) queue->last->next = nw;
	else queue->first = nw;
	queue->last = nw;
}

Item queue_pop(Queue *queue)
{
	if (queue->first == NULL) {
		printf("Queue is empty\n");
		queue->last = NULL;
		return QUEUE_EMPTY;
	}
	Item result = queue->first->value;
	QueueNode *node_del = queue->first;
	queue->first = node_del->next;
	free(node_del);
	node_del = NULL;
	return result;
}

Item queue_first(Queue *queue)
{
	return queue->first->value;
}

/*void queue_print_correct(Queue *queue)
{
	QueueNode *ths = queue->first;
	while (ths) {
		printf("%lld ", ths->value);
		ths = ths->next;
	}
	printf("\n");
}*/

bool queue_is_empty(Queue *queue)
{
	if (queue->first == NULL) {
		queue->last = NULL;
		//printf("Empty: TRUE\n");
		return true;
	}
	//printf("Empty: FALSE\n");
	return false;
}
