#include<iostream>

class QuickSort {
private:
	int* Arr;
	int Count;
public:
	QuickSort(int*, int);
	void Print();
	void Swap(int, int);
	int Partition(int, int);
	void Sort(int, int);
	~QuickSort();
};

class BinarySearch {
private:
	int* Arr;
	int Count;
public:
	BinarySearch(int*, int);
	int Search(int);
	~BinarySearch();
};

QuickSort::QuickSort(int* lpArr, int nCount) {
	Arr = lpArr;
	Count = nCount;
}

void QuickSort::Print() {
	std::cout << "데이터 출력 : ";
	for (int i = 0; i < Count; i++) {
		std::cout << Arr[i] << "   ";
	}
}

void QuickSort::Swap(int index1, int index2) {
	int Temp = Arr[index1];
	Arr[index1] = Arr[index2];
	Arr[index2] = Temp;
}

int QuickSort::Partition(int left, int right) {
	int pivot = Arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot > Arr[low]) {
			low++;
		}
		while (pivot < Arr[high]) {
			high--;
		}
		if (low <= high) {
			Swap(low, high);
		}
	}
	Swap(left, high);
	return high;
}

void QuickSort::Sort(int left, int right) {
	if (left <= right) {
		int pivot = Partition(left, right);
		Sort(left, pivot - 1);
		Sort(pivot + 1, right);
	}
}

QuickSort::~QuickSort() {
	Arr = nullptr;
	Count = 0;
}

BinarySearch::BinarySearch(int* lpArr, int nCount) {
	Arr = lpArr, Count = nCount;
}

int BinarySearch::Search(int Key) {
	int middle = 0, Left = 0;
	int Right = Count;
	while (Left <= Right) {
		middle = (Left + Right) / 2;
		if (Key == Arr[middle]) {
			return middle;
		}
		else if (Key > Arr[middle]) {
			Left = middle + 1;
		}
		else {
			Right = middle - 1;
		}
	}
	return -1;
}

BinarySearch::~BinarySearch() {
	Arr = nullptr;
}

int main() {
	using namespace std;
	int* arr, Count;
	cout << "데이터 수를 입력 : ";
	cin >> Count;
	arr = new int[Count];
	cout << "데이터 입력 : ";
	for (int i = 0; i < Count; i++) {
		cin >> arr[i];
	}
	QuickSort Sort(arr, Count);
	cout << "정렬 전 데이터\n";
	Sort.Print();
	Sort.Sort(0, Count - 1);
	cout << "\n정렬 후 데이터\n";
	Sort.Print();
	BinarySearch Search(arr, Count);
	int Key = 0;
	cout << "\n찾으시는 값을 입력 해 주세요 : ";
	cin >> Key;
	int N = Search.Search(Key);
	if (N < 0) {
		cout << "찾으시는 값이 없습니다.";
	}
	else {
		cout << "\n찾으시는 값은 배열 " << N << "번째에 있고, 값은 " << arr[N] << "입니다.\n";
	}
	return 0;
}