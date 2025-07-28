// UP Exam.03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_SIZE = 20;

int getMinElement(const int arr[], int length) {
    int minElement = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    return minElement;
}

int getSumOfMinElements(const int array[], int length1, int subarray[], int length2) {
    if (length2 > length1) {
        std::cout << "Invalid data!" << std::endl;
        return 0;
    }

    int sum = 0;

    for (int i = 0; i <= length1 - length2; i++) {
        for (int j = 0; j < length2; j++) {
            subarray[j] = array[i + j];
        }

        sum += getMinElement(subarray, length2);
    }

    return sum;
}

void readArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        std::cin >> arr[i];
    }
}

int main()
{
    int N, k;
    std::cin >> N >> k;

    int array[MAX_SIZE];
    readArray(array, N);

    int subarray[MAX_SIZE];
    std::cout << getSumOfMinElements(array, N, subarray, k) << std::endl;
}

