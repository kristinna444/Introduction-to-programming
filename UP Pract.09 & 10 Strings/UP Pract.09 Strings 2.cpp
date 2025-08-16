// UP Pract.09 Strings 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_SIZE = 50;
constexpr int DIFFERENCE = 32;
constexpr int NUM = 10;
constexpr int MAX_COLS = 1024;
constexpr int MAX_ROWS = 100;
constexpr char TERMINATOR = '\0';

//Task.14
void getDigitOccurences(const char* digits, char* result) {
    if (!digits || !result) return;

    int counter[NUM] = { 0 };

    while (*digits) {
        if ('0' <= *digits && *digits <= '9') {
            int currentDigit = *digits - '0';
            counter[currentDigit]++;
        }

        digits++;
    }

    for (int i = 0; i < 10; i++) {
        if (counter[i] > 0) {
            int count = counter[i];
            if (count >= 10) {
                *result = (count / 10) + '0';
                result++;
            }

            *result = (count % 10) + '0';
            result++;
            *result = 'x';
            result++;
            *result = i + '0';
            result++;
            *result = ',';
            //add counter for numbers if you want to erase ',' after last number
            result++;

        }
    }

    *result = '\0';
}

//Task.16
bool isLowerCase(char symbol) {
    return 'a' <= symbol && symbol <= 'z';
}

bool isUpperCase(char symbol) {
    return 'A' <= symbol && symbol <= 'Z';
}

bool isLetter(char symbol) {
    return isLowerCase(symbol) || isUpperCase(symbol);
}

char fromLowerToUpper(char symbol) {
    return symbol - DIFFERENCE;
}

char fromUpperToLower(char symbol) {
    return symbol + DIFFERENCE;
}

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp; 
}

void copyString(const char* string, char* result) {
    if (!string || !result) {
        return;
    }

    while (*string) {
        if (isUpperCase(*string)) {
            *result = fromUpperToLower(*string);
            result++;
        }
        else if (isLowerCase(*string)) {
            *result = *string;
            result++;
        }

        string++;
    }

    *result = '\0';
}

void sortCharacters(const char* string, char* result) {
    if (!string || !result) return;
    copyString(string, result);

    for (char* first = result; *first; first++) {
        char* minPointer = first;

        for (char* second = first + 1; *second; second++) {
            if (*minPointer > *second) {
                minPointer = second; 
            }
        }

        if (minPointer != first) {
            swap(*minPointer, *first);
        }
    }
}

//Task.17
void fillMatrix(const char* text, char matrix[MAX_ROWS][MAX_COLS]) {
    if (!text || !matrix) { 
        std::cout << "Error" << std::endl;
        return;
    }

    int word = 0;
    int symbol = 0;
    bool inWord = false;

    for (const char* ptr = text; *ptr; ptr++) {
        if (isLetter(*ptr)) {
            inWord = true;
            matrix[word][symbol++] = *ptr;
        }
        else {
            if (inWord) {
                matrix[word][symbol] = TERMINATOR;
                word++;
                symbol = 0;
            }

            inWord = false;
        }
    }

    matrix[word][symbol] = TERMINATOR;
}

void printMatrix(char matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS && matrix[i][0] != '\0'; i++) {
        std::cout << matrix[i] << std::endl;
    }
}

void initialize(char matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            matrix[i][j] = '\0';
        }
    }
}

int main()
{
    char matrix[MAX_ROWS][MAX_COLS];
    char text[] = "Hi my name is Nikola";

    initialize(matrix);
    fillMatrix(text, matrix);
    printMatrix(matrix);
}

