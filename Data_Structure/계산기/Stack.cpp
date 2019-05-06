#include<iostream>
#include<cstdlib>
#include"Stack.h"

StackList::StackList() {
	List = NULL;
}

bool StackList::SIsEmpty() {
	if (!List) {
		return true;
	}
	return false;
}

void StackList::SPush(SData Data) {
	Node* NewNode = new Node;
	NewNode->Data = Data;
	NewNode->Next = List;
	List = NewNode;
}

SData StackList::SPop() {
	Node* rpos = List;
	SData BData = rpos->Data;
	List = List->Next;
	delete rpos;
	return BData;
}

SData StackList::SPeek() {
	if (SIsEmpty()) {
		std::cout << "Stack Is Empty!";
		exit(-1);
	}
	return List->Data;
}