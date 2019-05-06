#include<iostream>
#include<cstdlib> 
#include"Deque.h"

int main() {
	using namespace std;
	Deque_ Deque;

	Deque.DQAddFirst(4);
	Deque.DQAddFirst(5);
	Deque.DQAddFirst(6);

	Deque.DQAddLast(3);
	Deque.DQAddLast(2);
	Deque.DQAddLast(1);

	while (!Deque.DIsEmpty()) {
		cout << Deque.DQRemoveLast() << "  ";
	}

	return 0;
}