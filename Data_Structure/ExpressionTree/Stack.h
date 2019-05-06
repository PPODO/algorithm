#pragma once
#include"BinaryTree.h"

typedef int SData;

typedef struct _Node {
	BTreeNode* Data;
	_Node* Next;
}Node;

typedef struct _Node_Data{
	SData Data;
	_Node_Data* Next;
}NodeD;

class _Stack {
private:
	Node* Head;
public:
	_Stack();
	bool IsEmpty();
	void Push(BTreeNode*);
	BTreeNode* Pop();
	BTreeNode* Peek();
	~_Stack();
};

class _Stack_S {
private:
	NodeD* Head;
public:
	_Stack_S();
	bool IsEmpty();
	void Push(SData);
	SData Pop();
	SData Peek();
	~_Stack_S();
};