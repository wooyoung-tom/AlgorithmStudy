//
// Created by 최우영 on 2021/01/14.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int row, col;
};

// 지도의 크기 N
// (정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)
int N;
int map[25][25];
bool isVisited[25][25];

int complex, house;

vector<Point> housePoint;
vector<int> houseCnt;

queue<Point> q;

Point movePoint[4] = {
        Point{0, 1},
        Point{1, 0},
        Point{0, -1},
        Point{-1, 0}
};

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%1d", &map[i][j]);

            // 집이 있으면 출발지 후보군 중 하나
            if (map[i][j] == 1) housePoint.push_back(Point{i, j});
        }
    }
}

bool isPossible(int mRow, int mCol) {
    return (mRow >= 0 && mRow < N && mCol >= 0 && mCol < N)
           && map[mRow][mCol] == 1
           && !isVisited[mRow][mCol];
}

void bfs(Point start) {
    q.push(start);
    isVisited[start.row][start.col] = true;
    house++;

    while (!q.empty()) {
        Point currentPoint = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int mRow = currentPoint.row + movePoint[i].row;
            int mCol = currentPoint.col + movePoint[i].col;
            if (isPossible(mRow, mCol)) {
                q.push(Point{mRow, mCol});
                isVisited[mRow][mCol] = true;
                house++;
            }
        }
    }
}

int main() {
    input();

    for (int i = 0; i < housePoint.size(); ++i) {
        // 해당 집이 현재 단지에 포함되어 있지 않다면 bfs 동작
        if (!isVisited[housePoint[i].row][housePoint[i].col]) {
            bfs(housePoint[i]);

            complex++;

            houseCnt.push_back(house);
            house = 0;
        }
    }

    printf("%d\n", complex);

    sort(houseCnt.begin(), houseCnt.end());
    for (int i = 0; i < houseCnt.size(); ++i) {
        printf("%d\n", houseCnt[i]);
    }
}