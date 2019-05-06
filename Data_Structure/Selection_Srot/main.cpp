#include<iostream>

void Selection_Sort(int a[], int n) {
	int min = 0, index = 0;
	for (int i = 0; i < n - 1; i++) {
		min = a[i];
		index = i;
		for (int j = i + 1; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = min;
		std::cout << "Step : " << i << ' ';
		for (int k = 0; k < n; k++) {
			std::cout << a[k] << '\t';
		}
		std::cout << std::endl;
	}
}

int main() {
	using namespace std;
	int a[] = { 5,2,8,1,9,7,3,11,6 };

	for (int i = 0; i < 9; i++) {
		cout << a[i] << '\t';
	}
	cout << endl;
	Selection_Sort(a, 9);
	cout << "정렬 후 데이터\n";
	for (int i = 0; i < 9; i++) {
		cout << a[i] << '\t';
	}
	cout << endl << endl;
	return 0;
}