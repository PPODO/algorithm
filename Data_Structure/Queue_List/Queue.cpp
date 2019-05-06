#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

void QInit(Queue* pQueue) {
	pQueue->Rear = pQueue->Front = NULL;
}

bool QIsEmpty(Queue* pQueue) {
	if (!pQueue->Front) {
		return true;
	}
	return false;
}

void EnQueue(Queue* pQueue, QData Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Next = NULL;
	NewNode->Data = Data;
	if (QIsEmpty(pQueue)) {
		pQueue->Front = NewNode;
	}
	else {
		pQueue->Rear->Next = NewNode;
	}
	pQueue->Rear = NewNode;
}

QData DeQueue(Queue* pQueue) {
	Node* rpos = pQueue->Front;
	QData BData = rpos->Data;
	pQueue->Front = pQueue->Front->Next;
	free(rpos);
	return BData;
}

QData QPeek(Queue* pQueue) {
	if (QIsEmpty(pQueue)) {
		printf("Queue is Empty!");
		exit(-1);
	}
	return pQueue->Front->Data;
}