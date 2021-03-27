//
// Created by djdj7 on 2020-04-22.
//

/*
 * TODO 7576 토마토
 *  1. 입력 시 1이 나오면, 익은 토마토 큐에 Push
 *  2. 큐에서 꺼내면서, 현재 큐 size 만큼만 돈다.
 *  3. 큐 size 만큼 돌면 하루 지난것.
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int box[1000][1000];
int day = -1;
bool isBeforeAllRipen = true;

int move_row[] = {0, 0, 1, -1};
int move_col[] = {1, -1, 0, 0};

typedef struct {
    int row, col;
} Point;

queue<Point> ripen_points;

void input() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 0) {
                isBeforeAllRipen = false;
            } else if (box[i][j] == 1) {
                Point ripen_point = {i, j};
                ripen_points.push(ripen_point);
            }
        }
    }
}

bool isInBound(int row, int col) {
    return row < N && row >= 0 && col < M && col >= 0;
}

void bfs() {
    while (!ripen_points.empty()) {
        int old_size = ripen_points.size();
        for (int i = 0; i < old_size; ++i) {
            Point pop_point = ripen_points.front();
            int pop_row = pop_point.row;
            int pop_col = pop_point.col;
            ripen_points.pop();

            /* 0: 오른쪽, 1: 왼쪽, 2: 아래쪽, 3: 위쪽 */
            for (int j = 0; j < 4; j++) {
                int m_row = pop_row + move_row[j];
                int m_col = pop_col + move_col[j];
                if (isInBound(m_row, m_col) && box[m_row][m_col] == 0) {
                    Point push_point = {m_row, m_col};
                    box[m_row][m_col] = 1;
                    ripen_points.push(push_point);
                } else {
                    continue;
                }
            }
        }
        day++;
    }
}

bool check() {
    bool isAllRipen = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                isAllRipen = false;
            }
        }
    }
    return isAllRipen;
}

int main() {
    input();
    if(isBeforeAllRipen) {
        cout << 0;
        return 0;
    } else {
        if (ripen_points.empty()) {
            cout << -1;
            return 0;
        } else {
            bfs();
        }
        if (check()) {
            cout << day << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}