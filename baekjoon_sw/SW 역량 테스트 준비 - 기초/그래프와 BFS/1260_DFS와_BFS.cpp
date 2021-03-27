//
// Created by djdj7 on 2020-04-27.
//

#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int one, two;
int arr[1001][1001];
bool isVisited[1001];

void input() {
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        cin >> one >> two;
        arr[one][two] = 1;
        arr[two][one] = 1;
    }
}

/* isVisit 함수를 DFS 이후에 false로 Reset */
void reset_visit() {
    for (int i = 1; i <= N; i++) {
        isVisited[i] = false;
    }
}

/* DFS isVisit 함수 확인 후 재귀함수로 구현 */
void dfs(int start) {
    cout << start << " ";
    isVisited[start] = true;

    for (int i = 1; i <= N; i++) {
        if (i == start) {
            continue;
        } else {
            if (!isVisited[i] && arr[start][i] == 1 && arr[i][start] == 1) {
                dfs(i);
            }
        }
    }
}

/* BFS 함수 queue 사용하여 구현 */
void bfs(int start) {
    queue<int> q;
    q.push(start);
    isVisited[start] = true;

    while (!q.empty()) {
        int q_front = q.front();
        q.pop();
        cout << q_front << " ";

        for (int i = 1; i <= N; i++) {
            if (i == q_front) {
                continue;
            } else {
                if (!isVisited[i] && arr[q_front][i] == 1 && arr[i][q_front] == 1) {
                    q.push(i);
                    isVisited[i] = true;
                }
            }
        }
    }
}

int main() {
    input();
    dfs(V);
    reset_visit();      // DFS 돌고 isVisited 배열 false로 초기화
    cout << "\n";
    bfs(V);
}