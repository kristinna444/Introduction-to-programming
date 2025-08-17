// BubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) { 
		bool swapped = false;

		for (size_t j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}

void optimizedBubbleSort(int* arr, size_t size) {
	size_t lastSwappedIndex = size - 1;

	for (size_t i = 0; i < size; i++) { 
		size_t currentSwappedIndex = -1; 

		for (size_t j = 0; j < lastSwappedIndex; j++) {
			if (arr[j] > arr[j + 1]) {
				currentSwappedIndex = j;
				swap(arr[j], arr[j + 1]);
			}
		}

		if (currentSwappedIndex == -1) {
			return;
		}

		lastSwappedIndex = currentSwappedIndex;
	}
}

int main()
{
	int arr[] = { 1, 23, 13, 9, 45, 18, 34 };
	bubbleSort(arr, 7);
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

