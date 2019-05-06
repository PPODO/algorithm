#include<iostream>
#include<cstdlib>
#include<cctype>
#include"Convert.h"
#include"Stack.h"

Convert::Convert() {
	index = popOp = tok = expLen = 0;
}

void Convert::ConvToRPNExp(char* exp, char** str) {
	StackList list;
	int Count = 0;
	expLen = strlen(exp);
	for (int i = 0; i < expLen; i++) {
		if (isdigit(exp[i])) {
			if (!isdigit(exp[i + 1])) {
				Count++;
			}
		}
	}
	convExp = (char*)malloc(sizeof(char) * ((expLen + Count) + 1));
	*str = (char*)malloc(sizeof(char) * ((expLen + Count) + 1));

	memset(convExp, 0, sizeof(char) * ((expLen + Count) + 1));

	for (int i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			convExp[index++] = tok;
		}
		else {
			convExp[index++] = ' ';
			switch (tok) {
			case '(':
				list.SPush(tok);
				break;
			case ')':
				while (1) {
					popOp = list.SPop();
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
				while (!list.SIsEmpty() && WhoPrecOp(list.SPeek(), tok) >= 0) {
					convExp[index++] = list.SPop();
				}
				list.SPush(tok);
				break;
			}
		}
	}
	convExp[index++] = ' ';
	while (!list.SIsEmpty()) {
		convExp[index++] = list.SPop();
	}
	strcpy(*str, convExp);
}

int Convert::GetOpPrec(char op) {
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

int Convert::WhoPrecOp(char op1, char op2) {
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

int Convert::EvalPRNExp(const char exp[]) {
	StackList list;
	expLen = strlen(exp);
	tok = 0, popOp = 0;
	int op1 = 0, op2 = 0, Count = 0;

	for (int i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			if (isdigit(exp[i + 1])) {
				Count++;
			}
			else {
				int Value = 0, sum = 1;
				for (int j = Count; j > 0; j--) {
					int temp = (exp[i - j] - '0');
					for (int k = 0; k < j; k++) {
						sum *= 10;
					}
					sum *= temp;
					Value += sum;
					sum = 1;
				}
				Value += (exp[i] - '0');
				list.SPush(Value);
				Count = 0;
			}
		}
		else {
			if (tok != ' ') {
				op2 = list.SPop();
				op1 = list.SPop();
				switch (tok) {
				case '+':
					list.SPush(op1 + op2);
					break;
				case '-':
					list.SPush(op1 - op2);
					break;
				case '*':
					list.SPush(op1 * op2);
					break;
				case '/':
					list.SPush(op1 / op2);
					break;
				}
			}
		}
	}
	return list.SPop();
}

Convert::~Convert() {
	delete[] convExp;
}