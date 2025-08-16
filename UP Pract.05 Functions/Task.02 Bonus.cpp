// Task.02 Bonus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//LEAST COMMON MULTIPLE
int lcm(int a, int b) {
    int i = a < b ? b : a;

    while (i % a != 0 || i % b != 0) {
        i++;
    }

    return i;
}

void addFraction(int first_num, int first_den, int sec_num, int sec_den, int& num, int& denom) {
    if (first_den == 0 || sec_den == 0) return;

    if (first_den == sec_den) {
        num = first_num + sec_num;
        denom = first_den;
        return;
    }

    int m = lcm(first_den, sec_den);
    denom = m; 

    int first_mult = m / first_den; 
    int sec_mult = m / sec_den; 

    num = first_num * first_mult + sec_num * sec_mult; 
}

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d;
    addFraction(a, b, c, d, e, f);
    cout << e << " " << f << endl;
}

