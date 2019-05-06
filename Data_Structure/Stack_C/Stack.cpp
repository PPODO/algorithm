#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

void SInit(Stack* pStack) {
	pStack->Head = NULL;
}

bool SIsEmpty(Stack* pStack) {
	if (!pStack->Head) {
		return true;
	}
	return false;
}

void SPush(Stack* pStack, SData Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Next = pStack->Head;
	NewNode->Data = Data;
	pStack->Head = NewNode;
}

SData SPop(Stack* pStack) {
	if (SIsEmpty(pStack)) {
		puts("Stack is Empty!");
		exit(-1);
	}
	Node* rpos = pStack->Head;
	SData BData = rpos->Data;
	pStack->Head = pStack->Head->Next;
	free(rpos);
	return BData;
}

SData SPeek(Stack* pStack) {
	if (SIsEmpty(pStack)) {
		puts("Stack is Empty!");
		exit(-1);
	}
	return (pStack->Head->Data);
}