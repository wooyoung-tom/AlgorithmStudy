//
// Created by 최우영 on 2021/02/01.
//

#include <iostream>
#include <climits>

#define MAX 100001

// 정수 n(1 ≤ n ≤ 100,000)
int n;
int arr[MAX];
int res[MAX];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // 첫 번째 최대값은 자기 자신
    res[0] = arr[0];

    // 두 번째 부터는 이전의 결과값에 영향을 받는다.
    for (int i = 1; i < n; ++i) {
        // 이전까지의 최대값과 자기 자신 더한 값이
        // 자신보다 작으면 새로운 연속합의 시작점이 된다.
        res[i] = std::max(res[i - 1] + arr[i], arr[i]);
    }

    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (max < res[i]) max = res[i];
    }

    printf("%d", max);
}