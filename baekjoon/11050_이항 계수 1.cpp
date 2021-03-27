//
// Created by 최우영 on 2021/03/08.
//

#include <iostream>

using namespace std;

int N, K;

long long binomial(int n, int k) {
    if (k == 0 || k == n) return 1;

    return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    cout << binomial(N, K);
}