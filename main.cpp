//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <vector>

#define MAX 20 + 1

using namespace std;

// 좌표담을 구조체
struct Point {
    int i, j;
};

// N(4 ≤ N ≤ 20, N은 짝수)
int N;
// N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고,
// i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고,
// 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.
int S[MAX][MAX];
bool isVisited[MAX][MAX];

int min = 101;

void input() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &S[i][j]);
        }
    }
}

void solve(int depth) {
    if (depth == N) {

    }


}

int main() {
    input();

    solve(0);
}