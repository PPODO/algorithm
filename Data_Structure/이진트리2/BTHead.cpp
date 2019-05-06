#include <iostream>
#include "BTHead.h"

BTNode* MakeNode() {
	BTNode* NewNode = new BTNode;
	NewNode->Left = NewNode->Right = nullptr;
	return NewNode;
}

BTData GetBTData(BTNode* Node) {
	return Node->Data;
}

void SetBTData(BTNode* Node, BTData Data) {
	Node->Data = Data;
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

void LinkLeftSubTree(BTNode* Root, BTNode* Node) {
	if (Root->Left) {
		delete Root->Left;
	}
	Root->Left = Node;
}

void LinkRightSubTree(BTNode* Root, BTNode* Node) {
	if (Root->Right) {
		delete Root->Right;
	}
	Root->Right = Node;
}

void PreorderTraverse(BTNode* Node, void(*VisitFuncPtr)(BTNode*)) {
	if (Node) {
		VisitFuncPtr(Node);
		PreorderTraverse(Node->Left, VisitFuncPtr);
		PreorderTraverse(Node->Right, VisitFuncPtr);
	}
	return;
}

void InorderTraverse(BTNode* Node , void(*VisitFuncPtr)(BTNode*)) {
	if (Node) {
		InorderTraverse(Node->Left, VisitFuncPtr);
		VisitFuncPtr(Node);
		InorderTraverse(Node->Right, VisitFuncPtr);
	}
	return;
}

void PostorderTraverse(BTNode* Node , void(*VisitFuncPtr)(BTNode*)) {
	if (Node) {
		PostorderTraverse(Node->Left, VisitFuncPtr);
		PostorderTraverse(Node->Right, VisitFuncPtr);
		VisitFuncPtr(Node);
	}
	return;
}