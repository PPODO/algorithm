#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include"List.h"

int main() {
	int* Data = nullptr;
	int n = 0;
	printf("배열 개수 입력 : ");
	scanf("%d", &n);
	Data = (int*)calloc(n, sizeof(int));
	Print(Data, n);
	printf("데이터 입력(%d개) : ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &Data[i]);
	}
	Print(Data, n);
	puts("\n");
	printf("index 번호, 삽입할 수 : ");
	int in, num;
	scanf("%d %d", &in, &num);
	if (in > n) {
		printf("입력 불량 종료\n");
		free(Data);
		return -1;
	}
	printf("%d번째 요소에 %d 입력\n", in, num);
	Insert(Data, in, num, n);
	Print(Data, n);
	puts("\n");
	int delnum = 0;
	printf("삭제할 데이터 index : ");
	scanf("%d", &delnum);
	printf("%d번째 요소 삭제\n", delnum);
	Delete(Data, 1, n);
	Print(Data, n);
	puts("\n");
	int Key = 0;
	printf("찾으시는 값 입력 : ");
	scanf("%d", &Key);
	int index = Search(Data, Key, n);
	if (index >= 0 && index > n) {
		printf("%d번째 요소에서 찾음 \n", index + 1);
	}
	free(Data);
	return 0;
}