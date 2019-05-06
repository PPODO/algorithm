#pragma once

typedef int BTData;

typedef struct _bTreeNode {
	BTData Data;
	_bTreeNode* Left;
	_bTreeNode* Right;
	bool NumOfStr;
}BTreeNode;

BTreeNode* MakeTreeNode();
BTreeNode* GetLeftSubTree(BTreeNode*);
BTreeNode* GetRightSubTree(BTreeNode*);
void MakeLeftSubTree(BTreeNode*, BTreeNode*);
void MakeRightSubTree(BTreeNode*, BTreeNode*);
BTData GetData(BTreeNode*);
void SetData(BTreeNode*, BTData, bool);
void DeleteTree(BTreeNode*);

typedef void Show(BTData, bool);
void PreorderTraverse(BTreeNode*, Show);
void InorderTraverse(BTreeNode*, Show);
void PostorderTraverse(BTreeNode*, Show);