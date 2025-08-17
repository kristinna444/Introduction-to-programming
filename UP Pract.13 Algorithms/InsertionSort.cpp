// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void insertionSort(int* arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int currentElement = arr[i];
        int currentIndex = i - 1;

        while (currentIndex >= 0 && arr[currentIndex] > currentElement) {
            arr[currentIndex + 1] = arr[currentIndex];
            currentIndex--;
        }

        arr[currentIndex + 1] = currentElement;
    }
}

int main()
{
    int arr[] = { 1, 23, 13, 9, 45, 18, 34 };
    insertionSort(arr, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

