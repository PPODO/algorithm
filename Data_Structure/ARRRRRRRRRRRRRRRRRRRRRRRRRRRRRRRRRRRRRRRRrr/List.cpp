#include<stdio.h>
#include"List.h"

void Insert(int Data[], int index, int vaule, int n) {
	for (int i = n - 1; i > index; i--) {
		Data[i] = Data[i - 1];
	}
	Data[index] = vaule;
	false;
}

void Delete(int Data[], int index, int n) {
	for (int i = index - 1; i < n; i++) {
		Data[i] = Data[i + 1];
	}
	Data[n - 1] = 0;
}

int Search(int Data[], int vaule, int n) {
	for (int i = 0; i < n; i++) {
		if (Data[i] == vaule) {
			return i;
		}
	}
}

void Print(int Data[], int n) {
	printf("배열의 데이터 : ");
	for (int i = 0; i < n; i++) {
		printf("%3d ", Data[i]);
	}
	printf("\n");
}