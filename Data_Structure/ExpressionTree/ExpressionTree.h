#pragma once
#include"BinaryTree.h"

void ConvToRPNExp(char*, char**);
int GetOpPrec(char);
int WhoPrecOp(char, char);

BTreeNode* MakeExpTree(char[]);
int EvaluateExpTree(BTreeNode*);

void ShowPrefixTypeExp(BTreeNode*);
void ShowInfixTypeExp(BTreeNode*);
void ShowPostfixTypeExp(BTreeNode*);