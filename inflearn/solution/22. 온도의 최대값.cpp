//
// Created by 최우영 on 2021/02/02.
//

// https://www.acmicpc.net/problem/2559

#include <iostream>
#include <climits>

// 2 <= N <= 100000
// 1 <= K <= N
int N, K;
int max = INT_MIN;
int a[100001];

int main() {
    int sum = 0;

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    // 첫 번째 K 구간의 합
    for (int i = 0; i < K; i++) {
        sum += a[i];
    }

    // max 값 init
    max = sum;

    // K 번째부터 구간의 합
    for (int i = K; i < N; ++i) {
        sum += (a[i] - a[i - K]);
        if (max < sum) max = sum;
    }

    printf("%d", max);
}