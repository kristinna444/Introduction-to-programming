// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Task.01
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortAsc(int* arr, int start, int end) {
    for (int i = start; i < end; i++) {
        int minIndex = i;
        for (int j = i + 1; j < end; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

void sortDesc(int* arr, int start, int end) {
    for (int i = start; i < end; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < end; j++) {
            if (arr[maxIndex] < arr[j]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            swap(arr[maxIndex], arr[i]);
        }
    }
}

void sortConcat(int* arr, int size) {
    int mid = size / 2;
    sortAsc(arr, 0, mid);
    sortDesc(arr, mid, size);
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = { 4, 1, 2, 8, 9, -4, 0, -6, 11, 3 };
    sortConcat(arr, 10);
    printArray(arr, 10);

}

