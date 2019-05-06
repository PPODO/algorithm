#include<iostream>



class QuickSort_ {
public:
	QuickSort_();
	void Swap(int, int);
	int Partition(int, int);
	void Sort(int, int);
	void Print();
};

QuickSort_::QuickSort_() {

}

void QuickSort_::Print() {

}

void QuickSort_::Swap(int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int QuickSort_::Partition(int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot > arr[low]) {
			low++;
		}
		while (pivot < arr[high]) {
			high--;
		}
		if (low <= high) {
			Swap(low, high);
		}
	}
	Swap(left, high);
	return high;
}

void QuickSort_::Sort(int left, int right) {
	if (left <= right) {
		int pivot = Partition(left, right);
		Sort(left, pivot - 1);
		Sort(pivot + 1, right);
	}
}

int main() {
	QuickSort_ QuickSort;
	std::cout << "정렬 전 데이터 : ";
	QuickSort.Print();

	std::cout << "정렬 후 데이터 : ";
	QuickSort.Print();
	return 0;
}