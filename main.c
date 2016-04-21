#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queue.h"

int main(void)
{
	Queue* queue = queue_create();
	queue_push(queue, 1);
	queue_push(queue, 2);
	queue_push(queue, 3);
	queue_push(queue, 4);
	queue_push(queue, 5);
	queue_print(queue);
	queue_pop(queue);
	queue_print(queue);
	queue_pop(queue);
	queue_print(queue);
	queue_destroy(&queue);
	return 0;
}