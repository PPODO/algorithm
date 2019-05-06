#include<iostream>

int LinearSearch(int[], int, int);

int main() {
	using namespace std;
	cout << "������ �Է� ���� : ";
	int Count = 0;
	cin >> Count;
	int* Arr = new int[Count];
	cout << "������ �Է� : ";
	for (int i = 0; i < Count; i++) {
		cin >> Arr[i];
	}
	cout << "�迭 Arr[] : ";
	for (int i = 0; i < Count; i++) {
		cout << Arr[i] << "  ";
	}
	cout << endl << "ã���� �ϴ� ������ : ";
	int Key = 0;
	cin >> Key;
	int Find = LinearSearch(Arr, Count, Key);

	if (Find > 0) {
		cout << "Arr[" << Find << "] = " << Arr[Find];
	}
	else {
		cout << "ã���� �ϴ� ���� ����.";
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