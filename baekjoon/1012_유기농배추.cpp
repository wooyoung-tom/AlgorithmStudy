//
// Created by djdj7 on 2020-04-27.
//

#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int row, col;
} Position;

/*
 * T->테스트케이스 개수 / M->가로길이 (column)
 * N->세로길이 (row) / K->배추심어진 개수
 */
int T, M, N, K;
int cabbage_map[51][51];
bool isVisited[51][51];
int bug_count;

int move_row[] = {0, 0, 1, -1};
int move_col[] = {1, -1, 0, 0};

/* 상하좌우 좌표가 Boundary 안쪽인지 체크 */
bool isInBound(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

/* 한번 다 돌고나면 양배추 정보 모두 reset 해주어야 함. */
void reset_cabbage() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cabbage_map[i][j] = 0;
            isVisited[i][j] = false;
        }
    }
}

void bfs(Position start_position) {
    queue<Position> bfs_q;
    bfs_q.push(start_position);

    int start_row = start_position.row;
    int start_col = start_position.col;

    isVisited[start_row][start_col] = true;

    while (!bfs_q.empty()) {
        Position current_position = bfs_q.front();
        bfs_q.pop();

        for (int i = 0; i < 4; i++) {
            int m_row = current_position.row + move_row[i];
            int m_col = current_position.col + move_col[i];
            if (isInBound(m_row, m_col) && cabbage_map[m_row][m_col] == 1 && !isVisited[m_row][m_col]) {
                Position moved_position;
                moved_position.row = m_row;
                moved_position.col = m_col;
                isVisited[m_row][m_col] = true;
                bfs_q.push(moved_position);
            }
        }
    }
}

void input_and_solve() {
    int col, row;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++) {
            cin >> col >> row;
            Position position;
            position.row = row;
            position.col = col;
            cabbage_map[row][col] = 1;
        }
        for (int i_row = 0; i_row < N; i_row++) {
            for (int i_col = 0; i_col < M; i_col++) {
                Position position;
                position.row = i_row;
                position.col = i_col;
                if (!isVisited[i_row][i_col] && cabbage_map[i_row][i_col] == 1) {
                    bfs(position);
                    bug_count++;
                }
            }
        }
        cout << bug_count << "\n";
        bug_count = 0;
        reset_cabbage();
    }
}

int main() {
    input_and_solve();
}