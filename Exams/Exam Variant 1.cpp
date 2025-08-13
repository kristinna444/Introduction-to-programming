// Exam Variant 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int DIFFERENCE = 32;

//Task.1
double absoluteVal(double n) {
    return n < 0 ? -n : n;
}

double findAverage(const int* arr, size_t size) {
    if (!arr || size == 0) {
        cout << "Invalid input array!" << endl;
        return 0;
    }

    double sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

int findMaxMin(const int* arr, size_t size, int& minVal, int& maxVal) {
    if (!arr || size == 0) {
        cout << "Invalid input array!" << endl;
        return 0;
    }

    minVal = arr[0], maxVal = arr[0];

    double average = findAverage(arr, size);

    int closestToAverage = arr[0];
    double minDifference = absoluteVal(average - arr[0]); 

    for (size_t i = 1; i < size; i++) {
        if (minVal > arr[i]) { 
            minVal = arr[i];
        }

        if (maxVal < arr[i]) { 
            maxVal = arr[i]; 
        }

        double curDifference = absoluteVal(average - arr[i]);

        if (minDifference > curDifference) {  
            minDifference = curDifference; 
            closestToAverage = arr[i];
        }
    }

    return closestToAverage;
}

//myStrLen
int myStrLen(const char* string) {
    if (!string) return 0;

    int count = 0;

    while (*string) {
        count++;
        string++;
    }

    return count;
}

//Task.2
bool isPalindrome(const char* str, int len, int i, int j) {
    if (!str) return false;

    if (i < 0 || i >= len || j < 0 || j >= len || i == j) { 
        return false; 
    }

    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (left == i || left == j) {
            left++;
            continue;
        }

        if (right == i || right == j) {
            right--;
            continue;
        }

        if (str[left] != str[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

bool checkStr(const char* str) {
    if (!str) return false;

    int len = myStrLen(str);

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            bool palindrome = isPalindrome(str, len, i, j);

            if (palindrome) {
                return true;
            }
        }
    }

    return false;
}

//Task.3
bool isLowerCase(char ch) {
    return 'a' <= ch && ch <= 'z';
}

bool isUpperCase(char ch) {
    return 'A' <= ch && ch <= 'Z';
}

bool isLetter(char ch) {
    return isLowerCase(ch) || isUpperCase(ch);
}

char lowerToUpper(char ch) {
    return isLowerCase(ch) ? ch - DIFFERENCE : ch;
}

int charToDigit(char ch) {
    if ('0' <= ch && ch <= '9') {
        return ch - '0';
    }

    if (isLetter(ch)) {
        ch = lowerToUpper(ch);
        return ch - 'A' + 10;
    }

    return 0;
}

int convert(const char* string, int k) {
    if (!string) {
        cout << "Invalid input string!" << endl;
        return 0;
    }

    if (k < 2 || k > 36) {
        cout << "Invalid input data!" << endl;
        return 0;
    }

    int length = myStrLen(string);

    int result = 0;
    int multiplier = 1;
    
    for (int i = length - 1; i >= 0; i--) {
        result += charToDigit(string[i]) * multiplier; 
        multiplier *= k;
    }

    return result; 
}


int main()
{
    cout << (checkStr("racecars") ? "yes" : "no") << endl;
}
