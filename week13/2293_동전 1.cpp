//
// Created by 최우영 on 2021/02/14.
//

#include <iostream>

using namespace std;

// n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000)
int n, k;
int coin[101];

// 0원을 만드는 방법은 아무것도 사용하지 않는 한 가지 방법
int dp[10001] = {1,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    // 동전의 가치를 입력받는다.
    for (int i = 1; i <= n; ++i) {
        cin >> coin[i];
    }

    // 1번 코인부터 루프 순회
    for (int i = 1; i <= n; ++i) {
        int currentValue = coin[i];

        // 현재 동전 가치로는 그것보다 작은 가치는 만들지 못한다.
        for (int j = currentValue; j <= k; ++j) {
            // i번째 동전의 가치를 현재 가치에서 뺀 경우의 수를 더한다.
            dp[j] += dp[j - currentValue];
        }
    }

    cout << dp[k] << "\n";
}