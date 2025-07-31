// UP Exam.02 Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isSufix(unsigned number, unsigned k) {
    if (number < k) {
        return false;
    }

    while (k) {
        if (number % 10 != k % 10) {
            return false;
        }

        number /= 10;
        k /= 10;
    }

    return true;
}

int countDigits(unsigned num) {
    if (num == 0) {
        return 1;
    }

    int count = 0;
    
    while (num) {
        count++;
        num /= 10;
    }

    return count;
}

int powerOf10(int p) {
    if (p == 0) {
        return 1;
    }

    int multiplier = 1;

    for (int i = 0; i < p; i++) {
        multiplier *= 10;
    }

    return multiplier; 
}

bool isConcat(unsigned number, unsigned k) {
    int digits = countDigits(k);
    int power = powerOf10(digits);

    number /= 10;

    while (number >= k) {
        if (isSufix(number, k)) {
            int A = number / power;

            if (A > 0) {
                return true;
            }
        }

        number /= 10;
    }

    return false;

}

int main()
{
    unsigned n, k;
    cin >> n >> k;
    cout << (isConcat(n, k) ? "true" : "false") << endl;
}

