// UP Pract.07 Matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_SIZE = 3;
constexpr int COLUMNS = 2;

//Task.1
int findMaxNumber(const int arr[][MAX_SIZE], int rows, int cols) {
    int max = arr[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }

    return max;
}

int findMinNumber(const int arr[][MAX_SIZE], int rows, int cols) {
    int min = arr[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (min > arr[i][j]) {
                min = arr[i][j];
            }
        }
    }

    return min; 
}

double findAverage(const int arr[][MAX_SIZE], int rows, int cols) {
    double totalSum = 0; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            totalSum += arr[i][j];
        }
    }

    return totalSum / (rows * cols);
}

//Task.2
bool hasNumber(const int arr[][MAX_SIZE], int rows, int cols, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (value == arr[i][j]) {
                return true;
            }
        }
    }

    return false;
}

//Task.3
void printDiagonals(const int arr[][MAX_SIZE], int rows, int cols) {
    if (rows != cols) {
        std::cout << "Error" << std::endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        std::cout << arr[i][i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < rows; i++) {
        std::cout << arr[i][cols - i - 1] << " ";
    }

    std::cout << std::endl;
}

//Task.4
bool isTriangular(const int arr[][MAX_SIZE], int rows, int cols) {
    if (rows != cols) {
        return false;
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

//Double check: upper AND lower triangular
bool triangular(const int arr[][MAX_SIZE], int rows, int cols) {
    if (rows != cols) {
        return false;
    }

    bool lower = true, upper = true;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < j && arr[i][j] != 0) {
                lower = false;
            }

            if (i > j && arr[i][j] != 0) {
                upper = false;
            }
        }
    }

    return lower || upper;
}

//Task.5
void printSpiral(const int matrix[][MAX_SIZE], int rows, int cols) {
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            std::cout << matrix[top][i] << " ";
        }

        top++;

        for (int i = top; i <= bottom; i++) {
            std::cout << matrix[i][right] << " ";
        }

        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                std::cout << matrix[bottom][i] << " ";
            }

            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                std::cout << matrix[i][left] << " "; 
            }

            left++;
        }
    }

    std::cout << std::endl;
}

//Task.6
int getSumBelowDiagonal(const int arr[][MAX_SIZE], int rows, int cols) {
    if (rows != cols) {
        return false;
    }

    int totalSum = 0;

    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            totalSum += arr[i][j];
        }
    }

    return totalSum; 
}

int getSumOnAndAboveDiagonal(const int arr[][MAX_SIZE], int rows, int cols) {
    if (rows != cols) {
        return false;
    }

    int totalSum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = i; j < cols; j++) {
            totalSum += arr[i][j];
        }
    }

    return totalSum;
}

//VERSION 2 
void getSumsAroundDiagonal(const int arr[][MAX_SIZE], int rows, int cols, int& sumOnAndAboveDiagonal, 
    int& sumBelowDiagonal)
{
    if (rows != cols) {
        std::cout << "Error" << std::endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i <= j) {
                sumOnAndAboveDiagonal += arr[i][j];
            }
            else {
                sumBelowDiagonal += arr[i][j];
            }
        }
    }

    std::cout << "Ready" << std::endl;
}

//Task.7
bool areDiagonalsAscending(const int arr[][MAX_SIZE], int M, int N) {
    if (M <= 0 || M >= 10 || N <= 0 || N >= 10) {
        std::cout << "Invalid parameters" << std::endl;
        return false;
    }

    //check by column
    for (int col = 0; col < N; col++) {
        int i = 0, j = col;
        while (i + 1 < M && j + 1 < N) {
            if (arr[i][j] >= arr[i + 1][j + 1]) {
                return false;
            }

            i++;
            j++;
        }
    }

    //check by row
    for (int row = 1; row < M; row++) {
        int i = row, j = 0;
        while (i + 1 < M && j + 1 < N) {
            if (arr[i][j] >= arr[i + 1][j + 1]) {
                return false;
            }

            i++;
            j++;
        }
    }

    return true;

}

