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

	printf("傈困 款青(Preorder) : ");
	Preordert(TNode);
	puts("");
	printf("吝困 款青(Inorder) : ");
	Inordert(TNode);
	puts("");
	printf("饶困 款青(Postorder) : ");
	Postordet(TNode);
	puts("");

	Delete(TNode);

	return 0;
}