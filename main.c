#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "queue.h"

void queue_sort(Queue *queue_basic)
{
	Queue *queue = queue_create();
	Queue *queue_sub = queue_create();
	while (!queue_is_empty(queue_basic)) {	
		Item tmp = queue_pop(queue_basic);
		bool is_inserted = false;
		while (!queue_is_empty(queue)) {
			if (tmp < queue_first(queue) && !is_inserted) {
				is_inserted = true;
				queue_push(queue_sub, tmp);
			} else {
				queue_push(queue_sub, queue_pop(queue));
			}
		}
		if (!is_inserted) queue_push(queue_sub, tmp);
		Queue *queue_tmp = queue;
		queue = queue_sub;
		queue_sub = queue_tmp;
	}

	while (!queue_is_empty(queue)) {
		queue_push(queue_basic, queue_pop(queue));
	}

	queue_destroy(&queue_sub);
	queue_destroy(&queue);
}

void queue_print(Queue *queue)
{
	printf("Input\n");
	Queue *tmp = queue_create();
	while (!queue_is_empty(queue)) {
		Item value = queue_pop(queue);
		printf("%lld ", value);
		queue_push(tmp, value);
	}
	printf("\n");
	while (!queue_is_empty(tmp)) {
		queue_push(queue, queue_pop(tmp));
	}
	queue_destroy(&tmp);
}

int main(void)
{
	/*Queue *queue = queue_create();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Item tmp;
		scanf("%lld", &tmp);
		queue_push(queue, tmp);
	}
	queue_sort(queue);
	queue_print(queue);
	queue_destroy(&queue);*/
	Queue *queue = queue_create();
	printf("-------------------------------------------\n");
	printf("Commands:\n");
	printf("a <value> - push to queue\n");
	printf("d - pop from queue and print popped item\n");
	printf("s - sort queue\n");
	printf("p - print queue\n");
	printf("q - exit\n");
	printf("-------------------------------------------\n");
	while (true) {
		char cmd;
		Item value = 0;
		bool is_finished = false;
		scanf("%c", &cmd);
		switch (cmd) {
			case 'q':
				is_finished = true;
				break;
			case 'a':
				scanf("%lld", &value);
				queue_push(queue, value);
				break;
			case 'd':
				printf("%lld\n", queue_pop(queue));
				break;
			case 's':
				queue_sort(queue);
				//queue_print(queue);
				break;
			case 'p':
				queue_print(queue);
				break;
			case '\n':
				break;
			default:
				printf("Invalid command `%c`\n", cmd);
				break;
		}
		if (is_finished) break;
	}
	printf("Goodbye!\n");

	return 0;
}
