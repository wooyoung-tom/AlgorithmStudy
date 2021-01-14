//
// Created by 최우영 on 2021/01/14.
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
        Point{-1, 0}
};

bool isPossiblePoint(int mRow, int mCol) {
    return (mRow > 0 && mRow <= N && mCol > 0 && mCol <= M)
           && maze[mRow][mCol] == 1
           && !isVisited[mRow][mCol];
}

void bfs() {
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            Point current = q.front();
            q.pop();

            for (int j = 0; j < 4; ++j) {
                int mRow = current.row + movePoint[j].row;
                int mCol = current.col + movePoint[j].col;

                if (isPossiblePoint(mRow, mCol)) {
                    q.push(Point{mRow, mCol});
                    isVisited[mRow][mCol] = true;

                    if (mRow == N && mCol == M) {
                        res++;
                        return;
                    }
                }
            }
        }
        res++;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%1d", &maze[i][j]);
        }
    }

    q.push(Point{1, 1});
    isVisited[1][1] = true;
    res++;

    bfs();

    printf("%d", res);
}