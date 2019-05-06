#pragma once

typedef int LData;

typedef struct _node {
	LData Data;
	_node* Next;
}Node;

typedef struct {
	Node* Head;
	Node* Tail;
	Node* Cur;
	Node* Before;
	int Count;
}LinkedList;

typedef LinkedList List;

void LInit(List*);
void LInsert(List*, LData);

bool LFirst(List*, LData*);
bool LNext(List*, LData*);

LData LRemove(List*);
int LCount(List*);