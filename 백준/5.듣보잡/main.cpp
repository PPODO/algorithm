#include <iostream>
#include <string>
#include <vector>

int main() {
	using namespace std;
	int DontSee, DontHear, Total = 0;
	cin >> DontHear >> DontSee;

	vector<string>str(DontHear);
	vector<string>str__(DontHear > DontSee ? DontSee : DontHear);
	string str_;

	while (getchar() != '\n');

	for (int i = 0; i < DontHear; i++) {
		getline(cin, str[i]);
	}

	for (int i = 0; i < DontSee; i++) {
		getline(cin, str_);
		for (int j = 0; j < DontHear; j++) {
			if (str[j] == str_) {
				str__[Total++] = str_;
				break;
			}
		}
	}

	cout << Total << endl;
	for (int i = 0; i < Total; i++) {
		cout << str__[i] << endl;
	}

	return 0;
}