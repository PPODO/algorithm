#include<stdio.h>
#include<stdlib.h>
#include"List.h"

int main() {
	List list;
	LData Data;
	LInit(&list);

	for (int i = 0; i < 10; i++) {
		LInsert(&list, (i + 1));
	}

	if (LFirst(&list, &Data)) {
		printf("%d   ", Data);
		for (int i = 0; i < 19; i++) {
			if (LNext(&list, &Data)) {
				printf("%d   ", Data);
			}
		}
	}

	return 0;
}