// UP Pract.10 Strings Excercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_SIZE = 50;
constexpr int LETTER_NUM = 26;
constexpr int DIFFERENCE = 32;
constexpr char CENSOR_CHAR = '*';
constexpr char MINUS = '-';
constexpr int WORDS_NUM = 3;

unsigned int myStrLen(const char* string) {
    if (!string) return 0;

    unsigned int count = 0;

    while (*string) {
        count++;
        string++;
    }

    return count++;
}

bool isPrefix(const char* substring, const char* string) {
    if (!substring || !string) return false;

    while (*substring) {
        if (*substring != *string) {
            return false;
        }

        substring++;
        string++;
    }

    return true;
}

//Task.4
unsigned int getStringOccurences(const char* substring, const char* string) {
    if (!string || !substring) {
        std::cout << "Invalid data" << std::endl;
        return 0;
    }

    unsigned int count = 0;

    unsigned int stringLength = myStrLen(string);
    unsigned int substringLength = myStrLen(substring);

    while (substringLength <= stringLength) {
        if (isPrefix(substring, string)) {
            count++;
        }
        
        string++;
        stringLength--;
    }

    return count;
}

//Task.5
bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
} 

int charToDigit(char ch) {
    if (isDigit(ch)) {
        return ch - '0';
    }

    return 0;
}

int stringToNumber(const char* string, bool& validNumber) {
    if (!string) {
        std::cout << "Invalid string" << std::endl;
        return 0;
    }

    bool isNegative = false;

    if (*string == MINUS) {
        isNegative = true;
        string++;
    }

    int result = 0;

    while (*string) {
        if (!isDigit(*string)) {
            validNumber = false;
            return 0;
        }

        result *= 10;
        result += charToDigit(*string);
        string++;
    }

    return isNegative ? -result : result;
}

int integerCompare(const char* first, const char* second) {
    if (!first || !second) {
        std::cout << "Invalid data" << std::endl;
        return 0;
    }

    bool validNumbers = true;

    int firstNum = stringToNumber(first, validNumbers);
    int secondNum = stringToNumber(second, validNumbers);

    if (!validNumbers) {
        std::cout << "Invalid numbers" << std::endl;
        return 0;
    }

    if (firstNum != secondNum) {
        return (firstNum > secondNum) ? 1 : -1;
    }

    return 0;
}

//Task.6
void getSubstring(const char* string, int start, int end, char* result) {
    if (!string || !result) return;

    unsigned int stringLength = myStrLen(string);
    if (end > stringLength) {
        end = stringLength;
    }

    if (start >= end || start >= stringLength) { 
        *result = '\0';
        return;
    }

    for (const char* ptr = string + start; ptr < string + end; ptr++) {
        *result = *ptr;
        result++;
    }

    *result = '\0';
}

//Task.7
bool isUpperCase(char ch) {
    return 'A' <= ch && ch <= 'Z';
}

bool isLowerCase(char ch) {
    return 'a' <= ch && ch <= 'z';
}

bool isLetter(char ch) {
    return isLowerCase(ch) || isUpperCase(ch); 
}

char fromUpperToLower(char ch) {
    return isUpperCase(ch) ? ch + DIFFERENCE : ch; 
}

char fromLowerToUpper(char ch) {
    return isLowerCase(ch) ? ch - DIFFERENCE : ch;
}

bool containsDuplicate(const char* string) {
    if (!string) return false;

    bool container[LETTER_NUM] = { false };

    for (const char* ptr = string; *ptr; ptr++) {
        char curSymbol = *ptr;

        if (isLetter(curSymbol)) {
            curSymbol = fromUpperToLower(curSymbol);

            int index = curSymbol - 'a';

            if (container[index]) {
                return true;
            }

            container[index] = true;
        }
    }

    return false;
}

