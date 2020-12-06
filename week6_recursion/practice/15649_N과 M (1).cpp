//
// Created by 최우영 on 2020/12/03.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
int N, M;
int arr[8];
bool isVisited[8];

void input() {
    cin >> N >> M;
}

void solution(int num) {
    if (num == M) {
        for (int i = 0; i < M; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            arr[num] = i;
            solution(num + 1);
            isVisited[i] = false;
        }
    }
}

int main() {
    input();
    solution(0);
}