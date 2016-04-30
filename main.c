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
	//int cnt = 0;
	for (int i = 0; i < n; i++) {
		
		
		Item tmp;
		scanf("%lld", &tmp);
		bool is_inserted = false;
		while (!queue_is_empty(queue)) {
			if (tmp > queue_first(queue) && !is_inserted) {
				is_inserted = true;
				queue_push(queue_sub, tmp);
			} else {
				queue_push(queue_sub, queue_pop(queue));
			}
		}
		Queue* queue_tmp = queue;
		queue = queue_sub;
		queue_sub = queue_tmp;
	}
	printf("SUB\n");
	if (queue_is_empty(queue)) printf("True\n");
	else printf("False\n");
	if (queue_is_empty(queue_sub)) printf("True\n");
	else printf("False\n");
	//printf("%lld\n", queue_first(queue));
	/*for (int i = 0; i < n; i++) {
		cnt++;
		printf("%d\n", cnt);
		printf("%lld ", queue_pop(queue));
	}*/
	printf("\n");
	queue_destroy(&queue_sub);
	queue_destroy(&queue);
	return 0;
}