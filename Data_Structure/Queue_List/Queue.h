#pragma once

typedef int QData;

typedef struct _node{
	_node* Next;
	QData Data;
}Node;

typedef struct {
	Node* Front;
	Node* Rear;
}QueueList;

typedef QueueList Queue;

void QInit(Queue*);
bool QIsEmpty(Queue*);

void EnQueue(Queue*, QData);
QData DeQueue(Queue*);
QData QPeek(Queue*);