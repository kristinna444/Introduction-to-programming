// UP Pract.06 Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_SIZE = 1024;
constexpr int DIGIT_SIZE = 5;
constexpr int MAX_ELEMENT = 30;

//Task.3
int getLongestRow(const int arr[], int length) {
    if (length == 0) {
        return 0;
    }

    int counter = 1;
    int maxLength = 1;

    for (int i = 0; i < length - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            counter++;
        }
        else {
            if (counter > maxLength) {
                maxLength = counter;
            }

            counter = 1;
        }
    }

    if (counter > maxLength) {
        maxLength = counter;
    }

    return maxLength;
}

//Task.4
//FINISH

//Task.5
void setToNull(int arr[], int length) {
    int currentNumber = 0;

    for (int i = 0; i < length; i++) {
        bool hasNumber = false;
        currentNumber = arr[i];

        while (currentNumber != 0) {
            if ((currentNumber % 10) == i) {
                hasNumber = true;
                break;
            }

            currentNumber /= 10;
        }

        if (!hasNumber) {
            arr[i] = 0;
        }
    }
}

//PrintFunc
void print(const int arr[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

//Task.6
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void orderAsc(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        int minIndex = i;

        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int findMissingNumber(const int arr[], int length) {
    for (int i = 0; i < length; i++) {
        if (arr[i] != i) {
            return i; 
        }
    } 

    return length;
}

//Task.7
bool checkLinearDependence(const int vector1[], int length1, const int vector2[], int length2) {
    if (length1 != length2) return false;

    for (int i = 0; i < length1; i++) {
        for (int j = i + 1; j < length1; j++) { 
            if (vector1[i] * vector2[j] != vector1[j] * vector2[i]) {
                return false;
            }
        }
    }

    return true;
}

//Task.8
void filterNegativeNums(const int arr[], int length, int result[], int& resultLength) {
    for (int i = 0; i < length; i++) {
        if (arr[i] >= 0) {
            result[resultLength++] = arr[i];
        }
    }
}

//Task.9
void getMinAndMax(const int arr[], int length, int& min, int& max) {
        min = arr[0]; 
        max = arr[0]; 

        for (int i = 1; i < length; i++) { 
            if (arr[i] < min) {  
                min = arr[i];  
            }

            if (arr[i] > max) { 
                max = arr[i]; 
            }
        }   
}

//Task.10
bool areAllElementsDiff(const int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }

    return true;
}

//BONUS
bool checkIfDistinct(const int arr[], int length) {
    bool seen[MAX_ELEMENT] = { false };

    for (int i = 0; i < length; i++) {
        int num = arr[i];

        if (num < 1 || num >= MAX_ELEMENT) return false;

        if (seen[num]) {
            return false;
        }

        seen[num] = true;
    }

    return true;
}

//Task.11
//my version
bool myFindSubarray(const int arr1[], int length1, const int arr2[], int length2) {
    for (int i = 0; i < length1; i++) {
        if (i + length2 > length1) {
            return false;
        }

        if (arr1[i] == arr2[0]) {
            int currentNum = 1; 

            for (int j = i + 1; j < i + length2; j++) {
                if (arr1[j] != arr2[currentNum]) {
                    break;
                }

                currentNum++;
            }

            if (currentNum == length2) {
                return true;
            }
        }
    }

    return false;
}

//FIXED VERSION
bool findSubarray(const int arr1[], int length1, const int arr2[], int length2) {
    if (length2 > length1) {
        return false;
    }

    for (int i = 0; i <= length1 - length2; i++) {
        bool match = true;

        for (int j = 0; j < length2; j++) {
            if (arr1[i + j] != arr2[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            return true;
        }
    }

    return false;
}

//Task.12
void addOneToArray(int num[]) {
    int memory = 0;

    num[DIGIT_SIZE - 1]++; 

    if (num[DIGIT_SIZE - 1] == 10) { 
        num[DIGIT_SIZE - 1] = 0; 
        memory = 1;
    }

    for (int i = DIGIT_SIZE - 2; i >= 0; i--) {
        num[i] += memory;
        memory = 0;

        if (num[i] == 10) {
            num[i] = 0;
            memory = 1;
        }
        else {
            break;
        }
    }
}

//Task.13
bool hasNumber(const int arr[], int length, int number) {
    for (int i = 0; i < length; i++) {
        if (number == arr[i]) {
            return true;
        }
    }

    return false;
}

void intersect(const int arr1[], int size1, const int arr2[], int size2, int result[], int& resultSize) {
    for (int i = 0; i < size1; i++) {
        if (hasNumber(arr2, size2, arr1[i]) && !hasNumber(result, resultSize, arr1[i])) {
            result[resultSize++] = arr1[i];
        }
    }
}

void merge(const int arr1[], int size1, const int arr2[], int size2, int result[], int& resultSize) {
    for (int i = 0; i < size1; i++) {
        bool contains = hasNumber(result, resultSize, arr1[i]);
        if (!contains) {
            result[resultSize++] = arr1[i];
        }
    }

    for (int i = 0; i < size2; i++) { 
        bool contains = hasNumber(result, resultSize, arr2[i]); 
        if (!contains) {
            result[resultSize++] = arr2[i]; 
        }
    }
}

int main()
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 2, 4, 6, 8, 11 };
    

    int result[MAX_SIZE];
    int resultLength = 0;

    std::cout << (checkLinearDependence(arr1, 5, arr2, 5) ? "true" : "false") << std::endl;
}

