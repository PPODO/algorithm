#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"Queue.h"
#define SPACEDELETE while(getchar() != '\n');

int main() {
	Queue list;
	LData Data;
	int Count = 0, Count_2 = 0;
	QInit(&list);
	do {
		system("cls");
		printf("�Է��� ������ �� : ");
		scanf("%d", &Count);
		for (int i = 0; i < Count; i++) {
			printf("%d ��° ������ �Է� : ", (i + 1));
			scanf("%d", &Data);
			QAdd(&list, Data);
		}
		SPACEDELETE;
		puts("\n�����͸� �� �Է��Ͻ÷��� y�� �����ּ���");
		while (getchar() == 'y') {
			printf("�Է��� ������ �� : ");

			scanf("%d", &Count_2);
			for (int i = 0; i < Count_2; i++) {
				printf("%d ��° ������ �Է� : ", ((i + 1) + Count));
				scanf("%d", &Data);
				QAdd(&list, Data);
			}
			Count += Count_2;
			puts("\n�����͸� �� �Է��Ͻ÷��� y�� �����ּ���");
			SPACEDELETE;
		}
		puts("\n");
		for (int i = 0; i < Count; i++) {
			printf("%d ��° ������ %d ��� �� ����\n", (i + 1), QDelete(&list));
		}
		puts("\nó������ �ٽ� �����Ͻ÷��� y�� ���α׷��� �����Ͻ÷��� �ƹ�Ű�� �����ּ���.");
		SPACEDELETE;
	} while (getchar() == 'y');

	return 0;
}