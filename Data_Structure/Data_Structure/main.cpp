#include<stdio.h>
#include<stdlib.h>
#include"List.h"

int main() {
	List list;
	LData Data;
	int Count = 0;
	LInit(&list);
	printf("�Է� ���� ������ ���� : ");
	scanf("%d", &Count);
	for (int i = 0; i < Count; i++) {
		printf("%d ��° ������ �Է� : ", (i + 1));
		scanf("%d", &Data);
		LInsert(&list, Data);
	}
	puts("");
	if (LFirst(&list, &Data)) {
		printf("%d  ", Data);
		while (LNext(&list, &Data)) {
			printf("%d  ", Data);
		}
	}
	puts("\n");
	Count = 0;
	if (LFirst(&list, &Data)) {
		Count++;
		printf("%d��° ��忡 ����� ������ %d ����\n", Count, LRemove(&list));
		while (LNext(&list, &Data)) {
			Count++;
			printf("%d��° ��忡 ����� ������ %d ����\n", Count, LRemove(&list));
		}
	}
	puts("");
	return 0;
}