#pragma once

typedef int DData;

typedef struct _Node {
	_Node* Next;
	_Node* Prev;
	DData Data;
}Node;

class Deque_ {
private:
	Node* Head;
	Node* Tail;
public:
	Deque_();
	bool DIsEmpty();
	void DQAddFirst(DData);
	void DQAddLast(DData);
	DData DQRemoveFirst();
	DData DQRemoveLast();
	DData DQGetFirst();
	DData DQGetLast();
};