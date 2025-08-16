// UP Pract.11 Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int* readArray(int length) {
    int* arr = new int[length];

    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    return arr;
}

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }

    int sqrtN = sqrt(num);

    for (int i = 2; i <= sqrtN; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool isPrime2(int num) {
    if (num == 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int getPrimeNumbers(const int* arr, int length) {
    if (!arr) return 0;

    int count = 0;

    for (int i = 0; i < length; i++) {
        if (isPrime(arr[i])) {
            count++;
        }
    }

    return count;
}

int* sortPrimeNumbers(const int* arr, int length, int& size) {
    if (!arr) return nullptr;

    size = getPrimeNumbers(arr, length);
    int* result = new int[size];

    int resultIndex = 0;

    for (int i = 0; i < length; i++) {
        if (isPrime(arr[i])) {
            result[resultIndex++] = arr[i];
        }
    }

    return result; 
}

void printArr(const int* arr, int length) {
    if (!arr) return;

    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int length;
    cin >> length;
    int* arr = readArray(length);

    int resultLength = 0;
    int* result = sortPrimeNumbers(arr, length, resultLength); 
    printArr(result, resultLength); 
    //the printing (and deleting) of the result can be done in sortPrimeNumbers

    delete[] result;
    delete[] arr;
}

