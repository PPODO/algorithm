#include<iostream>
#include"Tree.h"

void ShowData(BTData);

int main() {
	BTreeNode* Tree1 = MakeBTreeNode();
	BTreeNode* Tree2 = MakeBTreeNode();
	BTreeNode* Tree3 = MakeBTreeNode();
	BTreeNode* Tree4 = MakeBTreeNode();
	BTreeNode* Tree5 = MakeBTreeNode();
	BTreeNode* Tree6 = MakeBTreeNode();

	SetData(Tree1, 1);
	SetData(Tree2, 2);
	SetData(Tree3, 3);
	SetData(Tree4, 4);
	SetData(Tree5, 5);
	SetData(Tree6, 6);

	MakeLeftSubTree(Tree1, Tree2);
	MakeRightSubTree(Tree1, Tree3);
	MakeLeftSubTree(Tree2, Tree4);
	MakeRightSubTree(Tree2, Tree5);
	MakeRightSubTree(Tree3, Tree6);

	PreorderTraverse(Tree1, ShowData);
	puts("");
	InorderTraverse(Tree1, ShowData);
	puts("");
	PostorderTraverse(Tree1, ShowData);
	puts("");

	DeleteTree(Tree1);

	return 0;
}

void ShowData(BTData Data) {
	std::cout << Data << ' ';
}