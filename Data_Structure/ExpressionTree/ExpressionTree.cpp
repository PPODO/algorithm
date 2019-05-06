#include<iostream>
#include<cctype>
#include<cstring>
#include"ExpressionTree.h"
#include"Stack.h"

void ConvToRPNExp(char* exp, char** str) {
	_Stack_S Stack;
	int expLen = strlen(exp);
	int Index = 0, Count = 0, popOp = 0;
	char tok = 0;
	for (int i = 0; i < expLen; i++) {
		if (isdigit(exp[i])) {
			if (!isdigit(exp[i + 1])) {
				Count++;
			}
		}
	}
	char* convExp = new char[expLen + Count + 1];
	*str = new char[expLen + Count + 1];

	for (int i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(exp[i])) {
			convExp[Index++] = tok;
		}
		else {
			convExp[Index++] = ' ';
			switch (tok) {
			case '(':
				Stack.Push(tok);
				break;
			case ')':
				while (1) {
					popOp = Stack.Pop();
					if (popOp == '(') {
						break;
					}
					convExp[Index++] = popOp;
				}
				break;
			case '+':
			case '-':
			case '/':
			case '*':
				while (!Stack.IsEmpty() && WhoPrecOp(Stack.Peek(), tok) >= 0) {
					convExp[Index++] = Stack.Pop();
				}
				Stack.Push(tok);
				break;
			}
		}
	}
	convExp[Index++] = ' ';
	while (!Stack.IsEmpty()) {
		convExp[Index++] = Stack.Pop();
	}
	convExp[Index++] = '\0';
	strcpy(*str, convExp);
}

int GetOpPrec(char op) {
	switch (op) {
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	default:
		return 1;
	}
}

int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);
	if (op1Prec > op2Prec) {
		return 1;
	}
	else if (op1Prec < op2Prec) {
		return -1;
	}
	else {
		return 0;
	}
}

BTreeNode* MakeExpTree(char exp[]) {
	_Stack Stack;
	BTreeNode* pNode = nullptr;
	int expLen = strlen(exp);
	int Num = 0;
	for (int i = 0; i < expLen; i++) {
		if (exp[i] != ' ') {
			pNode = MakeTreeNode();
			if (isdigit(exp[i])) {
				if (isdigit(exp[i + 1])) {
					Num++;
				}
				else {
					int Value = 0;
					for (int k = i - Num; k <= i; k++) {
						int Sum = 1;
						for (int j = k; j < i; j++) {
							Sum *= 10;
						}
						Value += ((exp[k] - '0') * Sum);
					}
					SetData(pNode, Value, false);
					Stack.Push(pNode), Num = 0;
				}
			}
			else {
				MakeRightSubTree(pNode, Stack.Pop());
				MakeLeftSubTree(pNode, Stack.Pop());
				SetData(pNode, exp[i], true);
				Stack.Push(pNode);
			}
		}
	}
	return Stack.Pop();
}

int EvaluateExpTree(BTreeNode* pTree) {
	int op1, op2;
	if (!GetLeftSubTree(pTree) && !GetRightSubTree(pTree)) {
		return GetData(pTree);
	}
	op1 = EvaluateExpTree(GetLeftSubTree(pTree));
	op2 = EvaluateExpTree(GetRightSubTree(pTree));
	switch (GetData(pTree)) {
	case '+':
		return op1 + op2;
		break;
	case '-':
		return op1 - op2;
		break;
	case '*':
		return op1 * op2;
		break;
	case '/':
		return op1 / op2;
		break;
	}
	return 0;
}

void ShowNodeData(int Data, bool bNumOrStr) {
	if (bNumOrStr) {
		std::cout << char(Data);
	}
	else {
		std::cout << '(';
		std::cout << Data;
	}
}

void ShowPrefixTypeExp(BTreeNode* pTree) {
	PreorderTraverse(pTree, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* pTree) {
	InorderTraverse(pTree, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* pTree) {
	PostorderTraverse(pTree, ShowNodeData);
}