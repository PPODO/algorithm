#include<iostream>
#include"Tree.h"

BTreeNode* MakeBTreeNode() {
	BTreeNode* NewNode = new BTreeNode;
	NewNode->Left = NewNode->Right = nullptr;
	return NewNode;
}

void MakeLeftSubTree(BTreeNode* mainTree, BTreeNode* subTree) {
	if (mainTree->Left) {
		delete mainTree->Left;
	}
	mainTree->Left = subTree;
}

void MakeRightSubTree(BTreeNode* mainTree, BTreeNode* subTree) {
	if (mainTree->Right) {
		delete mainTree->Right;
	}
	mainTree->Right
}

BTreeNode* GetLeftSubTree(BTreeNode* pTree) {
	return pTree->Left;
}

BTreeNode* GetRightSubTree(BTreeNode* pTree) {
	return pTree->Right;
}

BTData GetData(BTreeNode* pTree) {
	return pTree->Data;
}

void SetData(BTreeNode* pTree, BTData Data) {
	pTree->Data = Data;
}

void PreorderTraverse(BTreeNode* pTree, FunctionAction Action) {
	if (!pTree) {
		return;
	}
	Action(pTree->Data);
	PreorderTraverse(pTree->Left, Action);
	PreorderTraverse(pTree->Right, Action);
}

void InorderTraverse(BTreeNode* pTree, FunctionAction Action) {
	if (!pTree) {
		return;
	}
	InorderTraverse(pTree->Left, Action);
	Action(pTree->Data);
	InorderTraverse(pTree->Right, Action);
}

void PostorderTraverse(BTreeNode* pTree, FunctionAction Action) {
	if (!pTree) {
		return;
	}
	PostorderTraverse(pTree->Left, Action);
	PostorderTraverse(pTree->Right, Action);
	Action(pTree->Data);
}

void DeleteTree(BTreeNode* pTree) {
	if (!pTree) {
		return;
	}
	DeleteTree(pTree->Left);
	DeleteTree(pTree->Right);
	std::cout << "삭제 노드 : " << pTree->Data << '\n';
	delete pTree;
}