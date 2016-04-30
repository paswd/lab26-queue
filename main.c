#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "queue.h"

int main(void)
{
	Queue* queue = queue_create();
	Queue* queue_sub = queue_create();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {		
		Item tmp;
		scanf("%lld", &tmp);
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
		Queue* queue_tmp = queue;
		queue = queue_sub;
		queue_sub = queue_tmp;
	}

	for (int i = 0; i < n; i++) printf("%lld ", queue_pop(queue));

	printf("\n");
	queue_destroy(&queue_sub);
	queue_destroy(&queue);
	return 0;
}