#include <iostream>

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

WeightValue arr[101];

void input() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &W, &V);
        arr[i].weight = W;
        arr[i].value = V;
    }
}

int main() {
    input();


}