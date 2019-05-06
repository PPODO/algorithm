#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include"List.h"

int main() {
	int* Data = nullptr;
	int n = 0;
	printf("�迭 ���� �Է� : ");
	scanf("%d", &n);
	Data = (int*)calloc(n, sizeof(int));
	Print(Data, n);
	printf("������ �Է�(%d��) : ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &Data[i]);
	}
	Print(Data, n);
	puts("\n");
	printf("index ��ȣ, ������ �� : ");
	int in, num;
	scanf("%d %d", &in, &num);
	if (in > n) {
		printf("�Է� �ҷ� ����\n");
		free(Data);
		return -1;
	}
	printf("%d��° ��ҿ� %d �Է�\n", in, num);
	Insert(Data, in, num, n);
	Print(Data, n);
	puts("\n");
	int delnum = 0;
	printf("������ ������ index : ");
	scanf("%d", &delnum);
	printf("%d��° ��� ����\n", delnum);
	Delete(Data, 1, n);
	Print(Data, n);
	puts("\n");
	int Key = 0;
	printf("ã���ô� �� �Է� : ");
	scanf("%d", &Key);
	int index = Search(Data, Key, n);
	if (index >= 0 && index > n) {
		printf("%d��° ��ҿ��� ã�� \n", index + 1);
	}
	free(Data);
	return 0;
}