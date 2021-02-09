//
// Created by 최우영 on 2021/02/09.
//

/**
 * scoville [1, 2, 3, 9, 10, 12]
 * K        7
 * return   2
 */
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> priorityQueue(scoville.begin(), scoville.end());

    // K 보다 top 값이 작으면
    while (priorityQueue.top() < K) {
        // 섞을 수 있는 것이 없으면 return
        if (priorityQueue.size() == 1) return -1;

        // 첫 번째 음식
        int first = priorityQueue.top();
        priorityQueue.pop();

        // 두 번째 음식
        int second = priorityQueue.top();
        priorityQueue.pop();

        // 더해주고 큐에 push
        int newScoville = first + (second * 2);
        priorityQueue.push(newScoville);

        // 횟수 증가
        answer++;
    }

    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;

    int res = solution(scoville, K);

    printf("%d", res);
}