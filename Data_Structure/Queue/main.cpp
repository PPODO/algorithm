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
		printf("입력할 데이터 수 : ");
		scanf("%d", &Count);
		for (int i = 0; i < Count; i++) {
			printf("%d 번째 데이터 입력 : ", (i + 1));
			scanf("%d", &Data);
			QAdd(&list, Data);
		}
		SPACEDELETE;
		puts("\n데이터를 더 입력하시려면 y를 눌러주세요");
		while (getchar() == 'y') {
			printf("입력할 데이터 수 : ");

			scanf("%d", &Count_2);
			for (int i = 0; i < Count_2; i++) {
				printf("%d 번째 데이터 입력 : ", ((i + 1) + Count));
				scanf("%d", &Data);
				QAdd(&list, Data);
			}
			Count += Count_2;
			puts("\n데이터를 더 입력하시려면 y를 눌러주세요");
			SPACEDELETE;
		}
		puts("\n");
		for (int i = 0; i < Count; i++) {
			printf("%d 번째 데이터 %d 출력 및 삭제\n", (i + 1), QDelete(&list));
		}
		puts("\n처음부터 다시 시작하시려면 y를 프로그램을 종료하시려면 아무키나 눌러주세요.");
		SPACEDELETE;
	} while (getchar() == 'y');

	return 0;
}