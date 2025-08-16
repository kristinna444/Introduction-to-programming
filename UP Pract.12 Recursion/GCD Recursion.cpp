// GCD Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == b) {
        return a;
    }

    if (a > b) {
        return gcd(a - b, a);
    }

    return gcd(a, b - a);
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;
}

