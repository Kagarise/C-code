#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

#define TOL 2  // 多项式的总数

int getRand(int n, int m) {
    return (rand() % (m - n + 1)) + n;
}

int main() {
    freopen("D:\\CF\\in.txt", "w", stdout);
    srand(time(0));
    int n[TOL + 1];
    for (int i = 1; i <= TOL; i++) {
        n[i] = getRand(1, 10);
        cout << n[i] << endl;
        for (int j = 0; j < n[i]; j++)
            if (j == 0)
                cout << getRand(-10, 10) << " " << getRand(-10, 10) << " ";
            else
                cout << getRand(-10, 10) << " " << getRand(-10, 10) << " ";
        cout << endl;
    }
    int op = getRand(0, 2);
    switch (op) {
        case 0:
            cout << "+" << endl;
            break;
        case 1:
            cout << "-" << endl;
            break;
        case 2:
            cout << "*" << endl;
            break;
        default:
            break;
    }
}