#pragma once

typedef int LData;

typedef struct _node {
	_node* Next;
	_node* Prev;
	LData Data;
}Node;

class LinkedList {
private:
	Node* Tail;
	Node* Cur;
public:
	LinkedList();
	void LInsert(LData);
	bool LFirst(LData*);
	bool LNext(LData*);
	bool LBefore(LData*);
	LData LRemove();
};

typedef LinkedList List;