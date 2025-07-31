// UP Pract.11 Dynamic Memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Task.2
void readArray(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void reverse(int* arr, int N) {
	if (!arr) return;

	for (int i = 0; i < N / 2; i++) {
		swap(arr[i], arr[N - i - 1]);
	}
}

void print(const int* arr, int N) {
	if (!arr) return;

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int main()
{
	int N;
	cin >> N;

	int* arr = new int[N];
	readArray(arr, N);
	reverse(arr, N);
	print(arr, N);
	delete[] arr;
}


