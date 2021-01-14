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

// 2 ≤ M,N ≤ 1,000 이다
int M, N;
int box[1001][1001];

int day;

queue<Point> q;
Point movePoint[4] = {
        Point{0, 1},
        Point{1, 0},
        Point{0, -1},
        Point{-1, 0}
};

bool isPossible(int mRow, int mCol) {
    return (mRow >= 0 && mRow < N && mCol >= 0 && mCol < M)
           && box[mRow][mCol] == 0;
}

void bfs() {
    while (!q.empty()) {
        int qSize = q.size();

        for (int i = 0; i < qSize; ++i) {
            Point currentPoint = q.front();
            q.pop();

            for (int j = 0; j < 4; ++j) {
                int mRow = currentPoint.row + movePoint[j].row;
                int mCol = currentPoint.col + movePoint[j].col;

                if (isPossible(mRow, mCol)) {
                    q.push(Point{mRow, mCol});
                    box[mRow][mCol] = 1;
                }
            }
        }
        day++;
    }
}

int main() {
    bool isCompleted = true;

    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &box[i][j]);

            if (box[i][j] == 1) q.push(Point{i, j});
            else if (box[i][j] == 0) isCompleted = false;
        }
    }

    bfs();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (box[i][j] == 0) {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", day - 1);

    return 0;
}