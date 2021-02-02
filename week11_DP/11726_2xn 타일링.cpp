//
// Created by 최우영 on 2021/02/02.
//

#include <iostream>

#define MAX 1001
#define DIVIDE_TARGET 10007

// (1 ≤ n ≤ 1,000)
int n;

// 2x1 일 때는 한가지 가능
// 2x2 일 때는 두가지 가능
int dp[MAX] = {0, 1, 2,};

int main() {
    scanf("%d", &n);

    // 가장 오른쪽에 2x1 하나 놓았을 때
    // 가장 오른쪽에 1x2 두개 놓았을 때
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIVIDE_TARGET;
    }

    printf("%d", dp[n]);
}