//
// Created by 최우영 on 2020/12/28.
//

#include <iostream>

using namespace std;

int main() {
    int N, M, i, sum = 0;

    cin >> N >> M;

    for (i = 1; i <= N; i++) {
        if (i % M == 0) {
            sum += i;
        }
    }

    cout << sum;

    return 0;
}