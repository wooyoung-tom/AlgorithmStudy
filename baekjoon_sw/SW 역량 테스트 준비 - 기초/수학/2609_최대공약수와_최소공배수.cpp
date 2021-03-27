//
// Created by djdj7 on 2020-05-28.
//

/*
 *  유클리드 호제법 이라는 방식이 있었음.
 *  최대 공약수를 이용하여 최소 공배수를 구함.
 */

#include <iostream>
#include <vector>

using namespace std;

int a, b;
vector<int> result_v;

void input() {
    cin >> a >> b;
}

void GCD_LCM(int _a, int _b) {
    int lcm = 0;
    while (_b != 0) {
        int remainder = _a % _b;
        _a = _b;
        _b = remainder;
    }
    result_v.push_back(_a);
    lcm = a * b / _a;
    result_v.push_back(lcm);
}

int main() {
    input();
    GCD_LCM(a, b);

    for (int i = 0; i < result_v.size(); ++i) {
        cout << result_v[i] << "\n";
    }
}