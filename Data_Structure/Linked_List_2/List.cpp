#include<stdlib.h>
#include"List.h"

void LInit(List* plist) {
	plist->Tail = plist->Before = plist->Cur = NULL;
}

void LInsert(List* plist, LData Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = Data;
	if (!plist->Tail) {
		plist->Tail = NewNode;
		plist->Tail->Next = plist->Tail;
	}
	else {
		NewNode->Next = plist->Tail->Next;
		plist->Tail->Next = NewNode;
		plist->Tail = NewNode;
	}
}

bool LFirst(List* plist, LData* Data) {
	if (!plist->Tail) {
		return false;
	}
	plist->Cur = plist->Tail->Next;
	plist->Before = plist->Tail;
	*Data = plist->Cur->Data;
	return true;
}

bool LNext(List* plist, LData* Data) {
	if (!plist->Cur) {
		return false;
	}
	plist->Before = plist->Cur;
	plist->Cur = plist->Cur->Next;
	*Data = plist->Cur->Data;
	return true;
}

LData LRemove(List* plist) {
	Node* rpos = plist->Cur;
	LData BData = rpos->Data;
	plist->Before->Next = plist->Cur->Next;
	plist->Cur = plist->Before;
	free(rpos);
	return BData;
}

int LCount(List* plist) {
	return (plist->Count);
}