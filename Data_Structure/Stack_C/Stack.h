#pragma once

typedef char SData;

typedef struct _node {
	_node* Next;
	SData Data;
}Node;

typedef struct {
	Node* Head;
}StackList;

typedef StackList Stack;

void SInit(Stack*);
void SPush(Stack*, SData);
SData SPop(Stack*);
SData SPeek(Stack*);
bool SIsEmpty(Stack*);