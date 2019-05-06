#include<stdio.h>
#include<stdlib.h>
#include"List.h"

int main() {
	List list;
	LData Data;
	int Count = 0;
	LInit(&list);
	printf("입력 받을 데이터 개수 : ");
	scanf("%d", &Count);
	for (int i = 0; i < Count; i++) {
		printf("%d 번째 데이터 입력 : ", (i + 1));
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
		printf("%d번째 노드에 저장된 데이터 %d 삭제\n", Count, LRemove(&list));
		while (LNext(&list, &Data)) {
			Count++;
			printf("%d번째 노드에 저장된 데이터 %d 삭제\n", Count, LRemove(&list));
		}
	}
	puts("");
	return 0;
}