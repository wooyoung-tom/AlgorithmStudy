//
// Created by 최우영 on 2021/01/25.
//

#include <iostream>

#define MAX 1000001

int N;
int res[MAX] = {0, 0,};

int main() {
    scanf("%d", &N);

    for (int i = 2; i <= N; ++i) {
        res[i] = res[i - 1] + 1;
        if (i % 2 == 0) res[i] = std::min(res[i], res[i / 2] + 1);
        if (i % 3 == 0) res[i] = std::min(res[i], res[i / 3] + 1);
    }

    printf("%d", res[N]);
}