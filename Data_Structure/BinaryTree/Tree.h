#pragma once

typedef int BTData;

typedef struct _bTreeNode {
	BTData Data;
	_bTreeNode* Left;
	_bTreeNode* Right;
}BTreeNode;

BTreeNode* MakeBTreeNode();
BTData GetData(BTreeNode*);
void SetData(BTreeNode*, BTData);
BTreeNode* GetLeftSubTree(BTreeNode*);
BTreeNode* GetRightSubTree(BTreeNode*);
void MakeLeftSubTree(BTreeNode*, BTreeNode*);
void MakeRightSubTree(BTreeNode*, BTreeNode*);
void DeleteTree(BTreeNode*);


typedef void FunctionAction(BTData Data);
void PreorderTraverse(BTreeNode*, FunctionAction);
void InorderTraverse(BTreeNode*, FunctionAction);
void PostorderTraverse(BTreeNode*, FunctionAction);