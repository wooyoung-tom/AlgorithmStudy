//
// Created by 최우영 on 2021/01/31.
//

#include <iostream>

#define MAX 5001

// 첫째 줄에 N이 주어진다. (3 ≤ N ≤ 5000)
int N;

// dp array 0~5 까지는 미리 초기화
int dp[5001] = {0, MAX, MAX, 1, MAX, 1};

int main() {
    scanf("%d", &N);

    if (N >= 6) {
        for (int i = 6; i <= N; ++i) {
            dp[i] = std::min(dp[i - 3], dp[i - 5]) + 1;
        }
    }

    // 위에서 +1 수행하기 때문에 MAX, MAX 비교하였을 때 MAX + 1 인 경우가 발생
    if (dp[N] == MAX || dp[N] == MAX + 1) printf("-1");
    else printf("%d", dp[N]);
}