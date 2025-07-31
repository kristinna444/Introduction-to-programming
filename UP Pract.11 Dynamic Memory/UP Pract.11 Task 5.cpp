// UP Pract.11 Task 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    return matrix;
}

void readMatrix(int** matrix, int rows, int cols) {
    if (!matrix) return;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void freeMatrix(int** matrix, int rows) {
    if (!matrix) return;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix; 
}

int getNegativeNums(const int* arr, int size) {
    if (!arr) return 0;

    int counter = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            counter++;
        }
    }

    return counter;
}

void printArray(const int* arr, int size) {
    if (!arr) return;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl; 
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int** matrix = allocateMatrix(rows, cols);
    readMatrix(matrix, rows, cols);
    
    int* negativeNums = new int[rows];
    for (int i = 0; i < rows; i++) {
        negativeNums[i] = getNegativeNums(matrix[i], cols);
    }

    printArray(negativeNums, rows); 

    freeMatrix(matrix, rows);
    delete[] negativeNums;
 
}

