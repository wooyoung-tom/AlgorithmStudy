//
// Created by 최우영 on 2020/12/28.
//

#include <iostream>

using namespace std;

int main() {
    int A, B, sum = 0;

    cin >> A >> B;

    for (int i = A; i < B; ++i) {
        cout << i << " + ";
        sum += i;
    }

    cout << B << " = " << sum + B;

    return 0;
}