//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

typedef long long ll;

// 정답 담을 배열 선언 (전역이라 0으로 초기화 됨)
int res[10];

int main() {
    // A, B, C는 모두 100보다 같거나 크고, 1,000보다 작은 자연수
    int A, B, C;
    ll mRes = 0;

    cin >> A >> B >> C;

    mRes = A * B * C;

    while (mRes > 0) {
        res[mRes % 10]++;
        mRes /= 10;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d\n", res[i]);
    }
}