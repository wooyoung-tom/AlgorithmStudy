//
// Created by djdj7 on 2020-04-28.
//

/*
 * TODO 2178_미로탐색 완료.
 *  1. BFS 쓰는 것은 파악.
 *  2. 안가도 되는 부분까지 가는 것이 문제. -> 같은 거리에 있는 애들을 똑같다고 생각하고 끝에 도착했을 때 거리를 재면 됨.
 *  3. DFS 쓰면 필요없나? -> DFS 쓰면 안됨.
 *  4. BFS 썼을 때가 가장 Optimal.
 */
#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int row, col;
} Position;

/*
 * (1,1)부터 출발해서 (N,M)까지 가야함.
 * N->row / M->col
 */
int N, M;
int maze[101][101];
bool isVisited[101][101];

int move_row[] = {0, 0, 1, -1};
int move_col[] = {1, -1, 0, 0};

int result_count;
int current_count;

bool isInBound(int row, int col) {
    return row >= 1 && row <= N && col >= 1 && col <= M;
}

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
}

void bfs(Position start_position) {
    queue<Position> q;
    q.push(start_position);
    isVisited[start_position.row][start_position.col] = true;

    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            Position current_position = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int m_row = current_position.row + move_row[j];
                int m_col = current_position.col + move_col[j];
                if (isInBound(m_row, m_col) && !isVisited[m_row][m_col] && maze[m_row][m_col] == 1) {
                    Position moved_position;
                    moved_position.row = m_row;
                    moved_position.col = m_col;
                    q.push(moved_position);
                    isVisited[m_row][m_col] = true;
                    if (m_row == N && m_col == M) {
                        result_count = current_count + 1;
                    }
                }
            }
        }
        current_count++;
    }
}

int main() {
    Position position;
    input();
    position.row = 1;
    position.col = 1;
    bfs(position);

    cout << result_count + 1;
}