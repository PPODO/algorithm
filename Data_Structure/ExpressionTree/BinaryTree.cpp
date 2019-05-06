#include<iostream>
#include"BinaryTree.h"

BTreeNode* MakeTreeNode() {
	BTreeNode* NewTree = new BTreeNode;
	NewTree->Left = NewTree->Right = nullptr;
	return NewTree;
}

BTreeNode* GetLeftSubTree(BTreeNode* pTree) {
	return pTree->Left;
}

BTreeNode* GetRightSubTree(BTreeNode* pTree) {
	return pTree->Right;
}

void MakeLeftSubTree(BTreeNode* mainTree, BTreeNode* subTree) {
	if (!mainTree->Left) {
		delete mainTree->Left;
	}
	mainTree->Left = subTree;
}

void MakeRightSubTree(BTreeNode* mainTree, BTreeNode* subTree) {
	if (!mainTree->Right) {
		delete mainTree->Right;
	}
	mainTree->Right = subTree;
}

BTData GetData(BTreeNode* pTree) {
	return pTree->Data;
}

void DeleteTree(BTreeNode* pTree) {
	if (!pTree) {
		return;
	}
	DeleteTree(pTree->Left);
	DeleteTree(pTree->Right);
	delete pTree;
	pTree = nullptr;
}

void SetData(BTreeNode* pTree, BTData Data, bool bTrue) {
	pTree->Data = Data;
	pTree->NumOfStr = bTrue;
}

void PreorderTraverse(BTreeNode* pTree, Show Action) {
	if (!pTree) {
		return;
	}
	Action(pTree->Data, pTree->NumOfStr);
	PreorderTraverse(pTree->Left, Action);
	PreorderTraverse(pTree->Right, Action);
}

void InorderTraverse(BTreeNode* pTree, Show Action) {
	if (!pTree) {
		return;
	}
	InorderTraverse(pTree->Left, Action);
	Action(pTree->Data, pTree->NumOfStr);
	InorderTraverse(pTree->Right, Action);
}

void PostorderTraverse(BTreeNode* pTree, Show Action) {
	if (!pTree) {
		return;
	}
	PostorderTraverse(pTree->Left, Action);
	PostorderTraverse(pTree->Right, Action);
	Action(pTree->Data, pTree->NumOfStr);
}