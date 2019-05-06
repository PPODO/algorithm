#include<iostream>

int BinarySearch(int[], int, int);

int main() {
	std::cout << "������ �Է� ���� : ";
	int Count = 0;
	std::cin >> Count;
	int* Arr = new int[Count];
	std::cout << "������ �Է�(������������) : ";
	for (int i = 0; i < Count; i++) {
		std::cin >> Arr[i];
	}
	std::cout << "�迭 : Arr[] : ";
	for (int i = 0; i < Count; i++) {
		std::cout << Arr[i] << "  ";
	}
	std::cout << std::endl << "ã���� �ϴ� ������ : ";
	int Key = 0;
	std::cin >> Key;
	int Found = BinarySearch(Arr, Count, Key);
	if (Found < 0) {
		std::cout << "ã���� �ϴ� ���� �����ϴ�.";
	}
	else {
		std::cout << "Arr[" << Found << "] = " << Arr[Found];
	}
	delete[] Arr;
	return 0;
}

int BinarySearch(int Arr[], int N, int Key) {
	int left = 0, right = 0, middle = 0;
	right = N - 1;
	while (left <= right) {
		middle = (left + right) / 2;
		if (Key > Arr[middle]) {
			left = middle + 1;
		}
		else if (Key < Arr[middle]) {
			right = middle - 1;
		}
		else {
			return middle;
		}
	}
	return -1;
}