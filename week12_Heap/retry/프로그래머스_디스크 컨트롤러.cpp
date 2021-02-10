//
// Created by 최우영 on 2021/02/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0;
    int time = 0;

    // jobs 를 먼저 들어온 시간 순, 처리하는 데 걸리는 시간 순 으로 정렬한다.
    sort(jobs.begin(), jobs.end());

    // Priority Queue 선언
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    // 대기열이 없거나 큐가 empty 될 때까지
    while (!pq.empty() || idx < jobs.size()) {
        // 대기열에 작업이 있고, 작업이 현재 시간보다 작으면
        if (jobs.size() > idx && time >= jobs[idx][0]) {
            pq.push(jobs[idx++]);
            continue;
        }

        // 큐가 비어있지 않다면
        if (!pq.empty()) {
            // 시간 변수에 작업이 끝날 때 까지 걸리는 시간 추가
            time += pq.top()[1];
            // 작업시간에 대기 시간만큼 추가 (현재 시간 - 작업 들어온 시간)
            answer += time - pq.top()[0];

            pq.pop();
        } else time = jobs[idx][0];
    }

    answer /= jobs.size();

    return answer;
}