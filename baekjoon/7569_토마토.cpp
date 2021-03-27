//
// Created by djdj7 on 2020-04-22.
//

#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int h, row, col;
} Point;

/* 익어있는 토마토 넣을 Queue */
queue<Point> ripen_q;

/* M=가로(col) N=세로(row) H=높이(h) */
int M, N, H;
/* h / row / col 순서 */
int tomato_box[100][100][100];
bool isVisited[100][100][100];

int result_day;

/* 실행 전에 토마토가 모두 익었는지 확인하는 Flag */
bool isBeforeRipen = true;

/* 우->좌->하->상->위->아래 순 */
Point move_point[6] = {
        {0,  0,  1},
        {0,  0,  -1},
        {0,  1,  0},
        {0,  -1, 0},
        {1,  0,  0,},
        {-1, 0,  0},
};

void input() {
    cin >> M >> N >> H;
    for (int h = 0; h < H; h++) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                cin >> tomato_box[h][row][col];
                if (tomato_box[h][row][col] == 0) {
                    isBeforeRipen = false;
                } else if (tomato_box[h][row][col] == 1) {
                    Point current_point = {h, row, col};
                    ripen_q.push(current_point);
                }
            }
        }
    }
}

bool isInBound(int h, int row, int col) {
    return h < H && h >= 0
           && row < N && row >= 0
           && col < M && col >= 0;
}

bool checkCondition(int h, int row, int col) {
    return isInBound(h, row, col)
           && !isVisited[h][row][col]
           && tomato_box[h][row][col] == 0;
}

bool isAllRipen() {
    bool result = true;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if(tomato_box[i][j][k] == 0){
                    result = false;
                }
            }
        }
    }
    return result;
}

void bfs(Point start_point) {
    isVisited[start_point.h][start_point.row][start_point.col] = true;
    while (!ripen_q.empty()) {
        int q_size = ripen_q.size();
        for (int i = 0; i < q_size; i++) {
            Point current_point = ripen_q.front();
            ripen_q.pop();
            for (int j = 0; j < 6; j++) {
                int m_h = current_point.h + move_point[j].h;
                int m_row = current_point.row + move_point[j].row;
                int m_col = current_point.col + move_point[j].col;
                if (checkCondition(m_h, m_row, m_col)) {
                    Point moved_point = {m_h, m_row, m_col};
                    tomato_box[m_h][m_row][m_col] = 1;
                    isVisited[m_h][m_row][m_col] = true;
                    ripen_q.push(moved_point);
                }
            }
        }
        result_day++;
    }
}

int main() {
    input();
    if (isBeforeRipen) {
        if(!ripen_q.empty()){
            cout << 0 << "\n";
            return 0;
        } else {
            cout << -1 << "\n";
            return 0;
        }
    } else {
        Point start_point = ripen_q.front();
        bfs(start_point);
    }
    if(isAllRipen()) {
        cout << result_day-1 << "\n";
    } else {
        cout << -1 << "\n";
    }
}