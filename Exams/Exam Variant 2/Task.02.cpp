// Task 02 variant 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int charToDigit(char ch) {
    return ch - '0';
}

int charToNumber(const char* ptr) {
    if (!ptr) return 0;

    int result = 0;

    while (*ptr) {
        if (!isDigit(*ptr)) {
            cout << "The string must consist only of digits!" << endl;
            return 0;
        }

        result *= 10;
        result += charToDigit(*ptr);
        ptr++;
    }

    return result;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortArray(int* arr, int len) {
    if (!arr) return;

    for (int i = 0; i < len; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

int arrToNum(const int* arr, int len) {
    if (!arr) return -1;

    int result = 0;
    for (int i = 0; i < len; i++) {
        result *= 10;
        result += arr[i];
    }

    return result;
}

int handleUnique2(const int count[10]) {
    int pair = -1, single = -1;
    for (int i = 0; i < 10; i++) {
        if (count[i] == 2) {
            pair = i;
        }
        else if (count[i] == 1) {
            single = i;
        }
    }

    if (pair == 0) {
        return single * 1000 + single;
    }

    return pair * 101 + single * 10;
}

int handleUnique3(const int count[10]) {
    int num[3] = { 0 };
    int index = 0;

    for (int i = 0; i < 10 && index < 3; i++) {
        if (count[i]) {
            num[index++] = i;
        }
    }

    sortArray(num, 3);

    if (num[0] == 0) {
        swap(num[0], num[1]);
    }

    int result = arrToNum(num, 3);
    result = result * 10 + num[1];
    result = result * 10 + num[0];

    return result;
}

int findNumber(const char* str) {
    if (!str) return -1;

    if (!str[0] || !str[1] || !str[2] || str[3]) return -1;

    int count[10] = { 0 };

    for (const char* ptr = str; *ptr; ptr++) {
        if (!isDigit(*ptr)) {
            return -1;
        }

        int digit = charToDigit(*ptr);
        count[digit]++;
    }

    int unique = 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            unique++;
        }
    }

    if (unique == 1) {
        return charToNumber(str);
    }

    if (unique == 2) {
        return handleUnique2(count);
    }

    return handleUnique3(count);
}

int main()
{
    cout << findNumber("103") << endl;
}

