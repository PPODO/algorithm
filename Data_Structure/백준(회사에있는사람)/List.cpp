#include<iostream>
#include<string>
#include<cstdlib>
#include"List.h"

Log_::Log_() {
	Head = new Node;
	Head->Next = Cur = Before = Tail = nullptr;
	Count = 0;
}

void Log_::LInsert(char* str, LData Data) {
	Node* NewNode = new Node;
	NewNode->Next = nullptr;
	NewNode->Data = Data;
	NewNode->Name = new char[strlen(str) + 1];
	strcpy(NewNode->Name, str);
	if (!Head->Next) {
		Head->Next = NewNode;
	}
	else {
		Tail->Next = NewNode;
	}
	Tail = NewNode;
	Count++;
}

bool Log_::NameSearch(char* str, LData Data){
	if (!Head) {
		return false;
	}
	Node* Temp = Head->Next;
	for (int i = 0; i < Count; i++) {
		if (!strcmp(Temp->Name, str)) {
			Temp->Data = Data;
			return true;
		}
		Temp = Temp->Next;
	}
	return false;
}

bool Log_::LFirst(char* str, LData* Data) {
	if (!Head->Next) {
		return false;
	}
	Cur = Head->Next;
	Before = Head;
	strcpy(str, Cur->Name);
	*Data = Cur->Data;
	return true;
}

bool Log_::LNext(char* str, LData* Data) {
	if (!Cur->Next) {
		return false;
	}
	Before = Cur;
	Cur = Cur->Next;
	strcpy(str, Cur->Name);
	*Data = Cur->Data;
	return true;
}

void Log_::LRemove() {
	Node* rpos = Cur;
	Before->Next = Cur->Next;
	Cur = Before;
	Count--;
	delete rpos->Name;
	delete rpos;
}

Log_::~Log_() {
	delete Head;
}