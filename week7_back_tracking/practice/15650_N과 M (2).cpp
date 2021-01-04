//
// Created by 최우영 on 2021/01/04.
//

#include <iostream>
#include <vector>

using namespace std;

// 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
int N, M;
int arr[9];
bool isVisited[9];

void solve(int depth, int num) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = num; i <= N; ++i) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            arr[depth] = i;
            solve(depth + 1, i + 1);
            isVisited[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    solve(0, 1);
}