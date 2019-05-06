#include<stdlib.h>
#include<stdio.h>
#include"Tree.h"

Node* Create(TData Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (!NewNode) {
		return NULL;
	}
	NewNode->right = NewNode->left = NULL;
	NewNode->Data = Data;
	printf("%c 노드 생성\n", NewNode->Data);
	return NewNode;
}

void Postordet(Node* pNode) {
	if (pNode) {
		Preordert(pNode->left);
		Preordert(pNode->right);
		printf("%c", pNode->Data);
	}
}

void Delete(Node* pNode) {
	if (pNode) {
		if (pNode->left) {
			Delete(pNode->left);
		}
		if (pNode->right) {
			Delete(pNode->right);
		}
		printf("%c노드 삭제\n", pNode->Data);
		free(pNode);
	}
}

void Preordert(Node* pNode) {
	if (pNode) {
		printf("%c", pNode->Data);
		Preordert(pNode->left);
		Preordert(pNode->right);
	}
}

void Inordert(Node* pNode) {
	if (pNode) {
		Inordert(pNode->left);
		printf("%c", pNode->Data);
		Inordert(pNode->right);
	}
}

void Postordert(Node* pNode) {
	if (pNode) {
		Postordert(pNode->left);
		Postordert(pNode->right);
		printf("%c", pNode->Data);
	}
}