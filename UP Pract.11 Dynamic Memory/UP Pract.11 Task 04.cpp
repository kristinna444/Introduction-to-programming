// UP Pract.11 Task.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 50;

int myStrLen(const char* string) {
    if (!string) return 0;

    int count = 0;

    while (*string) {
        count++;
        string++;
    }

    return count;
}

void myStrCpy(char* dest, const char* source, int letters) {
    if (!dest || !source) {
        cout << "Error" << endl;
        return;
    }

    int index = 0;
    while (*source && index < letters) {
        *dest = *source;
        dest++;
        source++;

        index++;
    }

    *dest = '\0';
}

void printMatrix(const char* const* matrix, int rowSize) {
    for (int i = 0; i < rowSize; i++) {
        cout << "[" << matrix[i] << "]";

        if (i < rowSize - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

int main()
{
    char string[MAX_SIZE];
    cin.getline(string, MAX_SIZE);

    int rowSize = myStrLen(string) + 1;
    char** matrix = new char* [rowSize];

    
    for (int prefix = 0; prefix < rowSize; prefix++) { 
        matrix[prefix] = new char[prefix + 1];  
        myStrCpy(matrix[prefix], string, prefix);
    }

    printMatrix(matrix, rowSize);

    for (int i = 0; i < rowSize; i++) {
        delete[] matrix[i];
    }

    delete[] matrix; 
}

