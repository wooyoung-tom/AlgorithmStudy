//
// Created by djdj7 on 2020-05-20.
//

/*
 *  TODO 왜 맞았누...?
 *   다시 한번 해봐야함.
 */

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct {
    int priority, location;
} INFO;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int count = 0;

    priority_queue<int> pq;
    queue<INFO> q;

    for (int i = 0; i < priorities.size(); ++i) {
        INFO info = {priorities[i], i};
        q.push(info);
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int current_max = pq.top();
        if (current_max == q.front().priority) {
            if (q.front().location == location) {
                answer = count;
                break;
            } else {
                pq.pop();
                q.pop();
                count++;
            }
        } else {
            INFO info = q.front();
            q.pop();
            q.push(info);
        }
    }

    while (!q.empty()) {
        int current_location = q.front().location;
        q.pop();
        count++;
        if (current_location == location) {
            answer = count;
            break;
        }
    }

    return answer;
}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;
    solution(priorities, location);
}