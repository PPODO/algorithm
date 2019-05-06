#pragma once

typedef int LData;

typedef struct _node{
	LData Data;
	_node* Next;
}Node;

typedef struct {
	Node* Head;
}StackList;

typedef StackList Stack;

void SInit(Stack*);
void SPush(Stack*, LData);
LData SPop(Stack*);
LData SPeek(Stack*);
bool SIsEmpty(Stack*);