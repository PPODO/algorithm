#include<iostream>

void Insertion_Sort(int a[], int n) {
	int temp = 0, j = 0;
	for (int i = 0; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (temp >= a[j]) {
				break;
			}
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
		std::cout << "Step : " << (i + 1) << ' ';
		for (int k = 0; k <= i; k++) {
			std::cout << a[k] << '\t';
		}
		puts("");
	}
}

int main() {
	using namespace std;
	int a[] { 5, 2, 8, 1, 9, 7 };

	cout << "정렬 전 데이터 : ";
	for (int i = 0; i < 6; i++) {
		cout << a[i] << '\t';
	}
	puts("");
	Insertion_Sort(a, 6);
	cout << "정렬 후 데이터 : ";
	for (int i = 0; i < 6; i++) {
		cout << a[i] << '\t';
	}
	puts("\n");
	return 0;
}