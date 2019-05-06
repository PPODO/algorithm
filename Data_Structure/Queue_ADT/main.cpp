#include<stdio.h>
#include"Queue.h"

int main() {
	Queue queue;
	QInit(&queue);

	EnQueue(&queue, 1);
	EnQueue(&queue, 2);
	EnQueue(&queue, 3);
	EnQueue(&queue, 4);
	EnQueue(&queue, 5);

	while (!QIsEmpty(&queue)) {
		printf("%d  ", DeQueue(&queue));
	}

	return 0;
}