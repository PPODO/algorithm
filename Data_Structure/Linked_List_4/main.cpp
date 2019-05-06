#include<iostream>
#include<cstdlib>
#include"List.h"

int main() {
	using namespace std;
	List list;
	LData Data = 0;

	list.LInsert(0);
	list.LInsert(1);
	list.LInsert(2);

	if (list.LFirst(&Data)) {
		cout << Data << "\t";
		for (int i = 0; i < 3; i++) {
			if (list.LNext(&Data)) {
				cout << Data << "\t";
			}
		}
	}

	return 0;
}