//Task.8
void copyString(const char* string, char* result) {
    if (!string || !result) return;

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

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void sortCharacters(const char* string, char* result) {
    if (!string || !result) return;

    copyString(string, result);

    for (char* ptr1 = result; *ptr1; ptr1++) {
        char* minIndex = ptr1;

        for (char* ptr2 = ptr1 + 1; *ptr2; ptr2++) {
            if (*minIndex > *ptr2) {
                minIndex = ptr2;
            }
        }

        if (minIndex != ptr1) {
            swap(*minIndex, *ptr1);
        }
    }
}

//Task.9
void manipulateString(char* string, char symbol, char oddSymbol, char evenSymbol) {
    if (!string) {
        std::cout << "Invalid data" << std::endl;
        return;
    }

    unsigned int index = 0;

    for (char* ptr = string; *ptr; ptr++) {
        if (*ptr == symbol) {
            if (index % 2 == 0) {
                *ptr = evenSymbol;
            }
            else {
                *ptr = oddSymbol;
            }
        }

        index++;
    }
}

//Task.10
void manipulateText(char* text) {
    if (!text) {
        std::cout << "Invalid data" << std::endl;
        return;
    }

    bool inWord = false;

    for (char* ptr = text; *ptr; ptr++) {
        char curSymbol = *ptr;

        if (isLetter(curSymbol)) {
            if (!inWord) {
                inWord = true;
                *ptr = fromLowerToUpper(curSymbol);
            }
            else {
                *ptr = fromUpperToLower(curSymbol);
            }
        }
        else {
            inWord = false;
        }
    }
}

//Task.11
bool hasSymbol(const char* string, unsigned int length, char ch) {
    if (!string) return false;

    for (unsigned int i = 0; i < length; i++) {
        if (string[length] == ch) {
            return true;
        }
    }

    return false;
}

void getUnduplicatedElements(const char* first, const char* second, char* result) {
    if (!first || !second || !result) {
        std::cout << "Invalid data" << std::endl;
        return;
    }

    unsigned int firstLength = myStrLen(first);
    unsigned int secondLength = myStrLen(second);

    unsigned int resultLength = 0;

    for (const char* ptr = first; *ptr; ptr++) {
        if (!hasSymbol(second, secondLength, *ptr) && !hasSymbol(result, resultLength, *ptr)) {
            result[resultLength++] = *ptr;
        }
    }

    for (const char* ptr = second; *ptr; ptr++) {
        if (!hasSymbol(first, firstLength, *ptr) && !hasSymbol(result, resultLength, *ptr)) {
            result[resultLength++] = *ptr; 
        }
    }

    *result = '\0';
}

//Task.12
void getLongestPrefix(const char* const* matrix, char* result) {
    if (!matrix || !result) return;

    const char* firstWord = matrix[0];
    int prefixLength = 0;

    while (true) {
        char currentChar = firstWord[prefixLength];

        for (int i = 1; i < WORDS_NUM; i++) {
            if (matrix[i][prefixLength] != currentChar) {
                result[prefixLength] = '\0';
                return;
            }
        }

        result[prefixLength++] = currentChar;
    }
}

//Task.13 FROM EXAM
unsigned int fromCharToNumber(char ch) {
    if ('0' <= ch && ch <= '9') {
        return ch - '0';
    }

    if ('A' <= ch && ch <= 'Z') {
        return ch - 'A' + 10;
    }

    return 0;
}

unsigned int fromRandomToDecimal(const char* string, int k) {
    if (!string) {
        std::cout << "Invalid string" << std::endl;
        return 0;
    }

    unsigned int result = 0;
    int multiplier = 1;

    int length = myStrLen(string);

    for (int i = length - 1; i >= 0; i--) { 
        unsigned int curDigit = fromCharToNumber(string[i]);

        if (curDigit >= k) {
            std::cout << "Invalid number" << std::endl;
            return 0;
        }

        result += curDigit * multiplier;
        multiplier *= k;
    }

    return result;
}

//Task.14
bool isPrefix2(const char* substring, const char* string) {
    if (!substring || !string) return false;

    while (*substring) {
        char currentInSub = fromUpperToLower(*substring); 
        char currentInStr = fromUpperToLower(*string);

        if (currentInSub != currentInStr) {
            return false;
        }

        string++;
        substring++;
    }

    return true;
}

void fillString(char* string, char ch, int positions) {
    if (!string) {
        std::cout << "Invalid data" << std::endl;
        return;
    }

    for (int i = 0; i < positions; i++) {
        string[i] = ch;
    }
}

void censorText(char* text, const char* substring) {
    if (!text || !substring) {
        std::cout << "Invalid data" << std::endl;
        return;
    }

    int textLength = myStrLen(text);
    int subLength = myStrLen(substring);

    bool found = false;

    while (subLength <= textLength) { 
        if (isPrefix2(substring, text)) { 
            found = true;
            fillString(text, CENSOR_CHAR, subLength);

            text += subLength;  
            textLength -= subLength; 
        }
        else {
            text++;
            textLength--;
        }
    }

    if (!found) {
        std::cout << "Substring not found" << std::endl;
    }
}

int main()
{
    const char* matrix[3] = { "flower", "flow", "flight" };
    char num[] = "3579";
    char mun[] = "3696";
    char result[MAX_SIZE];
    
    getLongestPrefix(matrix, result);
    std::cout << integerCompare(num, mun) << std::endl; 
}

