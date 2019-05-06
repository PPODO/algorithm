#include<iostream>

int Linear_Search(int a[], int Key, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == Key) {
			return i;
		}
	}
	return -1;
}

int Binary_Search(int a[], int n, int Key) {
	int left = 0, right = 0, middle = 0;
	right = n - 1;
	

		while (left <= right) {
		middle = (left + right) / 2;
		if (Key > a[middle]) {
			left = middle + 1;
		}
		else if (Key < a[middle]) {
			right = middle - 1;
		}
		else {
			return middle;
		}
	}
	return -1;
}

int FIBO(int n) {
	if (n <= 0) {
		return -1;
	}
	else if (n == 1 || n == 2) {
		return 1;
	}
	int f1 = 1, f2 = 1;
	int fibon = 0;

	for (int i = 2; i < n; i++) {
		fibon = f1 + f2;
		f1 = f2;
		f2 = fibon;
	}
	return fibon;
}

int Init(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	int f1 = 0;
	int f2 = 1;
	int i = 0;
	for (i = 1; f1 + f2 <= n; i++) {
		int temp = f2;
		f2 = f2 + f1;
		f1 = temp;
	}
	return i;
}

int Search(int a[], int n, int key) {
	int i = Init(n);
	int f1 = FIBO(i - 1);
	int f2 = FIBO(i - 2);
	int index = n - FIBO(i - 1) + 1;

	while (1) {
		if (key > a[index]) {
			if (f1 == 0) {
				return -1;
			}
			index = index + f2;
			f1 = f1 - f2;
			f2 = f2 - f1;
			continue;
		}
		if (key == a[index]) {
			return index;
		}
		if (key < a[index]) {
			if (f2 == 0) {
				return -1;
			}
			index = index - f2;
			int temp = f1 - f2;
			f1 = f2;
			f2 = temp;
		}
	}
}


int main() {
	int Key = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	std::cin >> Key;
	int Sum = Search(arr, sizeof(arr) / sizeof(int), Key);

	std::cout << std::endl << Sum << std::endl;

	return 0;
}