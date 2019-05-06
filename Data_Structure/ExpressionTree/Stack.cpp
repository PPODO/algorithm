#include<iostream>
#include"Stack.h"

_Stack::_Stack() {
	Head = nullptr;
}

bool _Stack::IsEmpty() {
	if (!Head) {
		return true;
	}
	return false;
}

void _Stack::Push(BTreeNode* Data) {
	Node* NewNode = new Node;
	NewNode->Data = Data, NewNode->Next = nullptr;
	if (Head) {
		NewNode->Next = Head;
	}
	Head = NewNode;
}

BTreeNode* _Stack::Pop() {
	if (IsEmpty()) {
		std::cout << "Stack is Empty!!";
		exit(-1);
	}
	Node* rpos = Head;
	BTreeNode* BData = rpos->Data;
	Head = Head->Next;
	delete rpos;
	return BData;
}

BTreeNode* _Stack::Peek() {
	if (IsEmpty()) {
		std::cout << "Stack is Empty!!";
		exit(-1);
	}
	return Head->Data;
}

_Stack::~_Stack() {
	Head = nullptr;
}

_Stack_S::_Stack_S() {
	Head = nullptr;
}

bool _Stack_S::IsEmpty() {
	if (!Head) {
		return true;
	}
	return false;
}

void _Stack_S::Push(SData Data) {
	NodeD* NewNode = new NodeD;
	NewNode->Data = Data, NewNode->Next = nullptr;
	if (Head) {
		NewNode->Next = Head;
	}
	Head = NewNode;
}

SData _Stack_S::Pop() {
	if (IsEmpty()) {
		std::cout << "Stack is Empty!!";
		exit(-1);
	}
	NodeD* rpos = Head;
	SData BData = rpos->Data;
	Head = Head->Next;
	return BData;
}

SData _Stack_S::Peek() {
	if (IsEmpty()) {
		std::cout << "Stack is Empty!!";
		exit(-1);
	}
	return Head->Data;
}

_Stack_S::~_Stack_S() {
	Head = nullptr;
}