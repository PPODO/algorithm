#pragma once

typedef int LData;

typedef struct _node {
	LData Data;
	_node* Next;
}Node;

typedef struct {
	Node* Head;
	Node* Tail;
}QueueList;

typedef QueueList Queue;

void QInit(Queue*);
bool QIsEmpty(Queue*);
void QAdd(Queue*, LData);
LData QDelete(Queue*);