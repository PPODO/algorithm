#pragma once

typedef int LData;

typedef struct _Node {
	_Node* Next;
	LData Data;
	char* Name;
}Node;

class Log_ {
private:
	Node * Head;
	Node* Tail;
	Node* Cur;
	Node* Before;
	int Count;
public:
	Log_();
	void LInsert(char*, LData);
	bool NameSearch(char*, LData);
	bool LFirst(char*, LData*);
	bool LNext(char*, LData*);
	void LRemove();
	~Log_();
};