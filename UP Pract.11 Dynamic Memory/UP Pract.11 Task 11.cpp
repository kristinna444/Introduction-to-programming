// UP Pract.11 Task 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void readArray(int* arr, size_t length) {
    if (!arr) return;

    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

void insertAt(int*& arr, size_t& len, size_t index, int elem) {
    if (!arr) return;

    if (index > len) {
        return;
    }

    len++;
    int* result = new int[len];
    int resultIndex = 0;
    int oldArrIndex = 0;

    for (int i = 0; i < len; i++) {
        if (i == index) {
            result[resultIndex++] = elem;
            //jumps over a position in the new array filling it with "elem"
        }
        else {
            result[resultIndex++] = arr[oldArrIndex++];  
        } 
    }

    delete[] arr;
    arr = result;
}

void removeAt(int*& arr, size_t& len, size_t index) {
    if (!arr) return;

    if (index >= len) {
        return;
    }

    int* result = new int[len - 1];
    int resultIndex = 0;
    int oldArrIndex = 0;

    for (int i = 0; i < len; i++) {
        if (i == index) {
            oldArrIndex++;
            //jumps over a position in the old array
        }
        else {
            result[resultIndex++] = arr[oldArrIndex++];
        }
    }

    len--;
    delete[] arr;
    arr = result;
}

void printArray(const int* arr, int length) {
    if (!arr) return;

    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    size_t size;
    cin >> size;
    int* arr = new int[size];
    readArray(arr, size);
    insertAt(arr, size, 4, 123);
    printArray(arr, size);
    removeAt(arr, size, 1);
    printArray(arr, size);

    delete[] arr;
}

