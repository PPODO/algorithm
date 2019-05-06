#pragma once

typedef int LData;

typedef struct _node {
	LData Data;
	_node* Next;
	_node* Prev;
}Node;

class LinkedList {
private:
	Node * Head;
	Node* Tail;
	Node* Cur;
	Node* Before;
public:
	LinkedList();
	void LInsert(LData);
	bool LFirst(LData*);
	bool LNext(LData*);
	bool LBefore(LData*);
	LData LRemove();
};

typedef LinkedList List;