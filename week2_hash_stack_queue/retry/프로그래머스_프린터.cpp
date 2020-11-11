//
// Created by 최우영 on 2020/11/11.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<pair<int, int>> printerQueue;
priority_queue<int> priorityQueue;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for (int i = 0; i < priorities.size(); ++i) {
        printerQueue.push(make_pair(i, priorities[i]));
        priorityQueue.push(priorities[i]);
    }

    while (!printerQueue.empty()) {
        int index = printerQueue.front().first;
        int priority = printerQueue.front().second;

        printerQueue.pop();

        // 지금 문서가 가장 중요하면 출력
        if (priority == priorityQueue.top()) {
            priorityQueue.pop();
            answer++;

            if (index == location) break;
        } else {
            // 다시 큐에 넣어야 한다.
            printerQueue.push(make_pair(index, priority));
        }
    }

    return answer;
}