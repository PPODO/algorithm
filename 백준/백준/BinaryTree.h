#pragma once

typedef char BTData;

typedef struct _BTNode {
	BTData Data;
	_BTNode* Left;
	_BTNode* Right;
}BTNode;

BTNode* MakeBTNode(BTData);
void SetupBTData(BTNode*, BTData);

BTNode* GetLeftSubTree(BTNode*);
BTNode* GetRightSubTree(BTNode*);

void LinkLeftSubTree(BTNode*, BTNode*);
void LinkRightSubTree(BTNode*, BTNode*);