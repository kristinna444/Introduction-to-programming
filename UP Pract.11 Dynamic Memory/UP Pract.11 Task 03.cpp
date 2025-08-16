// UP Pract.11 Task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void readArray(int* arr, int N) {
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int findResultSize(int N, int K) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (K & (1 << i)) {
            counter++;
        }
    }

    return counter;
}

void fillResult(const int* arr, int* result, int N, int K) {
    int index = 0;
    for (int i = 0; i < N; i++) {
        int positionsToLeft = N - i - 1;
        if (K & (1 << positionsToLeft)) {
            result[index++] = arr[i];
        }
    }
}
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
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

    int K;
    cin >> K;
    int resultSize = findResultSize(N, K);
    int* result = new int[resultSize];
    fillResult(arr, result, N, K); 
    printArray(result, resultSize);

    delete[] arr;
    delete[] result;
}

