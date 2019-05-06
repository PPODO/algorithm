#include<iostream>

int LinearSearch(int[], int, int);

int main() {
	using namespace std;
	cout << "데이터 입력 개수 : ";
	int Count = 0;
	cin >> Count;
	int* Arr = new int[Count];
	cout << "데이터 입력 : ";
	for (int i = 0; i < Count; i++) {
		cin >> Arr[i];
	}
	cout << "배열 Arr[] : ";
	for (int i = 0; i < Count; i++) {
		cout << Arr[i] << "  ";
	}
	cout << endl << "찾고자 하는 데이터 : ";
	int Key = 0;
	cin >> Key;
	int Find = LinearSearch(Arr, Count, Key);

	if (Find > 0) {
		cout << "Arr[" << Find << "] = " << Arr[Find];
	}
	else {
		cout << "찾고자 하는 값이 없다.";
	}
	delete[] Arr;
	return 0;
}

int LinearSearch(int Arr[], int N, int Key) {
	for (int i = 0; i < N; i++) {
		if (Arr[i] == Key) {
			return i;
		}
	}
	return -1;
}