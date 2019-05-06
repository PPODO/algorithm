#include<iostream>

void Shell_Sort(int a[], int n) {
	int i, j, k, m = 0, t;
	int temp;
	for (t = n / 2; t > 0; t /= 2) {
		for (i = t; i < n; i++) {
			temp = a[i];
			for (j = i; j >= t; j-=t) {
				if (temp < a[j - t]) {
					a[j] = a[j - t];
				}
				else {
					break;
				}
			}
			a[j] = temp;
		}
		printf("step %d : ", ++m);
		for (k = 0; k < n; k++) {
			printf("%d\t", a[k]);
		}
		printf("\n");
	}
}

int main() {
	int a[] = { 2,5,8,1,9,7,3,10 };
	int count = sizeof(a) / sizeof(int);

	printf("정렬 전 데이터 : ");
	for (int i = 0; i < count; i++) {
		printf("%d\t", a[i]);
	}
	puts("");
	Shell_Sort(a, count);
	printf("정렬 후 데이터 : ");
	for (int i = 0; i < count; i++) {
		printf("%d\t", a[i]);
	}
	puts("");

	return 0;
}