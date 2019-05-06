#define _CRT_NO_SECURE_WARNING

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Stack.h"

void ConvToRPNExp(char[]);
int GetOpPrec(char);
int WhoPrecOp(char, char);

int main() {
	char exp1[] = "1+2+3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s\n", exp1);
	printf("%s\n", exp2);
	printf("%s\n", exp3);

	return 0;
}

void ConvToRPNExp(char exp[]) {
	Stack list;
	int expLen = strlen(exp), index = 0;
	char tok = 0, popOp = 0;
	char* convExp = (char*)malloc(sizeof(char) * (expLen + 1));

	memset(convExp, 0, sizeof(char)*(expLen + 1));
	SInit(&list);

	for (int i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			convExp[index++] = tok;
		}
		else {
			switch (tok) {
			case '(':
				convExp[index++] = tok;
				break;
			case ')':
				while (1) {
					popOp = SPop(&list);
					if (popOp == '(') {
						break;
					}
					convExp[index++] = popOp;
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (!SIsEmpty(&list) && WhoPrecOp(SPeek(&list), tok) >= 0) {
					convExp[index++] = SPop(&list);
				}
				SPush(&list, tok);
				break;
			}
		}
		while (!SIsEmpty(&list)) {
			convExp[index++] = SPop(&list);
		}
		strcpy(exp, convExp);
		free(convExp);
	}
}

int GetOpPrec(char op) {
	switch (op) {
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
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