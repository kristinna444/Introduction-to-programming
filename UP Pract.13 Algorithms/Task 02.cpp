// UP Pract.13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Task.2
//STABLE
void sortLinear(int* arr, size_t size) {
	if (!arr) return;

	int* copy = new int[size];
	for (size_t i = 0; i < size; i++) {
		copy[i] = arr[i];
	}

	int counter[10] = { 0 };
	for (size_t i = 0; i < size; i++) {
		counter[arr[i]]++;
	}

	for (size_t i = 1; i < 10; i++) {
		counter[i] += counter[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		arr[counter[copy[i]] - 1] = copy[i];
		counter[copy[i]]--;
	}

	delete[] copy;
}

//UNSTABLE
void sortLinearUnstable(int* arr, size_t size) {
	int counter[10] = { 0 };

	for (size_t i = 0; i < size; i++) {
		counter[arr[i]]++;
	}

	size_t index = 0;
	for (size_t i = 0; i < 10; i++) {
		while (counter[i] != 0) {
			arr[index++] = i;
			counter[i]--;
		}
	}
}

void printArr(const int* arr, size_t size) {
	if (!arr) return;

	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int main()
{
	int arr[] = { 3, 9, 1, 5, 4, 8, 0 };
	sortLinearUnstable(arr, 7);
	printArr(arr, 7);
}

