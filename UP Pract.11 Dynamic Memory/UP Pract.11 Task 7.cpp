// UP Pract.11 Task 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
constexpr int INITIAL_VALUE = 0;

void swap(int*& arr1, int*& arr2) {
    int* temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}

void swapInt(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int* getPlayersInTeam(int teams) {
    int* playersInTeam = new int[teams];

    for (int i = 0; i < teams; i++) {
        cin >> playersInTeam[i];
    }

    return playersInTeam;
}

int** initializeMatrix(int teams, const int* playersInTeam) {
    if (!playersInTeam) return nullptr;

    int** matrix = new int* [teams];

    for (int i = 0; i < teams; i++) {
        int players = playersInTeam[i];
        matrix[i] = new int[players];

        for (int j = 0; j < players; j++) {
            matrix[i][j] = INITIAL_VALUE;
        }
    }

    return matrix;
}

int getSumOfPoints(const int* team, int players) {
    if (!team) return 0;

    int sum = 0;

    for (int i = 0; i < players; i++) {
        sum += team[i];
    }

    return sum;
}

//THE ROW WHERE WE HAVE ADDED POINTS GOES UP
//IF THE TEAM ABOVE HAS NOW LESS POINTS
//(UNTIL IT REACHES A TEAM WITH HIGHER RANKING)
void rearrangeMatrix(int** matrix, int* playersInTeam, int currentTeam) {
    if (!matrix || !playersInTeam) return;

    for (int i = currentTeam; i > 0; i--) {
        int currentSum = getSumOfPoints(matrix[i], playersInTeam[i]);
        int prevSum = getSumOfPoints(matrix[i - 1], playersInTeam[i - 1]);

        if (currentSum > prevSum) {
            swap(matrix[i], matrix[i - 1]);
            swapInt(playersInTeam[i], playersInTeam[i - 1]);
        }
        else {
            break;
        }
    }
}

void updateMatrix(int** matrix, int teams, int* playersInTeam, int t, int p, int points) {
    if (!matrix || !playersInTeam) {
        return;
    }

    if (t < 0 || t >= teams) { 
        cout << "Invalid input" << endl;
        return;
    }

    if (p < 0 || p >= playersInTeam[t]) {
        cout << "Invalid input" << endl;
        return;
    }

    matrix[t][p] += points;
    rearrangeMatrix(matrix, playersInTeam, t);
}

void printMatrix(const int* const* matrix, int teams, const int* playersInTeam) {
    if (!matrix || !playersInTeam) return;

    for (int i = 0; i < teams; i++) {
        int players = playersInTeam[i];

        for (int j = 0; j < players; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void freeMatrix(int** matrix, int teams) {
    if (!matrix) return;

    for (int i = 0; i < teams; i++) {
        delete[] matrix[i];
    }

    delete[] matrix; 
}

int main()
{
    int teams;
    cin >> teams;
    int* playersInTeam = getPlayersInTeam(teams);
    int** matrix = initializeMatrix(teams, playersInTeam);

    while (true) {
        int t, p, points; 
        cin >> t >> p >> points;

        if (t == -1) {
            break;
        }

        updateMatrix(matrix, teams, playersInTeam, t, p, points);
        printMatrix(matrix, teams, playersInTeam);
    }

    freeMatrix(matrix, teams);
    delete[] playersInTeam; 
}

