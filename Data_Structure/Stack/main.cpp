#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"Stack.h"
#define SPACEDELETE while (getchar() != '\n');

int main() {
	Stack list;
	LData Data;
	int Count = 0, Count_2 = 0;

	do {
		system("cls");
		printf("�Է¹��� ������ ���� : ");
		scanf("%d", &Count);
		for (int i = 0; i < Count; i++) {
			printf("%d ��° ������ �Է� : ", (i + 1));
			scanf("%d", &Data);
			SPush(&list, Data);
		}
		SPACEDELETE;
		puts("�����͸� �� �Է��Ͻ÷��� y�� �����ּ���");
		while (getchar() == 'y') {
			printf("�Է¹��� ������ ���� : ");
			scanf("%d", &Count_2);
			for (int i = 0; i < Count_2; i++) {
				printf("%d ��° ������ �Է� : ", ((i + 1) + Count));
				scanf("%d", &Data);
				SPush(&list, Data);
			}
			Count += Count_2;
			puts("�����͸� �� �Է��Ͻ÷��� y�� �����ּ���");
			SPACEDELETE;
		}
		puts("\n");
		for (int i = Count; i > 0; i--) {
			printf("%d ��° ������ %d ��� �� ����\n", i, SPop(&list));
		}
		puts("\nó������ �ٽ� �����Ͻ÷��� y�� ���α׷��� �����Ͻ÷��� �ƹ�Ű�� �����ּ���.");
		SPACEDELETE;
	} while (getchar() == 'y');
	puts("\n���α׷��� �����մϴ�.");
	return 0;
}