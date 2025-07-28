// UP Pract.09 Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr char TERMINATE_SYMB = '\0';
constexpr int MAX_SIZE = 50;
constexpr int MULTIPLIER = 10;
constexpr int DIFFERENCE = 32;

//Task.1 
unsigned int myStrLen(const char* string) {
    if (!string) return 0;

    unsigned int counter = 0;
    while (*string != TERMINATE_SYMB) {
        counter++;
        string++;
    }

    return counter;
}

//Task.2
void myStrCpy(char* destination, const char* source) {
    if (!destination || !source) {
        return;
    }

    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = TERMINATE_SYMB;
}

//Task.3
void myStrCat(char* first, const char* second) {
    if (!first || !second) {
        return;
    }

    unsigned int length = myStrLen(first);
    first += length;
    myStrCpy(first, second); 
    
}

//Task.4
int myStrCmp(const char* first, const char* second) {
    if (!first || !second) {
        return -1;
    }

    while (*first && *first == *second) {
        first++;
        second++;
    }

    return *first - *second;
}

//'f' - 'c' > 0 => "abf" > "abc" 
//'c' - 'd' < 0 => "abc" < "abd"

//Task.5
bool isDigit(char a) {
    return '0' <= a && a <= '9';
}

unsigned int stringToNumber(const char* string) {
    if (!string) return 0;

    unsigned int number = 0;

    while (*string) {
        char curSymbol = *string; 

        if (!isDigit(curSymbol)) {
            return 0;
        }

        number *= MULTIPLIER;
        number += (curSymbol - '0');

        string++;
    }

    return number;
}

//Task.6
unsigned int getCharOccurencesCount(const char* string, char ch) {
    if (!string) return 0;

    unsigned int count = 0;

    while (*string) {
        if (*string == ch) {
            count++;
        }

        string++;
    }

    return count;
}

//Task.7
bool isPrefix(const char* expectedPrefix, const char* text) {
    if (!expectedPrefix || !text) {
        return false;
    }

    while (*expectedPrefix) {
        if (*expectedPrefix != *text) {
            return false;
        }

        text++;
        expectedPrefix++; 
    }

    return true; 
}

//Task.8
bool searchInText(const char* pattern, const char* text) {
    if (!pattern || !text) {
        return false;
    }

    while (*text) {
        if (isPrefix(pattern, text)) {
            return true;
        }

        text++;
    }

    return false;
}

//for every position in text: check if pattern is prefix of the remaining string

bool searchInText2(const char* pattern, const char* text) {
    if (!pattern || !text) {
        return false;
    }

    unsigned int textLength = myStrLen(text);
    unsigned int patternLength = myStrLen(pattern);

    while (patternLength <= textLength) {
        if (isPrefix(pattern, text)) {
            return true;
        }

        text++;
        textLength--;
    }

    return false;
}

//only difference is the length regulation

//Task.9
void swap(int*& ptr1, int*& ptr2) {
    int* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

//Task.10
int at(const int* arr, unsigned int index) {
    return *(arr + index);
}

//Task.11
bool isPalindrome(const char* string) {
    if (!string) return false;

    unsigned int length = myStrLen(string);
    const char* left = string;
    const char* right = string + length - 1;

    while (left < right) {
        if (*left != *right) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

//Task.12
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

void convertString(char* string) {
    if (!string) return;

    while (*string) {
        char currentSymbol = *string;

        if (isLowerCase(currentSymbol)) { 
            *string = fromLowerToUpper(currentSymbol);
        }

        if (isUpperCase(currentSymbol)) {
            *string = fromUpperToLower(currentSymbol);
        }

        string++;
    }
}

//Task.13
void insertSymbol(const char* text, char* result, char symbol, unsigned int idx) {
    unsigned int currentIndex = 0;

    unsigned int length = myStrLen(text);
    if (idx > length - 1) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    while (*text) {
        if (currentIndex == idx) {
            *result = symbol;
            result++;
        }
        *result = *text;
        text++;
        result++;

        currentIndex++;
    }

    *result = '\0';
}

//Task.15
unsigned int getWordsCount(const char* text) {
    if (!text) return 0;

    unsigned int wordsCount = 0;
    bool inWord = false; 

    while (*text) {
        if (isLetter(*text)) {
            if (!inWord) {
                inWord = true;
                wordsCount++;
            }
        }
        else {
            inWord = false;
        }

        text++;
    }

    return wordsCount;
}

int main()
{
    char text[] = "hello world!";
    char result[MAX_SIZE];
    
    std::cout << text << std::endl; 
}

