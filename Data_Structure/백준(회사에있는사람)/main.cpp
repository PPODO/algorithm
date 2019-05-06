#include<iostream>
#include<string>
#include<cstdlib>
#include"List.h"

int main() {
	using namespace std;
	Log_ Log;
	char Name[50], State[20];
	int PNum = 0;
	cin >> PNum;
	cin.get();

	for (int i = 0; i < PNum; i++) {
		cin >> Name;
		cin >> State;
		if (!Log.NameSearch(Name, (!strcmp(State, "enter") ? 1 : 0))) {
			Log.LInsert(Name, (!strcmp(State, "enter") ? 1 : 0));
		}
	}
	cout << endl;
	if (Log.LFirst(Name, &PNum)) {
		if (PNum) {
			cout << Name << endl;
		}
		while (Log.LNext(Name, &PNum)) {
			if (PNum) {
				cout << Name << endl;
			}
		}
	}
	return true;
}