// Защо днес е решило да не работи.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int LIMIT = 100000;
constexpr int AVERAGE_LIMIT = 10;

//Swap
void swap(int& a, int& b) {
    int temp = 0;
    a = b;
    b = temp;
}

//Greatest common divisor
int gcd(int a, int b) {
    int i = a > b ? b : a;

    while (a % i != 0 || b % i != 0) {
        i--;
    }

    return i;
}

int greatestCommonDivisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

//Task.2
void simplifyFraction(int& numerator, int& denominator) {
    int div = gcd(numerator, denominator);
    numerator /= div;
    denominator /= div;
}

//Task.3
void concat(int& first, int second) { 
    int temp = second;
    int multiplier = 1; 

    while (temp) {
        multiplier *= 10;
        temp /= 10;
    }

    first = first * multiplier + second;
}

//Find number of digits 
int getDigits(int number) {
    if (number == 0) return 1;

    int counter = 0;

    while (number != 0) {
        counter++;
        number /= 10;
    }

    return counter;
}

//Power Of 10
int powerOf10(int k) {
    if (k == 0) return 1;

    int multiplier = 1;

    while (k != 0) {
        multiplier *= 10;
        k--;
    }

    return multiplier;
}

//Add Digit
void addDigit(int& number, int digit) {
    number = number * 10 + digit;
}

//Task.4
void divideNumberInTwo(int number, int& even, int& odd) {
    even = 0, odd = 0;

    int index = 1;
    int digitCount = getDigits(number);

    while (index <= digitCount) {
        int current = number / powerOf10(digitCount - index); 
        current %= 10;

        if (index % 2 == 0) {
            addDigit(even, current);
        }
        else {
            addDigit(odd, current);
        }

        index++;
    }
}

//Task.5
void reverseNumber(int& number) {
    int result = 0;

    while (number) {
        int curDigit = number % 10;
        addDigit(result, curDigit);
        number /= 10;
    }

    number = result;
}

void getNewNumber(int& number, int index, int newDigit) { 
    int result = 0;
    int digitsCount = getDigits(number);
    
    for (int i = digitsCount; i > 0; i--) {
        int current = number % 10;

        if (i == index) {
            current = newDigit;
        }

        addDigit(result, current);
        number /= 10;
    }

    reverseNumber(result);
    number = result;
}

int getDigitAt(int number, int index) {
    reverseNumber(number);

    for (int i = 1; i < index; i++) {
        number /= 10;
    }

    return number % 10;
}

void swapDigitsAt(int& first, int& second, int index) {
    int digitFirst = getDigitAt(first, index); 
    int digitSecond = getDigitAt(second, index); 

    getNewNumber(first, index, digitSecond);   
    getNewNumber(second, index, digitFirst);   
}

//Task.6
bool isRowEvenOrOdd(int n) {
    double current = 1, result = 0;

    for (int i = 1; i <= n; i++) {
        result = (current * 3) / 2;
        current = result;
    }

    int whole = result;
    return whole % 2 == 0;
}

//Task.7
void extractNumber(int& number, int i, int j) {
    if (i > j) {
        swap(i, j);
    }

    int digitsCount = getDigits(number);
    reverseNumber(number);

    int newNumber = 0;

    for (int index = 0; index < digitsCount; index++) {
        if (i <= index && index <= j) {
            newNumber *= 10;
            newNumber += number % 10;

            if (index == j) {
                break;
            }
        }

        number /= 10; 
    }

    number = newNumber;
}

//Task.8
int getDigitAverage(int number) {
    int sumOfDigits = 0;
    int counter = 0;

    while (number) {
        sumOfDigits += number % 10;
        counter++;
        number /= 10;
    }

    return sumOfDigits / counter;
}

void printAverageAboveK(unsigned int M, unsigned int N, unsigned int K) {
    if (M > LIMIT || N > LIMIT || K > AVERAGE_LIMIT) return;

    if (M > N) {
        swap(M, N);
    }

    for (unsigned int current = M; current <= N; current++) {
        if (getDigitAverage(current) >= K) {
            cout << current << " ";
        }
    }

    cout << endl;
}

//Task.9
void printNumsWithDuplicatedDigits(unsigned int K, unsigned int L) {
    if (K > LIMIT || L > LIMIT) return;

    if (K > L) {
        swap(K, L);
    }

    for (unsigned int current = K; current <= L; current++) {
        unsigned int copy = current;

        while (copy >= 10) {
            int curDigit = copy % 10;
            int next = (copy / 10) % 10;

            if (next == curDigit) { 
                cout << current << " ";
                break;
            }

            copy /= 10;
        }
    }

    cout << endl; 
}

//Task.10
void modifyNumbers(int& a, int& b, int k) {
    int digitsInA = getDigits(a);
    if (k > digitsInA) { 
        k = digitsInA;
    }

    int newNumber = 0;
    for (int i = 0; i < k; i++) {
        int curDigit = a % 10;
        addDigit(newNumber, curDigit);
        a /= 10;
    }

    reverseNumber(newNumber);
    concat(newNumber, b);

    b = newNumber;
}


int main()
{
    int number, i, j;   
    cin >> number >> i >> j;   
    
    extractNumber(number, i, j);
    cout << number << endl;


}

