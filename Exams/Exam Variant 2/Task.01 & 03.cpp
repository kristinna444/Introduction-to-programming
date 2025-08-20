// Exam Variant 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 10;
constexpr int LEN = 3;

//Task.1
long getAbsValue(long num) {
    return num < 0 ? -num : num;
}

long powerOf(int num, int pow) {
    long multiplier = 1;

    while (pow) {
        multiplier *= num;
        pow--;
    }

    return multiplier;
}

int findNumOfDigits(long num) {
    if (num == 0) return 1;
    
    int count = 0;

    while (num) {
        count++;
        num /= 10;
    }

    return count; 
}

long concat(long a, long b, int len) {
    int multiplier = powerOf(10, len);
    return a * multiplier + b; 
}

long findNewNum(long num, int index) {
    if (index < 0 || index >= findNumOfDigits(num)) {
        return num;
    }

    long divisor = powerOf(10, index); 
    long remain = num % divisor;  
    
    divisor *= 10;
    num /= divisor; 

    return concat(num, remain, index); 
}

bool isMonotone(long num) {
    int right = num % 10;
    num /= 10;

    bool increases = true, decreases = true;

    while (num) {
        int left = num % 10;

        if (right < left) {
            increases = false;
        }

        if (right > left) {
            decreases = false;
        }

        right = left; 
        num /= 10;
    }

    return increases || decreases; 
}

bool checkNum(long num) {
    num = getAbsValue(num); 

    int digits = findNumOfDigits(num);
    if (digits <= 2) return true;

    for (int i = 0; i < digits; i++) {
        long newNum = findNewNum(num, i);

        if (isMonotone(newNum)) { 
            return true;
        }
    }

    return false;
}

//Task.3
int* spiralRead(const int** matrix, size_t rows, size_t cols) {
    if (!matrix || rows == 0 || cols == 0) {
        return nullptr;
    }

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    size_t len = rows * cols;
    int* arr = new int[len]; 
    int index = 0;  

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right && index < len; i++) {
            arr[index++] = matrix[bottom][i];
        }

        bottom--;

        for (int i = bottom; i >= top && index < len; i--) { 
            arr[index++] = matrix[i][right];
        }

        right--;

        if (top <= bottom) {
            for (int i = right; i >= left && index < len; i--) {
                arr[index++] = matrix[top][i];
            }

            top++;
        }

        if (left <= right) {
            for (int i = top; i <= bottom && index < len; i++) {
                arr[index++] = matrix[i][left];
            }

            left++;
        }
    }
     
    return arr;
}

//Helper functions
int** readMatrix(size_t rows, size_t cols) {
    if (rows == 0 || cols == 0) {
        return nullptr;
    }

    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void freeMatrix(int** matrix, size_t rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void printArr(const int* arr, size_t len) {
    if (!arr) return;

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

