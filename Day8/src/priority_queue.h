#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct array Array;

struct array {
	int priority;
	int number;
};
struct queue {
	Array** arr;
	int size;
	int capacity;
};
typedef struct queue Queue;

enum status {FAILURE, SUCCESS};
typedef enum status Status;

enum boolean {FALSE, TRUE};
typedef enum boolean Boolean;

typedef void* PRIORITY_QUEUE;

PRIORITY_QUEUE priority_queue_init_default(void);

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_priority, int data_item);

Status priority_queue_service(PRIORITY_QUEUE hQueue);

void priority_queue_destroy(PRIORITY_QUEUE* phQueue);

void my_swap(Array** one, Array** two);

void fix_up(Array* heap[], int index);

void fix_down(Array* heap[], int index, int size);

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus);

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue);


#endif
