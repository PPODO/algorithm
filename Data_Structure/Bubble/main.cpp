#include<stdio.h>

int Bubble_Sort(int a[], int count) {
	int i = 0, flag = 0, temp = 0;
	for (i = 1; i < count; i++) {
		flag = 0;
		for (int j = 0; j < count - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		return 1;
	}
	printf("step : %d : ", i);
	for (int k = 0; k < count; k++) {
		printf("%d\t", a[k]);
	}
	printf("flag = %d\n", flag);
}

int main() {
	int arr[] = { 5,2,8,1,9,7 };

	printf("정렬 전 데이터 : ");
	for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
		printf("%d\t", arr[i]);
	}
	puts("");

	Bubble_Sort(arr, (sizeof(arr)/sizeof(int)));

	printf("정렬 후 데이터 : ");
	for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
		printf("%d\t", arr[i]);
	}
	puts("");

	return 0;
}