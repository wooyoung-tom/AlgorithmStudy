//
// Created by 최우영 on 2021/01/31.
//

#include <iostream>

#define STAIR_MAX 301

int N;
int stair[STAIR_MAX];
int dp[STAIR_MAX];

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &stair[i]);
    }

    // 첫 번째 계단과 두 번째 계단은 최댓값 구할 수 있음
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];

    // 세 번째 계단부터 마지막 계단까지 돌면 된다.
    for (int i = 3; i <= N; ++i) {
        // 이전 계단을 밟았을 때와 안밟았을 때 값 비교
        dp[i] = std::max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
    }

    printf("%d", dp[N]);
}