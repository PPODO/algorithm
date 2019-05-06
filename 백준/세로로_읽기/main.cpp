#include <iostream>
#include <cstring>

int main() {
	using namespace std;
	char str[5][16];
	memset(str, 0, 5 * 16);
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}

	int j = 0;
	for (int i = 0; i < strlen(str[j]); i++) {
		for (j = 0; j < 5; j++) {
			if (str[j][i]) {
				cout << str[j][i];
			}
		}
	}

	return 0;
}