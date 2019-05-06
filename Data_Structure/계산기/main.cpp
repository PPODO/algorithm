#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cctype>
#include"Stack.h"
#include"Convert.h"

int main() {
	using namespace std;
	char exp1[] = "90+5/5";
	char* str = NULL;
	Convert convert;

	convert.ConvToRPNExp(exp1, &str);
	printf("%s = %d", str, convert.EvalPRNExp(str));

	free(str);
	return 0;
}