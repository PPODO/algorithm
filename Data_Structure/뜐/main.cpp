#include<iostream>
#include"Ma.h"

int main() {
	using namespace std;
	Ma_ Ma;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < (i == 4 ? SIZE - 1 : SIZE); j++) {
			Ma.NextInput(Ma.NextCheck());
		}
	}
	Ma.Print();

	return 0;
}