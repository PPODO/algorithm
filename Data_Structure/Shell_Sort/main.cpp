#include<iostream>

int Count;

void Shell_Sort(int a[],int n) {
	int Temp = 0, m = 0, j = 0;
	for (int t = n / 2; t > 0; t /= 2) {
		for (int i = t; i < n; i++) {
			Temp = a[i];
			for (j = i; j >= t; j -= t) {
				if (Temp < a[j - t]) {
					a[j] = a[j - t];
				}
				else {
					break;
				}
			}
			a[j] = Temp;
		}
		printf("Step : %d\t", ++m);
		for (int k = 0; k < n; k++) {
			printf("%d\t", a[k]);
		}
		printf("\n");
	}

}

void Swap(int* a, int* b) {
	int Temp = *a;
	*a = *b;
	*b = Temp;
}

void Quick_Sort(int a[], int left, int right) {
	int low = left - 1, high = right, pivot = a[right];
	if (left < right) {
		do {
			do { low++; } while (a[low] < pivot);
			do { high--; } while (a[high] > pivot && high > left);
			if (low < high) {
				Swap(&a[low], &a[high]);
			}
		} while (low < high);
		Swap(&a[right], &a[low]);
		Quick_Sort(a, left, low - 1);
		Quick_Sort(a, low + 1, right);
	}
}

int main() {
	using namespace std;
	int arr[] = { 2,5,8,1,9,7,3 };
	Count = sizeof(arr) / sizeof(int);
	Shell_Sort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("%d\t", arr[i]);
	}


	return 0;
}