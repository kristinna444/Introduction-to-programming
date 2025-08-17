// Task 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Task.4
//this func swaps the whole triples
void swapTriples(int** arr, int i, int j) {
    for (int k = 0; k < 3; k++) {
        int temp = arr[k][i];
        arr[k][i] = arr[k][j];
        arr[k][j] = temp; 
    }
}

bool isGreater(int** arr, int i, int j) {
    if (arr[0][i] > arr[0][j]) {
        return true;
    }
    else if (arr[0][i] == arr[0][j] && arr[1][i] > arr[1][j]) {
        return true;
    }
    else if (arr[0][i] == arr[0][j] && arr[1][i] == arr[1][j] && arr[2][i] > arr[2][j]) { 
        return true;
    }

    return false;
}

//stable variant
void bubbleSort(int** arr, int cols) {
    int lastSwappedIndex = cols - 1;

    for (int i = 0; i < cols; i++) {
        int currentSwappedIndex = -1;
        for (int j = 0; j < lastSwappedIndex; j++) {
            if (isGreater(arr, j, j + 1)) {
                currentSwappedIndex = j; 
                swapTriples(arr, j, j + 1);
            }
        }

        if (currentSwappedIndex == -1) {
            return;
        }

        lastSwappedIndex = currentSwappedIndex;
    }
}

int** readMatrix(int rows, int cols) {
    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void printMatrix(const int* const * arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

void deleteMatrix(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i]; 
    }

    delete[] arr;
}

int main()
{
    int** matrix = readMatrix(3, 6);
    bubbleSort((int**)matrix, 6);
    printMatrix((const int* const*)matrix, 3, 6); 
    deleteMatrix(matrix, 3);
}

