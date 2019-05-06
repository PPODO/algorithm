#include<stdlib.h>
#include"List.h"

LinkedList::LinkedList() {
	Head = (Node*)malloc(sizeof(Node));
	Tail = (Node*)malloc(sizeof(Node));
	Before = Cur = Head->Prev = Tail->Next = NULL;
	Head->Next = Tail;
	Tail->Prev = Head;
}

void LinkedList::LInsert(LData Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = Data;
	if (Head->Next == Tail) {
		Head->Next = NewNode;
		NewNode->Prev = Head;
		Tail->Prev = NewNode;
		NewNode->Next = Tail;
	}
	else {
		Tail->Prev->Next = NewNode;
		NewNode->Prev = Tail->Prev;
		Tail->Prev = NewNode;
		NewNode->Next = Tail;
	}
}

bool LinkedList::LFirst(LData* Data) {
	if (Head->Next == Tail) {
		return false;
	}
	Cur = Head->Next;
	Before = Head;
	*Data = Cur->Data;
	return true;
}

bool LinkedList::LNext(LData* Data) {
	if (Cur->Next == Tail) {
		return false;
	}
	Before = Cur;
	Cur = Cur->Next;
	*Data = Cur->Data;
	return true;
}

bool LinkedList::LBefore(LData* Data) {
	if (Cur->Prev == Head) {
		return false;
	}
	Before = Cur;
	Cur = Cur->Prev;
	*Data = Cur->Data;
	return true;
}

LData LinkedList::LRemove(){
	Node* rpos = Cur;
	LData BData = rpos->Data;
	Before->Next = Cur->Next;
	Cur->Next->Prev = Before;
	Cur = Before;
	free(rpos);
	return BData;
}