#include<iostream>
#include<Windows.h>

int Inter_Search(int arr[], int n, int key) {
	int left = 0, right = n - 1, middle = 0;
	while (left <= right) {
		middle = left + (right - left)*((key - arr[left]) / (arr[right] - arr[left]));
		if (arr[middle] < key) {
			left = middle + 1;
		}
		else if (arr[middle] > key) {
			right = middle - 1;
		}
		else if (arr[middle] == key) {
			return middle;
		}
	}
	return -1;
}

int Binary_Search(int arr[], int n, int key) {
	int left = 0, right = n - 1, middle = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		if (arr[middle] < key) {
			left = middle + 1;
		}
		else if (arr[middle] > key) {
			right = middle - 1;
		}
		else if (arr[middle] == key) {
			return middle;
		}
	}
	return -1;
}

int main() {
	int arr[] = { 1,3,5,7,9,10,12,15 };
	int Result = 0;
	Result = Inter_Search(arr, sizeof(arr) / sizeof(int), 10);
	if (Result != -1) {
		printf("%d", Result);
	}
	else {
		printf("¾÷½Â");
	}

	return 0;
}