//Task.8
int getSum(const int arr[][MAX_SIZE], int K, int s) {
    int totalSum = 0;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if ((i + j) == s) {
                totalSum += arr[i][j];
            }
        }
    }

    return totalSum;
}

//Task.9 
bool isSymmetric(const int arr[][MAX_SIZE], int rows, int cols) {
    if (rows != cols) { 
        std::cout << "Only square matrices can be symmetric" << std::endl;
        return false;
    }

    for (int i = 1; i < rows; i++) { 
        for (int j = 0; j < i; j++) { 
            if (arr[i][j] != arr[j][i]) { 
                return false;
            }
        }
    }

    return true;
}

//Task.10
void addMatrices(const int arr1[][MAX_SIZE], int rows1, int cols1, const int arr2[][MAX_SIZE], int rows2, int cols2,
    int result[][MAX_SIZE], int& resRows, int& resCols) { 
    if (rows1 != rows2 || cols1 != cols2) {
        std::cout << "Only matrices with the same dimensions can be added" << std::endl;
        return;
    }

    for (int i = 0; i < rows1; i++) { 
        for (int j = 0; j < cols1; j++) { 
            result[i][j] = arr1[i][j] + arr2[i][j]; 
        }
    }

    resRows = rows1; 
    resCols = cols1;
}

void multiplyMatrices(const int arr1[][MAX_SIZE], int rows1, int cols1, const int arr2[][MAX_SIZE], int rows2, 
    int cols2, int result[][MAX_SIZE], int& resRows, int& resCols) {
    if (cols1 != rows2) {
        std::cout << "Error" << std::endl;
        return;
    }

    for (int curRow = 0; curRow < rows1; curRow++) {
        for (int curCol = 0; curCol < cols2; curCol++) {
            int sum = 0;
            for (int i = 0; i < cols1; i++) {
                sum += (arr1[curRow][i] * arr2[i][curCol]);
            }

            result[curRow][curCol] = sum;
        }
    }

    resRows = rows1; 
    resCols = cols2; 
}

//Task.11
int getSubmatrixSum(const int matrix[][MAX_SIZE], int curRow, int curCol, int rows2, int cols2) {
    int current = 0;

    for (int i = curRow; i < curRow + rows2; i++) {
        for (int j = curCol; j < curCol + cols2; j++) {
            current += matrix[i][j];
        }
    }

    return current;
}

int maxSubmatrixSum(const int matrix[][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    int maxSum = INT_MIN;

    for (int curRow = 0; curRow <= rows1 - rows2; curRow++) {
        for (int curCol = 0; curCol <= cols1 - cols2; curCol++) {
            int current = getSubmatrixSum(matrix, curRow, curCol, rows2, cols2);

            if (maxSum < current) {
                maxSum = current;
            }
        }
    }

    return maxSum;
}

//SwapFunc
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapRows(int row1[], int cols1, int row2[], int cols2) {
    if (cols1 != cols2) {
        std::cout << "Only rows with the same dimensions can be swapped" << std::endl;
        return;
    }

    for (int i = 0; i < cols1; i++) {
        swap(row1[i], row2[i]);
    }
}

//Task.12
void sortMatrix(int matrix[][COLUMNS], int N) {
    for (int i = 0; i < N; i++) {
        int minRowIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (matrix[minRowIndex][0] > matrix[j][0]) {
                minRowIndex = j;
            }

            if (matrix[minRowIndex][0] == matrix[j][0] && matrix[minRowIndex][1] > matrix[j][1]) {
                minRowIndex = j;
            }
        }

        if (minRowIndex != i) {
            swapRows(matrix[minRowIndex], COLUMNS, matrix[i], COLUMNS); 
        }
   }
}

//PrintFunc
void print(const int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

int main()
{
    int arr1[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int arr2[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
    int result[MAX_SIZE][MAX_SIZE];
    int resRows = 0;
    int resCols = 0;
    multiplyMatrices(arr1, 3, 3, arr2, 3, 3, result, resRows, resCols);
    print(result, resRows, resCols);
    
    
    

}

