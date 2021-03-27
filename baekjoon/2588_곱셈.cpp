//
// Created by djdj7 on 2020-03-13.
//

#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int b = 0;

    cin >> a >> b;

    int one = b - ((b % 100) * 100) - ((b / 10) * 10);
    int ten = b - ((b % 100) * 100);
    int hundred = b % 100;

    int first = a * one;
    int second = a * ten * 10;
    int third = a * hundred * 100;

    int result = first + second + third;

    cout << result;
}