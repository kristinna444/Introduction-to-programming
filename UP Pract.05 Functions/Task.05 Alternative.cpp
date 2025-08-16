// Task.05 Alternative.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int powerOf10(int k) {
    if (k == 0) return 1;

    int multiplier = 1;

    while (k != 0) {
        multiplier *= 10;
        k--;
    }

    return multiplier;
}

int getKthDigit(int n, int digits, int k) {
    if (k < 0 || k > digits) return 0;

    int divisor = powerOf10(digits - k);
    n /= divisor;

    return n % 10;
}

void changeKthDigit(int& n, int digits, int k, int d) {
    if (k < 0 || k > digits) return;

    int divisor = powerOf10(digits - k);
    int remain = n % divisor;

    n /= (divisor * 10);

    n = n * 10 + d;
    n = n * divisor + remain;
}

void swapKthDigits(int& a, int& b, int k) {
    int digitsInA = getDigits(a);
    int digitsInB = getDigits(b);

    int m = getKthDigit(a, digitsInA, k);
    int n = getKthDigit(b, digitsInB, k);

    changeKthDigit(a, digitsInA, k, n);
    changeKthDigit(b, digitsInB, k, m);
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    swapKthDigits(a, b, k);
    cout << a << " " << b << endl;

}

