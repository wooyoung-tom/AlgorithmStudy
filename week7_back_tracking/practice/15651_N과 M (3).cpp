//
// Created by 최우영 on 2021/01/04.
//

#include <iostream>
#include <vector>

using namespace std;

// 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
int N, M;
int arr[9];

void solve(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; ++i) {
        arr[depth] = i;
        solve(depth + 1);
    }
}

int main() {
    scanf("%d %d", &N, &M);

    solve(0);
}