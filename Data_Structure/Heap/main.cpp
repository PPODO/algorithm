#include<iostream>

void UpHeap(int);
void Insert(int);
void DownHeap();
int Delete();
void HeapSort(int[], int);

int a[10];
int n = 0;

int main() {
	using namespace std;
	int arr[] = { 15,2,8,11,9,7 };

	int count = sizeof(arr) / sizeof(int);

	printf("정렬 전 데이터 : ");
	
	for (int i = 0; i < count; i++) {
		printf("%d\t", arr[i]);
	}
	puts("");

	HeapSort(arr, count + 1);

	printf("정렬 후 데이터 : ");

	for (int i = count - 1; i >= 0; i--) {
		printf("%d\t", arr[i]);
	}
	puts("");
		

	return 0;
}

void UpHeap(int x) {
	int value = a[x];
	while (x > 1 && a[x / 2] < value) {
		a[x] = a[x / 2];
		x /= 2;
	}
	a[x] = value;
}

void Insert(int data) {
	a[++n] = data;
	UpHeap(n);
}

void DownHeap() {
	int value = a[1];
	int i = 1;
	while (i <= n / 2) {
		int j = i * 2;
		if (j + 1 <= n && a[j] < a[j + 1]) {
			j++;
		}
		if (value >= a[j]) {
			break;
		}
		a[i] = a[j];
		i = j;
	}
	a[i] = value;
}

int Delete() {
	int value = a[1];
	a[1] = a[n--];
	DownHeap();
	return value;

}

void HeapSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		Insert(a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		a[i] = Delete();
		printf("%d번째 삭제 = %5d\n", i + 1, a[i]);
	}
}