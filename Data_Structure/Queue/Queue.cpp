#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

void QInit(Queue* pQueue) {
	pQueue->Head = pQueue->Tail = NULL;
}

bool QIsEmpty(Queue* pQueue) {
	if(!pQueue->Head){
		return true;
	}
	return false;
}

void QAdd(Queue* pQueue, LData Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = Data;
	NewNode->Next = NULL;
	if (!pQueue->Head) {
		pQueue->Head = NewNode;
	}
	else {
		pQueue->Tail->Next = NewNode;
	}
	pQueue->Tail = NewNode;
}

LData QDelete(Queue* pQueue) {
	if (QIsEmpty(pQueue)) {
		puts("Queue is Empty!!");
		exit(-1);
	}
	Node* rpos = pQueue->Head;
	LData BData = rpos->Data;
	pQueue->Head = pQueue->Head->Next;
	free(rpos);
	return BData;
}