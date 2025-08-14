// UP Pract.06 Task 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_SIZE = 100;

void merge(const int arr1[], int length1, const int arr2[], int length2, int result[], int& resultLength) {
    int i = 0, j = 0;

    while (i < length1 && j < length2) {
        if (arr1[i] > arr2[j]) {
            result[resultLength++] = arr2[j++];
        }
        else {
            result[resultLength++] = arr1[i++];
        }
    }

    while (i < length1) {
        result[resultLength++] = arr1[i++];
    }

    while (j < length2) {
        result[resultLength++] = arr2[j++];
    }
}

void print(const int arr[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    int arr1[4] = { 1, 5, 7, 8 };
    int arr2[3] = { 2, 3, 6 };
    int result[MAX_SIZE];

    int resultLength = 0; 

    merge(arr1, 4, arr2, 3, result, resultLength); 
    print(result, resultLength); 

    return 0;
}

