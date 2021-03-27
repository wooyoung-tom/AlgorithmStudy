//
// Created by djdj7 on 2020-03-18.
//

#include <iostream>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    if(a > b) {
        cout << ">";
    } else if (a < b) {
        cout << "<";
    } else if (a == b) {
        cout << "==";
    }
}