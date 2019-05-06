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

void SPush(Stack* pStack, LData Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = Data;
	NewNode->Next = pStack->Head;
	pStack->Head = NewNode;
}

LData SPop(Stack* pStack) {
	if (SIsEmpty(pStack)) {
		printf("Stack memory is empty!!");
		exit(-1);
	}
	Node* rpos = pStack->Head;
	LData BData = rpos->Data;
	pStack->Head = pStack->Head->Next;
	free(rpos);
	return BData;
}

LData SPeek(Stack* pStack) {
	if (SIsEmpty(pStack)) {
		printf("Stack memory is empty!!");
		exit(-1);
	}
	return pStack->Head->Data;
}