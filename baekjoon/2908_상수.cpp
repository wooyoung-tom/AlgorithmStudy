//
// Created by 최우영 on 2021/02/28.
//

#include <iostream>

using namespace std;

int A, B;
int rA, rB;

// 자연수를 입력받아 뒤집어서 리턴하는 함수
int reverse(int x) {
    int res = 0;

    while (x > 0) {
        int tmp = x % 10;
        res = res * 10 + tmp;
        x /= 10;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B;

    rA = reverse(A);
    rB = reverse(B);

    if (rA > rB) cout << rA;
    else cout << rB;
}