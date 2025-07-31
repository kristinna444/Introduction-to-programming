// Prefix-Infix-Sufix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isPrefix(unsigned int number, unsigned int expectedPrefix) {
    while (number >= expectedPrefix) {
        if (number == expectedPrefix) {
            return true;
        }

        number /= 10;
    }

    return false;
}

bool isSufix(unsigned number, unsigned expectedSufix) {
    if (number < expectedSufix) {
        return false;
    }

    while (expectedSufix) {
        if (number % 10 != expectedSufix % 10) {
            return false;
        }

        number /= 10;
        expectedSufix /= 10;
    }

    return true;
}

bool isInfix(unsigned number, unsigned infix) {
    while (number >= infix) {
        if (isSufix(number, infix)) {
            return true;
        }

        number /= 10;
    }

    return false;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << (isInfix(a, b) ? "true" : "false") << endl;  
}

