#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

void QInit(Queue* pQueue) {
	pQueue->rear = pQueue->front = 0;
}

bool QIsEmpty(Queue* pQueue) {
	if (pQueue->front == pQueue->rear) {
		return true;
	}
	return false;
}

int NextPosIndex(int pos) {
	if (QUE_LEN == pos + 1) {
		return 0;
	}
	return (pos + 1);
}

void EnQueue(Queue* pQueue, QData Data) {
	if (NextPosIndex(pQueue->rear) == pQueue->front) {
		printf("Queue is Full!!");
		exit(-1);
	}
	pQueue->rear = NextPosIndex(pQueue->rear);
	pQueue->QueArr[pQueue->rear] = Data;
}

QData DeQueue(Queue* pQueue) {
	if (QIsEmpty(pQueue)) {
		printf("Queue is Empty!!");
		exit(-1);
	}
	pQueue->front = NextPosIndex(pQueue->front);
	return pQueue->QueArr[pQueue->front];
}

QData QPeek(Queue* pQueue) {
	if (QIsEmpty(pQueue)) {
		printf("Queue is Empty!!");
		exit(-1);
	}
	return pQueue->QueArr[NextPosIndex(pQueue->front)];
}