#pragma once

typedef struct _Node{
	int Data;
	_Node* Left;
	_Node* Right;
}NODE;

class BINARYSEARCH {
public:
	BINARYSEARCH(NODE*);
	NODE* Insert(NODE*, int);
	NODE* Search(NODE*, int);
	void Delete(NODE*);
	void Print(NODE*);
};