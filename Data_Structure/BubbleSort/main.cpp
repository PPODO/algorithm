#include<iostream>

class Merge_ {
private:
	void MergeTwoArea(int[], int, int, int);
public:
	void MergeSort(int[], int, int);
};

void Merge_::MergeSort(int arr[], int left, int right) {
	int mid = 0;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

void Merge_::MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int sIdx = left;
	int* sortArr = new int[right + 1];
	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx]) {
			sortArr[sIdx] = arr[fIdx++];
		}
		else {
			sortArr[sIdx] = arr[rIdx++];
		}
		sIdx++;
	}
	if (fIdx > mid) {
		for (int i = rIdx; i <= right; i++, sIdx++) {
			sortArr[sIdx] = arr[i];
		}
	}
	else {
		for (int i = fIdx; i <= mid; i++, sIdx++) {
			sortArr[sIdx] = arr[i];
		}
	}
	std::cout << std::endl << std::endl;
	for (int i = left; i <= right; i++) {
		arr[i] = sortArr[i];
		std::cout << sortArr[i] << ' ';
	}
	std::cout << std::endl << std::endl;
	free(sortArr);
}

class Sort_ : public Merge_ {
private:
	int DataSave;
public:
	Sort_();
	void BubbleSort(int[], int);
	void SelectionSort(int[], int);
	void InsertionSort(int[], int);
	void Print(int[], int);
};

Sort_::Sort_() {
	DataSave = 0;
}

void Sort_::BubbleSort(int arr[], int Len) {
	for (int i = 0; i < (Len - 1); i++) {
		for (int j = 0; j < (Len - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				int Temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = Temp;
			}
		}
	}
}

void Sort_::SelectionSort(int arr[], int Len) {
	for (int i = 0; i < Len; i++) {
		DataSave = i;
		for (int j = 1; j < Len; j++) {
			if (arr[j] < arr[DataSave]) {
				DataSave = j;
			}
		}
		int Temp = arr[DataSave];
		arr[DataSave] = arr[i];
		arr[i] = Temp;
	}
}

void Sort_::InsertionSort(int arr[], int Len) {
	int j = 0;
	for (int i = 1; i < Len; i++) {
		DataSave = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > DataSave) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = DataSave;
	}
}

void Sort_::Print(int arr[], int Len) {
	for (int i = 0; i < Len; i++) { 
		std::cout << arr[i] << ' ';
	}
}

int main() {
	using namespace std;
	Sort_ Sort;
	int Count = 0;
	cout << "입력할 수의 개수를 입력해 주세요 : ";
	cin >> Count;
		 
	int* arr = new int[Count];
	cout << "수를 입력해 주세요 : ";
	for (int i = 0; i < Count; i++) {
		cin >> arr[i];
	}
	Sort.MergeSort(arr, 0, Count - 1);
	Sort.Print(arr, Count);

	return 0;
}