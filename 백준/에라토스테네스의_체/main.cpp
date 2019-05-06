#include <iostream>
#include <climits>

int main() {
	using namespace std;
	int InputN, DeleteNum, DeleteCount = 0;
	cin >> InputN >> DeleteNum;
	int* arr = new int[InputN - 1];
	int SmallNum = 2, NextSmallNum = INT_MAX;
	bool bDont = true;

	for (int i = 0; i < InputN - 1; i++) {
		arr[i] = i + 2;
	}

	while (bDont) {
		for (int i = 0; i < InputN - 1; i++) {
			if ((arr[i] % SmallNum) == 0) {
				DeleteCount++;
				if (DeleteCount == DeleteNum) {
					DeleteNum = arr[i];
					bDont = false;
					break;
				}
				arr[i] = -1;
			}
			else {
				if (NextSmallNum > arr[i] && arr[i] != -1) {
					NextSmallNum = arr[i];
				}
			}
		}
		SmallNum = NextSmallNum;
		NextSmallNum = INT_MAX;
	}
	cout << DeleteNum << endl;

	delete[] arr;
	return 0;
}