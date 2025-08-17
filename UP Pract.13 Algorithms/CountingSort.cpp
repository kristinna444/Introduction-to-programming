// UP Pract.13 Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void stableCountingSort(char* arr) {
	size_t length = strlen(arr);
	char* copy = new char[length];
	for (size_t i = 0; i < length; i++) {
		copy[i] = arr[i];
	}

	int counter[256] = { 0 };
	for(size_t i = 0; i < length; i++) {
		counter[arr[i]]++;
	}

	for (size_t i = 1; i < 256; i++) {
		counter[i] += counter[i - 1];
	}

	for (int i = length - 1; i >= 0; i--) {
		arr[counter[copy[i]] - 1] = copy[i];
		--counter[copy[i]];
	}

	delete[] copy;
}

void unstableCountingSort(char* arr) {
	size_t length = strlen(arr);

	int counter[256] = { 0 };

	for (size_t i = 0; i < length; i++) {
		counter[arr[i]]++;
	}

	size_t index = 0;
	for (int i = 0; i < 256; i++) {
		while (counter[i] != 0) {
			arr[index++] = i;
			counter[i]--;
		}
	}
}

int main()
{
	char arr[] = "ababababababa";
	stableCountingSort(arr);
	std::cout << arr << endl;
}

