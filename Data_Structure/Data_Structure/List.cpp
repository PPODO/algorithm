#include<stdlib.h>
#include"List.h"

void LInit(List* plist) {
	plist->Head = NULL;
	plist->Cur = plist->Tail = plist->Before = NULL;
}

void LInsert(List* plist, LData Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = Data;
	NewNode->Next = NULL;
	if (!plist->Head) {
		plist->Head = NewNode;
	}
	else {
		plist->Tail->Next = NewNode;
	}
	plist->Tail = NewNode;
}

bool LFirst(List* plist, LData* Data) {
	if (!plist->Head->Next) {
		return false;
	}
	plist->Cur = plist->Head->Next;
	plist->Before = plist->Head;
	*Data = plist->Cur->Data;
	return true;
}

bool LNext(List* plist, LData* Data) {
	if (!plist->Cur->Next) {
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