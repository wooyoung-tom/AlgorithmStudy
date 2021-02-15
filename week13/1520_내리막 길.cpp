//
// Created by 최우영 on 2021/02/15.
//
#include <iostream>

#define MAX 501

using namespace std;

// M과 N은 각각 500이하의 자연수
int M, N;
int map[MAX][MAX];
int dp[MAX][MAX];

int dRow[4] = {-1, 1, 0, 0};
int dCol[4] = {0, 0, -1, 1};

/**
 * 움직일 수 있는 범위 내에 있는 지 확인하는 함수
 * @param mRow 움직이고 난 후의 row
 * @param mCol 움직이고 난 후의 col
 * @param target 현재 위치의 map 높이 값
 * @return 가능하면 true, 불가능하면 false
 */
bool isPossible(int mRow, int mCol, int target) {
    return mRow >= 1 && mRow <= M && mCol >= 1 && mCol <= N && map[mRow][mCol] < target;
}

int dfs(int row, int col) {
    // (M, N)에 도착하면 return 1
    if (row == M && col == N) return 1;

    // 현재 dp 배열의 값이 -1이 아니면 방문했던 곳이기 때문에
    // 그대로 return 해준다.
    if (dp[row][col] != -1) return dp[row][col];

    // 위 두가지 모두 건너면 방문 안한 좌표이기 때문에
    // dp 배열 값을 0으로 초기화 해준다.
    dp[row][col] = 0;

    // 네개 방향 상, 하, 좌, 우 순서로 움직인다.
    for (int i = 0; i < 4; ++i) {
        int mRow = row + dRow[i];
        int mCol = col + dCol[i];

        // 움직일 수 있는 범위인지, 내리막인지 확인해준다.
        if (isPossible(mRow, mCol, map[row][col])) {
            // 가능하다면 움직인 곳으로 dfs 진행
            dp[row][col] += dfs(mRow, mCol);
        }
    }

    return dp[row][col];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> map[i][j];

            // dp 배열을 모두 -1로 초기화 시켜준다.
            dp[i][j] = -1;
        }
    }

    cout << dfs(1, 1) << "\n";
}