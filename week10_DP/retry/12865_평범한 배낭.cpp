//
// Created by 최우영 on 2021/01/27.
//

#include <iostream>

#define VALUE_MAX 101
#define WEIGHT_MAX 100001

/**
 * INPUT
 * 물품의 수 N(1 ≤ N ≤ 100)
 * 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000).
 * 물건의 무게 W(1 ≤ W ≤ 100,000)
 * 해당 물건의 가치 V(0 ≤ V ≤ 1,000).
 */
int N, K, W, V;

struct WeightValue {
    int weight, value;
};

WeightValue arr[VALUE_MAX];
int value[VALUE_MAX][WEIGHT_MAX];

void input() {
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &W, &V);
        arr[i] = {W, V};
    }
}

int main() {
    input();

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            int w = arr[i].weight;
            int v = arr[i].value;

            // 현재 Item 의 무게가 j 보다 크면 배낭에 넣지 못함
            // 이전 Item 의 value 와 동일하다.
            if (w > j) {
                value[i][j] = value[i - 1][j];
            }// 현재 Item 의 무게가 배낭에 넣을 수 있을 때
            else value[i][j] = std::max(v + value[i - 1][j - w], value[i - 1][j]);
        }
    }

    printf("%d", value[N][K]);
}