// UP Pract.08 Number Systems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_SIZE = 20;
constexpr int BASE = 36;

//Task.1
char numberToChar(unsigned number) {
    if (0 <= number && number <= 9) {
        return number + '0';
    }

    if (10 <= number && number <= 36) {
        return (number - 10) + 'A';
    }

    return 0;
}

void mySwap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void reverseArray(char arr[], int length) {
    for (int i = 0; i < length / 2; i++) {
        mySwap(arr[i], arr[length - i - 1]);
    }
}

int getNumberOfOnes(unsigned number, char result[], int& resultLength) {
    int counter = 0;
    resultLength = 0;

    while (number != 0) {
        unsigned lastDigit = number % 2;
        if (lastDigit == 1) {
            counter++;
        }
        result[resultLength++] = numberToChar(lastDigit);
        number /= 2;
    }

    reverseArray(result, resultLength);
    return counter;
}

//BinaryToDecimal
unsigned charToNumber(char a) {
    if ('0' <= a && a <= '9') {
        return a - '0';
    }

    if ('A' <= a && a <= 'Z') {
        return a - 'A' + 10;
    }

    return 0;
}

unsigned binaryToDecimal(const char source[], int& length) {
    unsigned result = 0;
    int multiplier = 1;

    for (int i = length - 1; i >= 0; i--) {
        result += charToNumber(source[i]) * multiplier;
        multiplier *= 2;
    }

    return result;
}

//Task.2
void decimalToRandom(unsigned number, char result[], int& resultLength, int n) {
    resultLength = 0;
    while (number != 0) {
        unsigned lastDigit = number % n; 
        result[resultLength++] = numberToChar(lastDigit); 
        number /= n; 
    }

    reverseArray(result, resultLength);
}

unsigned randomToDecimal(const char source[], int& sourceLength, int k) {
    unsigned result = 0;
    int multiplier = 1;

    for (int i = sourceLength - 1; i >= 0; i--) {
        result += charToNumber(source[i]) * multiplier; 
        multiplier *= k;
    }

    return result; 
}

void randomToRandom(const char source[], int sourceLength, int k, char result[], int& resultLength, int n) {
    unsigned decimal = randomToDecimal(source, sourceLength, k);
    decimalToRandom(decimal, result, resultLength, n);
}

//Task.3
void addOne(char number[], int length, int K) {
    int carry = 1;

    for (int i = length - 1; i >= 0; i--) {
        int currentNumber = charToNumber(number[i]);
        currentNumber += carry;

        if (currentNumber >= K) {
            carry = 1;
            number[i] = numberToChar(currentNumber % K);
        }
        else {
            carry = 0;
            number[i] = numberToChar(currentNumber);
            break;
        }
    }
}

//Task.4
void subtractOne(char number[], int length, int K) { 
    int borrow = 1; 

    for (int i = length - 1; i >= 0; i--) {
        int currentNumber = charToNumber(number[i]);
        currentNumber -= borrow;

        if (currentNumber < 0) {
            borrow = 1;
            number[i] = numberToChar(currentNumber + K);
        }
        else {
            borrow = 0;
            number[i] = numberToChar(currentNumber);
            break;
        }
    }
    //return borrow == 0;
}

//Task.5
void toReadableSystem(int N, char result[], int& resultLength) {
    resultLength = 0;

    while (N != 0) {
        int lastDigit = N % BASE;
        result[resultLength++] = numberToChar(lastDigit);
        N /= BASE;
    }

    reverseArray(result, resultLength);
}

//PrintFunc
void printArr(const char arr[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    char source[] = { '1', '0', '0'};
    int sourceLength = 3;
 
    char result[MAX_SIZE];
    int resultLength = 0;

    subtractOne(source, sourceLength, 2);
    printArr(source, sourceLength); 
    
}

