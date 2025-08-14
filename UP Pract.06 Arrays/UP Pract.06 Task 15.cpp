// UP Pract.06 Task 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_SIZE = 100;

int binarySearch(const int arr[], int length, int value) {
    int leftIndex = 0, rightIndex = length - 1;

    while (leftIndex <= rightIndex) {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if (arr[midIndex] == value) {
            return midIndex;
        }

        if (arr[midIndex] % 2 == 0) {
            leftIndex = midIndex + 1;
        }
        else {
            rightIndex = midIndex - 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    std::cin >> size;
    int arr[MAX_SIZE];

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int index = binarySearch(arr, size, 0);
    std::cout << index << std::endl;

    return 0;
}

