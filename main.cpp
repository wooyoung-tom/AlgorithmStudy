//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col;
};

// 두 정수 N, M(2 ≤ N, M ≤ 100)
int N, M;
int maze[101][101];
bool isVisited[101][101];

int res;

queue<Point> q;

Point movePoint[4] = {
        Point{0, 1},
        Point{1, 0},
        Point{0, -1},
        Point{-1, 0}};

bool isPossiblePoint(int mRow, int mCol) {
    return (mRow > 0 && mRow <= N && mCol > 0 && mCol <= M)
           && maze[mRow][mCol] == 1
           && !isVisited[mRow][mCol];
}

void bfs() {
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int mRow = current.row + movePoint[i].row;
            int mCol = current.col + movePoint[i].col;

            if (isPossiblePoint(mRow, mCol)) {
                isVisited[mRow][mCol] = true;
                res++;

            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &maze[i][j]);
        }
    }

    q.push(Point{1, 1});
    isVisited[1][1] = true;
    bfs();
}