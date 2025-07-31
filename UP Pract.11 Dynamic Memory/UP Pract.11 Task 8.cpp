// UP Pract.11 Task 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void reverseNum(size_t& num) {
	size_t result = 0;
	while (num) {
		result *= 10;
		result += (num % 10);
		num /= 10;
	}
	num = result;
}

int compareLex(size_t first, size_t second) {
	reverseNum(first);
	reverseNum(second);

	while (first && second) {
		if ((first % 10) < (second % 10)) {
			return -1;
		}
		else if ((first % 10) > (second % 10)) {
			return 1;
		}
		else {
			first /= 10;
			second /= 10;
		}
	}

	return first - second; 
}

void copyArr(const size_t* nums, size_t* sorted, size_t N) {
	if (!nums || !sorted) return;

	for (size_t i = 0; i < N; i++) {
		sorted[i] = nums[i];
	}

}

void swap(size_t& a, size_t& b) {
	size_t temp = a;
	a = b;
	b = temp;
}

size_t* sortLex(size_t* nums, size_t N) {
	if (!nums) {
		return nullptr;
	}

	size_t* sorted = new size_t[N];
	copyArr(nums, sorted, N);

	for (size_t i = 0; i < N; i++) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < N; j++) {
			if (compareLex(sorted[minIndex], sorted[j]) > 0) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			swap(sorted[minIndex], sorted[i]);
		}
	}

	return sorted;
}

size_t* readArr(size_t N) {
	size_t* arr = new size_t[N];
	for (size_t i = 0; i < N; i++) {
		cin >> arr[i];
	}
	return arr;
}

void printArr(const size_t* arr, size_t N) {
	if (!arr) return;

	for (size_t i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int main()
{
	size_t N;
	cin >> N;
	size_t* arr = readArr(N);
	size_t* sorted = sortLex(arr, N);
	printArr(sorted, N);

	delete[] arr;
	delete[] sorted; 
}

