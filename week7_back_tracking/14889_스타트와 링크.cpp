//
// Created by 최우영 on 2021/01/06.
//

#include <iostream>
#include <vector>

#define MAX 20 + 1

using namespace std;

// 좌표담을 구조체
struct Point {
    int i, j;
};

// N(4 ≤ N ≤ 20, N은 짝수)
int N;
// N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고,
// i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고,
// 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.
int S[MAX][MAX];
bool isVisited[MAX];

vector<int> start, link;

int minNum = 101;

void input() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &S[i][j]);
        }
    }
}

/**
 * Function for calculate team's power
 */
void calculate() {
    int startPower = 0;
    int linkPower = 0;
    int res;

    for (int i = 0; i < N / 2; ++i) {
        for (int j = i + 1; j < N / 2; ++j) {
            // 계산 (좌표바꿔서도 진행해주어야 함)
            startPower += (S[start[i]][start[j]] + S[start[j]][start[i]]);
            linkPower += (S[link[i]][link[j]] + S[link[j]][link[i]]);
        }
    }

    res = abs(startPower - linkPower);
    if (minNum > res) minNum = res;
}

/**
 * DFS Function
 * @param player 현재 뽑을 Player
 * @param cnt 현재까지 뽑은 Player 인원 수
 */
void solve(int player, int cnt) {
    // N 의 절반만큼 뽑았으면, start 팀과 link 팀의 능력치 차이를 계산해야 한다.
    if (cnt == N / 2) {
        // 방문한 애들은 Start 팀, 아닌 나머지는 Link 팀
        for (int i = 0; i < N; ++i) {
            if (isVisited[i]) start.push_back(i);
            else link.push_back(i);
        }

        calculate();

        start.clear();
        link.clear();
        return;
    }

    for (int i = player + 1; i < N; ++i) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            solve(i, cnt + 1);
            isVisited[i] = false;
        }
    }

}

int main() {
    input();

    solve(0, 0);

    printf("%d", minNum);
}