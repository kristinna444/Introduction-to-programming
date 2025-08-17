// Task 05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Task.05
int inversionsCount(const int* arr, int size) {
    if (!arr || size < 2) return 0;

    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    return count;
}

//BONUS:


int main()
{
    int arr[] = { 2, 25, 18, 13, 8, 24 };
    cout << inversionsCount(arr, 6) << endl;
}

