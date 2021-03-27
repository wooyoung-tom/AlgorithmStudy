//
// Created by 최우영 on 2020/12/28.
//

/*
 * 시간제한 1초...
 * 이중 for 구문을 돌면 시간초과 날 것
 * 두 번째 for 구문에서 j 가 증가하는 범위를 달리 해주면 된다.
 */

#include <iostream>

using namespace std;

// Global 선언이기 때문에 0으로 모두 초기화 된다.
int cnt[50001];

int main() {
    // 자연수 N(5<=N<=50,000)
    int N;

    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        // j iterator 를 i 의 배수로 증가시키는 것
        for (int j = i; j <= N; j = j + i) {
            cnt[j]++;
        }
    }

    for (int i = 1; i <= N; ++i) {
        printf("%d ", cnt[i]);
    }

    return 0;
}