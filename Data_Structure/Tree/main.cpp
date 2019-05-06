#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

int main() {
	Node* TNode = NULL;
	TNode = Create('A');
	TNode->left = Create('B');
	TNode->right = Create('C');
	TNode->left->left = Create('D');
	TNode->left->right = Create('E');
	TNode->right->left = Create('F');
	TNode->right->right = Create('G');
	TNode->left->right->left = Create('H');

	printf("���� ����(Preorder) : ");
	Preordert(TNode);
	puts("");
	printf("���� ����(Inorder) : ");
	Inordert(TNode);
	puts("");
	printf("���� ����(Postorder) : ");
	Postordet(TNode);
	puts("");

	Delete(TNode);

	return 0;
}