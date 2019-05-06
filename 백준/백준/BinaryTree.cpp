#include "BinaryTree.h"

BTNode * MakeBTNode(BTData Data) {
	BTNode* NewNode = new BTNode;
	NewNode->Left = NewNode->Right = nullptr;
	NewNode->Data = Data;
	return NewNode;
}

BTNode * GetLeftSubTree(BTNode* Node) {
	if (Node) {
		return Node->Left;
	}
	return nullptr;
}

BTNode * GetRightSubTree(BTNode* Node) {
	if (Node) {
		return Node->Right;
	}
	return nullptr;
}

void LinkLeftSubTree(BTNode* Root, BTNode* Sub) {
	if (Root->Left) {
		delete Root->Left;
	}
	Root->Left = Sub;
}

void LinkRightSubTree(BTNode* Root, BTNode* Sub) {
	if (Root->Right) {
		delete Root->Right;
	}
	Root->Right = Sub;
}

void PreorderTraverse(BTNode* Node) {
	if (Node) {

	}
	return;
}

void InorderTraverse(BTNode* Node) {
	if (Node) {

	}
	return;
}

void PostorderTraverse(BTNode* Node) {
	if (Node) {

	}
	return;
}