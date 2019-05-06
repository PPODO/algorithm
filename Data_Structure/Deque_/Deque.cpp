#include<iostream>
#include<cstdlib>
#include"Deque.h"

Deque_::Deque_() {
	Tail = Head = NULL;
}

bool Deque_::DIsEmpty() {
	if (!Head || !Tail) {
		return true;
	}
	return false;
}

void Deque_::DQAddFirst(DData Data) {
	Node* NewNode = new Node;
	NewNode->Next = NewNode->Prev = NULL;
	NewNode->Data = Data;
	if (!Head) {
		Head = Tail = NewNode;
	}
	else {
		NewNode->Next = Head;
		Head = Head->Prev = NewNode;
	}
}

void Deque_::DQAddLast(DData Data) {
	Node* NewNode = new Node;
	NewNode->Next = NewNode->Prev = NULL;
	NewNode->Data = Data;
	if (!Tail) {
		Head = Tail = NewNode;
	}
	else {
		NewNode->Prev = Tail;
		Tail = Tail->Next = NewNode;
	}
}

DData Deque_::DQRemoveFirst() {
	if (DIsEmpty()) {
		std::cout << "Deque is Empty!!!!\n";
		exit(-1);
	}
	Node* rpos = Head;
	DData BData = rpos->Data;
	if (Head == Tail) {
		Tail = Head = NULL;
	}
	else {
		Head->Next->Prev = NULL;
		Head = Head->Next;
	}
	delete rpos;
	return BData;
}

DData Deque_::DQRemoveLast() {
	if (DIsEmpty()) {
		std::cout << "Deque is Empty!!!!\n";
		exit(-1);
	}

	Node* rpos = Tail;
	DData BData = rpos->Data;
	if (Head == Tail) {
		Tail = Head = NULL;
	}
	else {
		Tail->Prev->Next = NULL;
		Tail = Tail->Prev;
	}
	delete rpos;
	return BData;
}

DData Deque_::DQGetFirst() {
	if (DIsEmpty()) {
		std::cout << "Deque is Empty!!!!\n";
		exit(-1);
	}
	return Head->Data;
}

DData Deque_::DQGetLast() {
	if (DIsEmpty()) {
		std::cout << "Deque is Empty!!!!\n";
		exit(-1);
	}
	return Tail->Data;
}