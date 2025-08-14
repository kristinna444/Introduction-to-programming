// UP Exam.02 Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int ROWS = 6;
constexpr int COLS = 6;
constexpr int CLOCK_ROWS = 3;
constexpr int CLOCK_COLS = 3;

void readMatrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> matrix[i][j];
        }
    }
}

int getClockSum(const int matrix[][COLS], int row, int col, int& cenRow, int& cenCol) {
    int sum = 0;
    cenRow = row + 1;
    cenCol = col + 1;

    for (int i = row; i < row + CLOCK_ROWS; i++) {
        for (int j = col; j < col + CLOCK_COLS; j++) {
            if (i == cenRow && j != cenCol) {
                continue;
            }

            sum += matrix[i][j];
        }
    }

    return sum;
}

void getMaxSum(const int matrix[][COLS], int& maxRow, int& maxCol, int& maxSum) {
    maxSum = INT_MIN;

    for (int i = 0; i <= CLOCK_ROWS; i++) {
        for (int j = 0; j <= CLOCK_COLS; j++) {
            int cenRow, cenCol;
            int sum = getClockSum(matrix, i, j, cenRow, cenCol); 

            if (maxSum < sum) {
                maxSum = sum;
                maxRow = cenRow;
                maxCol = cenCol; 
            }
        }
    }
}

int main()
{
    int matrix[ROWS][COLS];
    readMatrix(matrix);
    int maxSum, maxRow, maxCol;
    getMaxSum(matrix, maxRow, maxCol, maxSum);
    cout << "Row: " << maxRow << endl;
    cout << "Col: " << maxCol << endl;
    cout << "Max sum: " << maxSum << endl;
}

