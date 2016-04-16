#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queue.h"

struct _queue_node {
	Item value;
	QueueNode* next;
};

struct _queue {
	QueueNode* first;
	QueueNode* last;
	int error;
};

Queue* queue_create(void)
{
	Queue* nw = (Queue *) calloc(1, sizeof(Queue));
	nw->first = NULL;
	nw->last = NULL;
	nw->error = 0;
	return nw;
}
void queue_destroy(Queue* queue)
{
	QueueNode* node_del = queue->first;
	while (node_del != NULL) {
		QueueNode* tmp = node_del->next;
		free(node_del);
		node_del = tmp;
	}
	free(queue);
}
void queue_push(Queue* queue, Item value)
{
	QueueNode* nw = (QueueNode *) calloc(1, sizeof(QueueNode));
	if (nw == NULL){
		queue->error = 1;
		return;
	}
	nw->value = value;
	nw->next = NULL;
	if (queue->last) queue->last->next = nw;
	else {
		queue->first = nw;
		queue->last = nw;
	}
}
Item queue_pop(Queue* queue)
{
	Item result = queue->first->value;
	QueueNode* node_del = queue->first;
	queue->first = node_del->next;
	free(node_del);
	return result;
}
Item queue_first(Queue* queue)
{
	return queue->first->value;
}