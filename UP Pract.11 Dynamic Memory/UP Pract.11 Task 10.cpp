// UP Pract.11 Task 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void printMatrix(const int* const* matrix, int rows, int cols) {
    if (!matrix) return;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

//matrix - an array of pointers
//we need to REDIRECT THE POINTERS to CHANGE THE MATRIX

void deleteOddRows(int** matrix, int& rows, int cols) {
    if (!matrix) return;

    int indexToRewrite = 0;

    for (int i = 0; i < rows; i++) {
        int sumInRow = 0;
        for (int j = 0; j < cols; j++) {
            sumInRow += matrix[i][j];
        }

        if (sumInRow % 2 == 0) {
            if (indexToRewrite != i) {
                matrix[indexToRewrite] = matrix[i];
            }
            indexToRewrite++;
        }
        else {
            delete[] matrix[i];
        }
    }

    rows = indexToRewrite;
}

//"indexToRewrite" KEEPS TRACK of the rows with POSITIVE SUM
//"...ToRewrite" GOES UP with one AFTER EVERY "POSITIVE" ROW
//we reach a "negative" row -> the variable remembers the deleted row
//a MISMATCH occurs -> we move the next positive row to WHERE THE LAST NEGATIVE ROW WAS

int getSumInRow(const int* arr, int length) {
    if (!arr) return 0;

    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }

    return sum;
}

void swap(int*& arr1, int*& arr2) {
    int* temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}

void removeOddRows(int** matrix, int& rows, int cols) {
    if (!matrix) return;

    for (int i = 0; i < rows;) {
        int sum = getSumInRow(matrix[i], cols);

        if (sum % 2 != 0) {
            swap(matrix[i], matrix[rows - 1]);
            delete[] matrix[rows - 1];
            rows--;
        }
        else {
            i++;
        }
    }
}

//we SWAP CURRENT and LAST row
//we DELETE the new LAST row and update the number of rows
//since the current row has changed, the index doesn't go up as we have to check it again

void freeMatrix(int** matrix, int rows) {
    if (!matrix) return;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int** matrix = allocateMatrix(rows, cols);
    readMatrix(matrix, rows, cols);
    removeOddRows(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    freeMatrix(matrix, rows);

}

