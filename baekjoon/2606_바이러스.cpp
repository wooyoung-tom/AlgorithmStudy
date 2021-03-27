//
// Created by djdj7 on 2020-04-27.
//

#include <iostream>
#include <queue>

using namespace std;

int computer, edges;
int network[101][101];
bool isVisited[101];

int virus_computer;

void input() {
    int one, two;
    cin >> computer >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> one >> two;
        network[one][two] = 1;
        network[two][one] = 1;
    }
}

/* BFS를 통해서 1번 컴퓨터부터 돌게됨, 떨어져있으면 애초에 가지 않음. */
void bfs(int start) {
    queue<int> q;
    q.push(start);
    isVisited[start] = true;

    while (!q.empty()) {
        int q_front = q.front();
        q.pop();
        virus_computer++;

        for (int i = 1; i <= computer; ++i) {
            if (i != q_front) {
                if (!isVisited[i] && network[i][q_front] == 1 && network[q_front][i] == 1) {
                    q.push(i);
                    isVisited[i] = true;
                }
            }
        }
    }
}

int main() {
    input();
    bfs(1);
    cout << virus_computer-1;
}