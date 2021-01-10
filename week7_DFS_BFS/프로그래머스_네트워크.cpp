//
// Created by 최우영 on 2021/01/09.
//


#include <iostream>
#include <vector>

using namespace std;

// 방문한 Computer (index == Computer Number)
bool isVisited[201];

/**
 *
 * @param start 현재 컴퓨터 번호
 * @param n 총 컴퓨터의 개수
 * @param computers 컴퓨터 네트워킹 상태를 나타낸 벡터
 */
void dfs(int current, int n, vector<vector<int>> computers) {
    // 현재 컴퓨터 방문
    isVisited[current] = true;

    // 전체 컴퓨터를 순회
    for (int i = 0; i < n; ++i) {
        // 다른 컴퓨터가 방문하지 않았고, 현재 컴퓨터와 연결되어 있으면
        // 한 단계 더 들어간다.
        if (!isVisited[i] && computers[current][i] == 1) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; ++i) {
        if (!isVisited[i]) {
            answer++;
            dfs(i, n, computers);
        }
    }

    printf("%d", answer);

    return answer;
}

int main() {
    int n = 3;
    vector<vector<int>> computers = {{1, 1, 0},
                                     {1, 1, 1},
                                     {0, 1, 1}};

    solution(n, computers);
}