// Exam Last Year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int DIGITS = 10;
constexpr char DELIM = ',';

//Task.1
bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int charToDigit(char ch) {
    return ch - '0';
}

int analyzeArr(const char* str) {
    if (!str) {
        cout << "Invalid input data" << endl;
        return -1;
    }

    bool container[DIGITS] = { false };

    for (const char* ptr = str; *ptr; ptr++) {
        if (isDigit(*ptr)) {
            int index = charToDigit(*ptr);
            container[index] = true;
        }
    }

    for (int i = DIGITS - 1; i >= 0; i--) {
        if (!container[i]) {
            return i; 
        }
    }

    return -1;
}

//Task.2
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortArr(int* arr, size_t len) {
    if (!arr) return;

    for (int i = 0; i < len; i++) {
        int maxElement = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[maxElement] < arr[j]) {
                maxElement = j;
            }
        }

        if (maxElement != i) {
            swap(arr[maxElement], arr[i]);
        }
    }
}

int* copyArr(const int* arr, size_t len) {
    if (!arr) return nullptr;

    int* newArr = new int[len];
    for (int i = 0; i < len; i++) {
        newArr[i] = arr[i];
    }

    return newArr;
}

bool checkSubarr(const int arr[], size_t len) {
    if (!arr || len == 0) return false;

    for (int i = 0; i < len; i++) {
        if (arr[i] < len) {
            return false;
        }
    }

    return true;
}

int findIndex(const int arr[], size_t L) {
    if (!arr) {
        cout << "Invalid input data" << endl;
        return -1;
    }

    int* newArr = copyArr(arr, L);
    sortArr(newArr, L);

    for (int num = L; num > 0; num--) {
        if (checkSubarr(newArr, num)) {
            delete[] newArr;
            return num;
        }
    }

    delete[] newArr;
    return 0;

}

//Task.3
long absValue(long n) {
    return n < 0 ? -n : n;
}

int digitsCount(long n) {
    if (n == 0) return 1;

    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }

    return count;
}

char digitToChar(int n) {
    return n + '0';
}

void findMinDiff(const long arr[], size_t N, long& left, long& right) {
    if (!arr) return;

    long minDiff = LONG_MAX;

    for (size_t i = 0; i < N - 1; i++) {
        for (size_t j = i + 1; j < N; j++) {
            long curDiff = absValue(arr[i] - arr[j]);

            if (minDiff > curDiff) {
                minDiff = curDiff;

                left = arr[i];
                right = arr[j];
            }
        }
    }

    if (left < right) {
        swap(left, right);
    }
}

char* findDiff(const long arr[], size_t N) {
    if (!arr) return nullptr;

    long left = 0;
    long right = 0;

    findMinDiff(arr, N, left, right);

    int length = digitsCount(left) + digitsCount(right) + 2;
    char* nums = new char[length];

    int index = length - 2;
   
    while (right) {
        nums[index--] = digitToChar(right % 10);
        right /= 10;
    }

    nums[index--] = DELIM;
    
    while (left) {
        nums[index--] = digitToChar(left % 10);
        left /= 10;
    }

    nums[length - 1] = '\0';

    return nums;
}


int main()
{
    
    long arr[] = { 5, 6, 7, 3, 4, 1, 2, 9 };
    char* nums = findDiff(arr, 8);
    cout << nums << endl;
    delete[] nums;
}

