#include <stdio.h>
#include "queue.h"

void PrintQueue(Queue* queue)
{
	QueueNode* ths = queue->first;
	while (ths != NULL) {
		printf("%lld ", ths->value);
		ths = ths->next;
	}
	printf("\n");
}

int main(void)
{
	Queue* queue = queue_create();
	queue_push(queue, 1);
	queue_push(queue, 2);
	queue_push(queue, 3);
	PrintQueue(queue);
	queue_pop(queue);
	PrintQueue(queue);
	return 0;
}