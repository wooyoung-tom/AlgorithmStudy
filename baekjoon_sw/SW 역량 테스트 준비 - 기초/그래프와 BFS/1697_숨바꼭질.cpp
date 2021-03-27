//
// Created by djdj7 on 2020-05-04.
//


/*
 * TODO 1697번 숨바꼭질 풀이중...
 *  1. BFS 사용
 *  2. isVisited 배열이 MAX의 두배가 되어야함.
 */

#include <iostream>
#include <queue>

#define MAX 100000

using namespace std;

int N, K;
int move_position[] = {-1, 1};
int second;
int result_second = MAX;
bool isVisited[2*MAX];
bool complete;

bool isValid(int m_position) {
    return m_position >= 0 && m_position <= MAX
           && !isVisited[m_position];
}

void bfs(int n, int k) {
    queue<int> q;
    q.push(n);
    isVisited[n] = true;

    while (!complete) {
        int old_size = q.size();

        for (int i = 0; i < old_size; i++) {
            int current_position = q.front();
            if (current_position == k) {
                result_second = min(result_second, second);
                complete = true;
                break;
            }
            q.pop();
            for (int j : move_position) {
                int m_position = current_position + j;
                if (isValid(m_position)) {
                    q.push(m_position);
                    isVisited[m_position] = true;
                }
            }
            if(isValid(current_position * 2)) {
                q.push(current_position * 2);
                isVisited[current_position * 2] = true;
            }
        }
        second++;
    }
}

int main() {
    cin >> N >> K;

    bfs(N, K);

    cout << result_second;
}