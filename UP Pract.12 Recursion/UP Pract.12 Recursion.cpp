// UP Pract.12 Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int BEG_COUNT = 0;
constexpr int LEAP_PERIOD = 4;
constexpr int COLS = 2;
constexpr int B_POS = 0;
constexpr int E_POS = 1;

//Task.1
int multiply(int n, int k) {
    if (k == 0) {
        return 0;
    }

    if (k < 0) {
        return -multiply(n, -k);
    }

    return n + multiply(n, k - 1);
}

//Task.2
bool contains(int n, int k) {
    if (n == 0) {
        return false;
    }

    if (n % 10 == k) {
        return true;
    }

    return contains(n / 10, k);
}

//Task.3
bool isSufix(long long n, long k) { 
    if (k == 0) {
        return true;
    }

    if (n % 10 != k % 10) {
        return false;
    }

    return isSufix(n / 10, k / 10);
}

//Task.4
int reverse(int n, int rev = 0) {
    if (n == 0) {
        return rev;
    }

    return reverse(n / 10, rev * 10 + n % 10);
}

//Task.5
size_t fibonacci(size_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

//FIBONACCI_CACHE
size_t fibonacci_Rec(size_t n, size_t* cache) {
    if (n == 0 || n == 1) {
        return n;
    }

    if (!cache[n]) {
        cache[n] = fibonacci_Rec(n - 1, cache) + fibonacci_Rec(n - 2, cache);
    }

    return cache[n];
}

size_t fibonacci_Cache(size_t n) {
    size_t* cache = new size_t[n + 1]();
    size_t result = fibonacci_Rec(n, cache);
    delete[] cache;

    return result;
}

//Task.6
void printRow(unsigned int N, unsigned int length) {
    if (length == 0) {
        cout << endl;
        return;
    }

    cout << N << " ";
    printRow(N - 1, length - 1);
}

void printNumbers(unsigned int N, unsigned int length) {
    if (length == 0) return;

    printNumbers(N, length - 1);
    printRow(N, length);
}

void print(unsigned int N) {
    if (N == 0) {
        cout << N << endl;
        return;
    }
    
    unsigned int length = N;
    printNumbers(N, length); 
}

//Task.7
bool isLeap(unsigned int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

unsigned int findNextLeapYear(unsigned int current) {
    unsigned int next = ++current;
    unsigned int rest = next % LEAP_PERIOD;

    if (rest) {
        next += (LEAP_PERIOD - rest);
    }

    if (next % 100 == 0 && next % 400 != 0) {
        next += LEAP_PERIOD;
    }

    return next; 
}

void printNextNLeapYears(unsigned int current, int N) {
    if (N == 0) {
        cout << endl;
        return;
    }

    unsigned int next = findNextLeapYear(current);
    cout << next << " ";

    printNextNLeapYears(next, N - 1);
}

//Task.8
int myStrLen(const char* string, int count) {
    if (!string) {
        return 0;
    }

    if (*string == '\0') {
        return count;
    }

    return myStrLen(++string, ++count);
}

bool checkPalindrome(const char* left, const char* right) {
    if (!left || !right) {
        return false;
    }

    if (left == right) {
        return true;
    }

    if (*left != *right) {
        return false;
    }

    checkPalindrome(++left, --right);  
}

bool isPalindrome(const char* str) {
    if (!str) return false;
   
    const char* left = str;
    const char* right = str + myStrLen(str, BEG_COUNT) - 1; 

    return checkPalindrome(left, right); 
}

//Task.9
bool hasElement(const int* arr, int size, int target) {
    if (size == 0) {
        return false;
    }

    return *arr == target || hasElement(arr + 1, size - 1, target);
}

//Task.10
bool hasElementBinary(const int* arr, int size, int target) {
    if (size == 0) {
        return false;
    }

    int midIndex = size / 2;

    if (arr[midIndex] == target) {
        return true;
    }

    if (target < arr[midIndex]) {
        return hasElementBinary(arr, midIndex, target);
    }
    else {
        return hasElement(arr + midIndex + 1, size - midIndex - 1, target);
    }
}

//Task.11
//for smaller numbers
int sumProperDivisors(int n, int d) {
    if (d > n / 2) return 0;
    if (n % d == 0) {
        return d + sumProperDivisors(n, d + 1);
    }
    return sumProperDivisors(n, d + 1);
}

bool isPerfect(int n) {
    if (n <= 1) return false;
    return n == sumProperDivisors(n, 1);
}

//for bigger numbers
int sumPairs(int n, int d) {
    if (d * d > n) return 0;

    int add = 0;

    if (n % d == 0) {
        int q = n / d;

        if (d != q) {
            add += d + q; 
        }
        else {
            add += d; 
        }
    }

    return add + sumPairs(n, d + 1);
}

bool perfect(int n) {
    if (n <= 1) return false;
    int sum = 1 + sumPairs(n, 2);
    return sum == n; 
}

//Task.12
bool hasEdge(const char (*matrix)[COLS], int rows, int i, char u, char v) {
    if (i == rows) return false;
    if (matrix[i][0] == u && matrix[i][1] == v) return true;
    return hasEdge(matrix, rows, i + 1, u, v);
}

bool checkTransitivity(const char (*matrix)[COLS], int rows, int i, char b, char e) {
    if (i == rows) return false;
    if (matrix[i][0] == b) {
        char x = matrix[i][1];
        if (hasEdge(matrix, rows, 0, x, e)) {
            return true;
        }
    }
    return checkTransitivity(matrix, rows, i + 1, b, e);
}

//FAST POW
int power(int n, int k) {
    if (k == 0) {
        return 1;
    }

    if (k & 1) {
        return n * power(n, k - 1);
    }
    else {
        return power(n * n, k / 2);
    }
}

int main()
{
   
}

