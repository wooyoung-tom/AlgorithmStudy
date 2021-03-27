//
// Created by djdj7 on 2020-03-26.
//

/*
 * TODO 16234번 인구이동 풀이...
 *  BFS 사용하여 한칸한칸 돌아야 함.
 *  BFS 사용이 핵심! BFS 사용법 다시한번 익히기.
 *  BFS/DFS 다시한번 공부해야함.
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int N, L, R;
int result = 0;
/* col, row 움직이는 방향 지정 */
int col_move[] = { 0, 0, 1, -1 };
int row_move[] = { 1, -1, 0, 0 };
/* 지도 상태와 방문여부 Array */
int land[50][50];
bool isVisited[50][50];
/* 인구이동이 완료되었는지에 대한 Flag */
bool check = true;

bool calculate_population(int current, int next) {
    int differ = abs(current-next);
    return L <= differ && differ <= R;
}

void bfs(int row, int col) {
    int union_sum = 0;
    int union_count = 0;

    queue<pair<int, int>> q, union_q;
    q.push(make_pair(row, col));
    union_q.push(make_pair(row, col));

    while (!q.empty()) {
        /* 큐 제일 앞에있는 원소 빼냄 */
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        isVisited[r][c] = true;

        union_sum += land[r][c];
        union_count++;

        /* 상, 하, 좌, 우 움직임
         * 0 -> 하 / 1 -> 상 / 2 -> 우 / 3 - > 좌
         */
        for(int i = 0 ; i < 4 ; i++) {
            int move_r = r + row_move[i];
            int move_c = c + col_move[i];
            if(move_r < 0 || move_r >= N || move_c < 0 || move_c >= N) continue;
            if(isVisited[move_r][move_c]) continue;
            if(calculate_population(land[r][c], land[move_r][move_c])) {
                isVisited[move_r][move_c] = true;
                q.push(make_pair(move_r, move_c));
                union_q.push(make_pair(move_r, move_c));
            }
        }
    }

    /*
     * 연합 할 수 있는 부분 다 했을 때
     * 연합 큐에 담겨있는 포인트들 돌면서 인구 변경.
     */
    if(union_count != 1) {
        check = true;
    }
    int population = union_sum / union_count;
    while(!union_q.empty()) {
        int _r = union_q.front().first;
        int _c = union_q.front().second;
        land[_r][_c] = population;
        union_q.pop();
    }
}

void input() {
    cin >> N >> L >> R;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            cin >> land[i][j];
        }
    }
}

int main() {
    input();

    while(check) {
        check = false;

        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                if(!isVisited[i][j]) bfs(i, j);
            }
        }

        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j < N ; j++) {
                isVisited[i][j] = false;
            }
        }
        if(check) result++;
    }

    cout << result;
}