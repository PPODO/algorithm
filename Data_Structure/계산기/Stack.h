#pragma once

typedef int SData;

typedef struct _node {
	_node* Next;
	SData Data;
}Node;

class StackList {
private:
	Node* List;
public:
	StackList();
	void SPush(SData);
	SData SPop();
	SData SPeek();
	bool SIsEmpty();
};