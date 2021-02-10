//
// Created by 최우영 on 2021/02/10.
//

#include <iostream>
#include <climits>

#define MAX 501

// T, K (3 ≤ K ≤ 500)
int T, K;
int kArr[MAX];
int kSum[MAX];

// Memoization Array
// dp[i][j] = i번째 장부터 j번째 장까지 합치는데 드는 최소한의 비용.
int dp[MAX][MAX];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;

    while (T--) {
        std::cin >> K;
        for (int i = 1; i <= K; ++i) {
            std::cin >> kArr[i];
            kSum[i] = kSum[i - 1] + kArr[i];
        }

        for (int i = 1; i < K; ++i) {
            for (int j = 1; j + i <= K; ++j) {
                dp[j][i + j] = INT_MAX;

                for (int k = j; k < i + j; ++k) {
                    dp[j][i + j] = std::min(
                            dp[j][i + j],
                            dp[j][k] + dp[k + 1][i + j] + kSum[i + j] - kSum[j - 1]
                    );
                }
            }
        }

        std::cout << dp[1][K] << "\n";
    }
}