//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d, e, verify;

    cin >> a >> b >> c >> d >> e;

    verify = a * a + b * b + c * c + d * d + e * e;
    verify %= 10;

    cout << verify;
}