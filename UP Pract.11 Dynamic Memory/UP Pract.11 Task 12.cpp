// UP Pract.11 Task 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 50;
constexpr char CENSOR = '*';
constexpr char TERMINATE = '\0';

bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int getCensoredLength(const char* string) {
    if (!string) return 0;

    int count = 0;
    bool inSequence = false;

    while (*string) {
        if (isDigit(*string)) {
            if (!inSequence) {
                count++;
                inSequence = true;
            }
        }
        else {
            count++;
            inSequence = false;
        }
        
        string++;
    }

    return count;
}

char* censorNumbers(const char* string) {
    if (!string) {
        return nullptr;
    }

    int length = getCensoredLength(string);
    char* censored = new char[length + 1];

    bool inSequence = false;
    int index = 0;

    for (const char* ptr = string; *ptr; ptr++) {
        if (isDigit(*ptr)) {
            if (!inSequence) {
                censored[index++] = CENSOR;
                inSequence = true;
            }
        }
        else {
            censored[index++] = *ptr;
            inSequence = false;
        }
    }

    censored[index] = TERMINATE;

    return censored;
}

int main()
{
    char string[MAX_SIZE];
    cin.getline(string, MAX_SIZE);

    char* censored = censorNumbers(string);
    cout << censored << endl;

    delete[] censored;
}

