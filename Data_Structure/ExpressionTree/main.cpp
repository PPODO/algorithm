#include<iostream>
#include"ExpressionTree.h"

int main() {
	using namespace std;
	char str[] = "10+22*7";
	char* exp;
	ConvToRPNExp(str, &exp);
	BTreeNode* Save = MakeExpTree(exp);
	int Sum = EvaluateExpTree(Save);
	ShowInfixTypeExp(Save);
	cout << endl << "°á°ú = " << Sum << endl;
	
	delete exp;
	return 0;
}