#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"


int main(int argv, char* argc []) {

	PRIORITY_QUEUE Queue;

	int i;
	int j;


	Queue = priority_queue_init_default();

	if (Queue == NULL)
	{
		printf("Failure/n");
		return 0;
	}

	else {

	if (priority_queue_is_empty(Queue))
	{
		for (i = 20; i > 0; i--)
			{
				for (j = 0; j < 20; j++)
				{
					priority_queue_insert(Queue, i, j);
				}
			}
		printf("%d\n", priority_queue_front(Queue, NULL));
	}


	while (!priority_queue_is_empty(Queue)) {
			printf("%d\n", priority_queue_front(Queue, NULL));
			priority_queue_service(Queue);
		}

	}

	priority_queue_destroy(&Queue);


	return 0;


}
