#pragma once

#define QUE_LEN 100

typedef int QData;

typedef struct {
	int front;
	int rear;
	int QueArr[QUE_LEN];
}CQueue;

typedef CQueue Queue;

void QInit(Queue*);
bool QIsEmpty(Queue*);
int NextPosIndex(int);

void EnQueue(Queue*, QData);
QData DeQueue(Queue*);
QData QPeek(Queue*);