#include <iostream>

int main() {
	using namespace std;

	int A, B, C;
	cin >> A >> B >> C;
	char str[100];
	sprintf(str, "%d", A*B*C);
	int NumCount[10] = { 0, };

	for (int i = 0; i < strlen(str); i++) {
		int Index = str[i] - '0';
		NumCount[Index]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << NumCount[i] << endl;
	}

	return 0;
}