#include <stdio.h>
#include "priority_queue.h"


PRIORITY_QUEUE priority_queue_init_default(void)
{

	Queue* pQueue = (Queue*)malloc(sizeof(Queue));

		if (pQueue != NULL) {
			pQueue->size = 0;
			pQueue->capacity = 20;
			pQueue->arr = (Array**)malloc(sizeof(Array*) * pQueue->capacity);

		}

		return (PRIORITY_QUEUE)pQueue;

}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_priority, int data_item)
{
	Queue* pQueue = (Queue*)hQueue;

	Array* temp;
	Array** TempArray;
	int i = 0;

	if (pQueue == NULL) {
		return FAILURE;
	}

	temp = (Array*)malloc(sizeof(Array));

	if (temp == NULL) {
		printf("Failure to allocate\n");

		return FAILURE;
	}

	temp->priority = priority_priority;

	temp->number = data_item;


	if (pQueue->size > pQueue->capacity ) {
		TempArray = (Array **)malloc(sizeof(Array*) * pQueue->capacity * 2);

		if (TempArray == NULL) 	{
			printf("Failure to allocate\n");
			return FAILURE;
		}

		while( i < pQueue->size) {
			TempArray[i] = pQueue->arr[i];
		}

		free(pQueue->arr);

		pQueue->arr = TempArray;
		pQueue->capacity = pQueue->capacity * 2;
	}

	if (pQueue->capacity > pQueue->size) {
		pQueue->arr[pQueue->size] = temp;
		pQueue->size++;
		fix_up(pQueue->arr, pQueue->size - 1);
	}

	return SUCCESS;
}


Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;

	if (pQueue == NULL) {
		return FAILURE;
	}

	if (pQueue->size > 0) {
		my_swap(&pQueue->arr[0], &pQueue->arr[pQueue->size - 1]);

		pQueue->size--;

		free(pQueue->arr[pQueue->size]);

		fix_down(pQueue->arr, 0, pQueue->size);
	}
	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
	Queue* pQueue = (Queue*)hQueue;

	if (priority_queue_is_empty(hQueue) && pStatus != NULL) {
		*pStatus = FAILURE;
		return -999;
	}

	if (pStatus != NULL) {
		*pStatus = SUCCESS;
	}

	return pQueue->arr[0]->number;

}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;

		if (pQueue->size <= 0) {
			return TRUE;
		}

		return FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
	Queue* pQueue = (Queue*)phQueue;

	int i = 0;

	while(i < pQueue->size) {

		free(pQueue->arr[i]);
		i++;
	}

	free(pQueue->arr);

	free(pQueue);

	*phQueue = NULL;
}

void fix_up(Array* heap[], int index)
{
	int ParentIndex = ParentIndex = ((index - 1) / 2);

	if (index > 0) {
		if (heap[index]->priority > heap[ParentIndex]->priority) {
			my_swap(&heap[index], &heap[ParentIndex]);
			fix_up(heap, ParentIndex);
		}
	}
}

void fix_down(Array* heap[], int index, int size)
{
	int LargestChildIndex,
	LeftChildIndex = (2 * index) + 1,
	RightChildIndex = (2 * index) + 2;


	if (RightChildIndex < size) {
		LargestChildIndex =
			(heap[LeftChildIndex]->priority > heap[RightChildIndex]->priority) ?
					LeftChildIndex : RightChildIndex;
		if (heap[index]->priority < heap[LargestChildIndex]->priority) {
			my_swap(&heap[index], &heap[LargestChildIndex]);
			fix_down(heap, LargestChildIndex, size);
		}
	}

	else if (LeftChildIndex < size) {
		LargestChildIndex = LeftChildIndex;
		if (heap[index]->priority < heap[LargestChildIndex]->priority) {
			my_swap(&heap[index], &heap[LargestChildIndex]);
			fix_down(heap, LargestChildIndex, size);
		}
	}
}

void my_swap(Array** one, Array** two) {
	Array* temp = *one;
	*one = *two;
	*two = temp;
}
