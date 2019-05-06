#include<stdio.h>
#include<stdlib.h>
#include"List.h"

int main() {
	List list;
	LData Data = 0;

	list.LInsert(1);
	list.LInsert(2);
	list.LInsert(3);
	list.LInsert(4);
	list.LInsert(5);

	if (list.LFirst(&Data)) {
		printf("%d   ", Data);
		while (list.LNext(&Data)) {
			printf("%d   ", Data);
		}
		while (list.LBefore(&Data)) {
			printf("%d   ", Data);
		}
	}
	puts("\n\n");
	if (list.LFirst(&Data)) {
		printf("%d   ", list.LRemove());
		while (list.LNext(&Data)) {
			printf("%d   ", list.LRemove());
		}
	}
	puts("\n\n");
	if (list.LFirst(&Data)) {
		printf("%d   ", Data);
		while (list.LNext(&Data)) {
			printf("%d   ", Data);
		}
	}
	return 0;
}