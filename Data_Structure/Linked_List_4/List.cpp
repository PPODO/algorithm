#include<stdlib.h>
#include"List.h"

LinkedList::LinkedList() {
	Tail = Cur = NULL;
}

void LinkedList::LInsert(LData Data) {
	Node* NewNode = new Node;
	NewNode->Data = Data;
	if (!Tail) {
		Tail = NewNode;
		Tail->Next = Tail->Prev = NewNode;
	}
	else {
		NewNode->Prev = Tail;
		Tail->Next->Prev = NewNode;
		Tail->Next = NewNode;
		NewNode->Next = Tail->Next;
		Tail = NewNode;
	}
}

bool LinkedList::LFirst(LData* Data) {
	if (!Tail) {
		return false;
	}
	Cur = Tail->Prev;
	*Data = Cur->Data;
	return true;
}

bool LinkedList::LNext(LData* Data) {
	if (!Cur->Next) {
		return false;
	}
	Cur = Cur->Next;
	*Data = Cur->Data;
	return true;
}

bool LinkedList::LBefore(LData* Data) {
	if (!Cur->Prev) {
		return false;
	}
	Cur = Cur->Prev;
	*Data = Cur->Data;
	return true;
}

LData LinkedList::LRemove() {
	Node* rpos = Cur;
	LData BData = rpos->Data;
	if (rpos == Tail) {
		if (Tail->Next == Tail) {
			Tail = NULL;
		}
		else {
			Tail = Cur->Prev;
		}
	}
	Cur->Prev->Next = Cur->Next;
	Cur->Next->Next = Cur->Prev;
	Cur = Cur->Prev;
	free(rpos);
	return BData;
}