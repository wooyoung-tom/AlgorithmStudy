//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

#define INIT_MAX -1000001
#define INIT_MIN 1000001

using namespace std;

int main() {
    // 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다
    int N;
    int num;

    // 최소값, 최대값
    int min = INIT_MIN, max = INIT_MAX;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);
        if (min > num) min = num;
        if (max < num) max = num;
    }

    printf("%d %d", min, max);
}