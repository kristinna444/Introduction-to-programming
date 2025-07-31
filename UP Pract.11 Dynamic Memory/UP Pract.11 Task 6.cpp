// UP Pract.11 Task 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void readArray(int* arr, int length) {
    if (!arr) return;

    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

int* sortArr(const int* arr, int size, int elem) {
    if (!arr) return nullptr;

    int* result = new int[size];
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < elem) {
            result[index++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == elem) {
            result[index++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) { 
        if (arr[i] > elem && index < size) {  
            result[index++] = arr[i];  
        }
    }

    return result; 
}

void print(const int* arr, int size) {
    if (!arr) return;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int size;
    cin >> size;
    int elem; 
    cin >> elem;

    int* arr = new int[size];
    readArray(arr, size);

    int* result = sortArr(arr, size, elem);
    print(result, size);

    delete[] result;
    delete[] arr;
}

