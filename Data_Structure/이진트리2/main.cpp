#include <iostream>
#include "BTHead.h"

void ShowData(BTNode* Node) {
	std::cout << Node->Data << '\t';
}

void DeleteData(BTNode* Node) {
	delete Node;
	Node = nullptr;
}

int main() {
	BTNode* bt1 = MakeNode();
	BTNode* bt2 = MakeNode();
	BTNode* bt3 = MakeNode();
	BTNode* bt4 = MakeNode();
	BTNode* bt5 = MakeNode();
	BTNode* bt6 = MakeNode();

	SetBTData(bt1, 1);
	SetBTData(bt2, 2);
	SetBTData(bt3, 3);
	SetBTData(bt4, 4);
	SetBTData(bt5, 5);
	SetBTData(bt6, 6);

	LinkLeftSubTree(bt1, bt2);
	LinkRightSubTree(bt1, bt3);
	LinkLeftSubTree(bt2, bt4);
	LinkRightSubTree(bt2, bt5);
	LinkRightSubTree(bt3, bt6);

	std::cout << "Preorder Traverse! : \t";
	PreorderTraverse(bt1, ShowData);
	std::cout << "\nInorder Traverse! : \t";
	InorderTraverse(bt1, ShowData);
	std::cout << "\nPostorder Traverse! : \t";
	PostorderTraverse(bt1, ShowData);
	std::cout << std::endl;

	PostorderTraverse(bt1, DeleteData);

	return 0;
}