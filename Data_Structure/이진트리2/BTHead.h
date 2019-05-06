#pragma once

typedef int BTData;

typedef struct _BTNode {
	BTData Data;
	_BTNode* Left;
	_BTNode* Right;
}BTNode;

BTNode* MakeNode();
BTData GetBTData(BTNode*);
void SetBTData(BTNode*, BTData);

BTNode* GetLeftSubTree(BTNode*);
BTNode* GetRightSubTree(BTNode*);

void LinkLeftSubTree(BTNode*, BTNode*);
void LinkRightSubTree(BTNode*, BTNode*);

void InorderTraverse(BTNode*, void(*VisitFuncPtr)(BTNode*));
void PreorderTraverse(BTNode*, void(*VisitFuncPtr)(BTNode*));
void PostorderTraverse(BTNode*, void(*VisitFuncPtr)(BTNode*));