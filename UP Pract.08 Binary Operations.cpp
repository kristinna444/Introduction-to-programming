// UP Pract.08 Binary Operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr int MAX_NUM = 7;

//Task.1
bool isEven(int num) {
    int mask = 1;
    return !(num & mask);
}

//mask = 00001
//we compare the digits AT THE RIGHT ENDS
//if the number is EVEN, it will have 0 AT THE RIGHT END
//(0 & 1) -> false

//Task.2
unsigned int setBitToOne(unsigned int num, unsigned int pos) {
    unsigned int mask = 1;
    mask <<= pos;
    return num | mask;
}

//in binary representation: 
//we read the numbers FROM THE RIGHT TO THE LEFT
//the FIRST index is ZERO
//example: mask <<= 4
//0000001 -> 0010000

//Task.3
unsigned int clearBit(unsigned int num, unsigned int pos) {
    unsigned int mask = 1;
    mask <<= pos;
    mask = ~mask;

    return num & mask;
}

//the mask should have ZERO in the position where you want to clear the bit

//Task.4
// 1 to 0 or 0 to 1

unsigned int toggleBit(unsigned int num, unsigned int pos) {
    unsigned int mask = 1;
    mask <<= pos;
    return num ^ mask;
}

//Task.5
bool checkBit(unsigned int num, unsigned int pos) {
    unsigned int mask = 1;
    mask <<= pos;
    return (num & mask) == mask;
}

//Task.6
unsigned int getNumberInLastKBits(unsigned int number, unsigned int k) {
    unsigned int mask = 1;
    mask <<= k;
    mask -= 1;

    return number & mask;
}

//(mask <<= k) == 2^k
//(mask -= 1) == 2^k - 1 (prime number)
//8 = 01[000] -> 7 = 00[111]

//Task.7
unsigned int clearRightmostBit(unsigned int number) {
    return number & (number - 1);
}

//26 == 110[10] 25 == 110[01]
//38 == 1001[10] 37 == 1001[01]

//Task.8
unsigned int getNumberFromBits(unsigned int number, unsigned int startIndex, unsigned int length) {
    if (length > startIndex + 1) {
        length = startIndex + 1;
    }
    else {
        number >>= (startIndex - length + 1);
    }

    unsigned int mask = (1 << length) - 1;
    return number & mask;

}

//Task.9
void swap(unsigned int& a, unsigned int& b) {
    a = a ^ b;
    b = a ^ b; 
    a = a ^ b; 
}

//example:
//a = 5, b = 9
//a = 5 ^ 9 = 12
//b = 12 ^ 9 = 5
//a = 12 ^ 5 = 9

//Task.10
void printDayOfTheWeek(unsigned int number) {
    switch (number) {
    case 1:
        std::cout << "Monday "; break;
    case 2:
        std::cout << "Tuesday "; break;
    case 3:
        std::cout << "Wednesday "; break;
    case 4:
        std::cout << "Thursday "; break;
    case 5:
        std::cout << "Friday "; break;
    case 6:
        std::cout << "Saturday "; break;
    case 7:
        std::cout << "Sunday"; break;
    default:
        std::cout << "Invalid number!" << std::endl;
    }
}

void getDaysOfTheWeek(uint8_t number) {
    unsigned int mask = 1;
    bool hasExam = false;

    for (int i = 0; i < MAX_NUM; i++) {
        if ((mask << i) & number) {
            printDayOfTheWeek(i + 1);
            hasExam = true;
        }
    }

    if (!hasExam) {
        std::cout << "No exams this week!";
    }

    std::cout << std::endl;
}

//Task.11
void printIP(uint32_t ip) {
    uint8_t a = (ip >> 24) & 0xFF;
    uint8_t b = (ip >> 16) & 0xFF;
    uint8_t c = (ip >> 8) & 0xFF;
    uint8_t d = ip & 0xFF;

    std::cout << (int)a << " " << (int)b << " " << (int)c << " " << (int)d << std::endl; 
}

//example:
// 2155905152 -> binary: 10000000 10000000 10000000 10000000
// 10000000 -> decimal: 128
// result: 128 128 128 128

//SEMINAR
//Task.1
bool isPowerOfTwo(unsigned int number) {
    if (number == 0) {
        return false;
    }

    unsigned int mask = number - 1;
    return (number & mask) == 0;
}

//Task.2
void printSubset(const int* arr, int length, unsigned mask) {
    std::cout << "{ ";
    for (int i = 0; i < length; i++) {
        if (mask & 1) {
            std::cout << arr[i] << " ";
        }

        mask >>= 1;
    }

    std::cout << "}" << std::endl;
}
//for every position in the array:
//we look at the bit at the right end of the mask
//if this bit is 1 -> std::cout << arr[0] 
//the numbering in ARR begins from the opposite direction
//=> to check the following bit: (mask >>= 1)

void printSubsets(const int* arr, int length) {
    unsigned subsetsCount = 1 << length;

    for (int i = 0; i < subsetsCount; i++) {
        printSubset(arr, length, i);
    }
}

//every set has 2^LENGTH (of set) subsets
//every number I is a MASK for a particular subset

//Task.3
int findNotDuplicated(const int* arr, int length) {
    int result = 0;

    for (int i = 0; i < length; i++) {
        result ^= arr[i];
    }

    return result;
}

//XOR of a number with 0 = number
//XOR of a number with itself = 0

int main()
{
    int arr[] = { 1, 2, 3 };
    printSubsets(arr, 3);
}

