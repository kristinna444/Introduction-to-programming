// Popravka.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int LETTERS = 26;
constexpr int LEN = 2;
constexpr int YEAR_LEN = 4;

//Task.1
bool isLowercase(char ch) {
    return 'a' <= ch && ch <= 'z';
}

bool isUppercase(char ch) {
    return 'A' <= ch && ch <= 'Z';
}

bool analyzeArr(const char* str) {
    if (!str) return false;

    bool uppercase[LETTERS] = { false };
    bool lowercase[LETTERS] = { false };

    while (*str) {
        if (isUppercase(*str)) {
            int upperIndex = *str - 'A';
            uppercase[upperIndex] = true;
        }
        else if (isLowercase(*str)) {
            int lowerIndex = *str - 'a';
            lowercase[lowerIndex] = true;
        }

        str++;
    }

    for (int i = 0; i < LETTERS; i++) {
        if (uppercase[i]) {
            if (!lowercase[i]) {
                return false;
            }
        }
    }

    return true;
}

//Task.2
bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int charToDigit(char ch) {
    return ch - '0';
}

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }

    return 31;
}

bool isDateValid(int day, int month, int year) {
    if (month < 1 || month > 12) return false;
    return 1 <= day && day <= getDaysInMonth(month, year);
}

int deriveNumber(const char* str) {
    if (!str) return 0;

    int num = 0;

    while (*str != '-' && *str) {
        if (isDigit(*str)) {
            num *= 10;
            num += charToDigit(*str);
        }
        else {
            return 0;
        }

        str++;
    }

    return num;
}

bool validDate(const char* string) {
    if (!string) return false;
    if (string[2] != '-' || string[5] != '-') return false;

    int day = deriveNumber(string);

    string += LEN + 1;
    int month = deriveNumber(string);

    string += LEN + 1;
    int year = deriveNumber(string);

    return isDateValid(day, month, year);
}

//Task.3
long powerOf(int n, int power) {
    if (power == 0) return 1;

    long result = 1;

    while (power) {
        result *= n;
        power--;
    }

    return result;
}

int findDigitsNum(long N) {
    if (N == 0) return 1;

    int count = 0;

    while (N) {
        count++;
        N /= 10;
    }

    return count;
}

int Find(long N, int n) {
    if (n <= 0 || n >= 8 || N < 0) {
        cout << "Invalid input data!" << endl;
        return -1;
    }

    if (n > findDigitsNum(N)) {
        cout << "n is bigger than the number of digits!" << endl;
        return -1;
    }

    long divisor = powerOf(10, n);
    long limit = powerOf(10, n - 1);

    int max = -1;

    while (N >= limit) {
        int k = N % divisor;

        if (max < k) {
            max = k;
        }

        N /= 10;
    }

    return max;
}

int main()
{
    cout << (validDate("29-02-2024") ? "yes" : "no") << endl;
}
