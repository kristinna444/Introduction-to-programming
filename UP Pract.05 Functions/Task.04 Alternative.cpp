// Task.04 Alternative.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int getDigits(int number) {
    if (number == 0) return 1;

    int counter = 0;

    while (number != 0) {
        counter++;
        number /= 10;
    }

    return counter;
}

void addDigit(int& number, int digit) {
    number = number * 10 + digit;
}

void reverseNumber(int& number) {
    int result = 0;

    while (number) {
        int curDigit = number % 10;
        addDigit(result, curDigit);
        number /= 10;
    }

    number = result;
}

void divideNumberInTwo(int number, int& even, int& odd) {
    even = 0, odd = 0;

    int digitCount = getDigits(number);
    reverseNumber(number);

    int current = 0;

    for (int i = 1; i <= digitCount; i++) {
        current = number > 0 ? number % 10 : 0;

        if (i % 2 == 0) {
            even *= 10;
            even += current;
        }
        else {
            odd *= 10;
            odd += current;
        }

        number /= 10;
    }
}

int main()
{
    int a, even = 0, odd = 0;
    cin >> a;

    divideNumberInTwo(a, even, odd);
    cout << even << " " << odd << endl;

}
