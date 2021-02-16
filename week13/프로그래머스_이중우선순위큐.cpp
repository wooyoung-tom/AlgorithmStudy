//
// Created by 최우영 on 2021/02/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

deque<int> doublePriorityQueue;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (int i = 0; i < operations.size(); ++i) {
        // 첫 번째 char 는 무조건 동작에 관련한 문자
        char op = operations[i][0];

        // 공백을 기준으로 substring 구함
        string strNum = operations[i].substr(2, operations[i].length() - 1);
        int num = stoi(strNum);

        if (op == 'I') {
            // 1. I 이면 큐에 넣어 줌
            doublePriorityQueue.push_back(num);
            // 큐에 넣어주고, 오름차순 정렬
            sort(doublePriorityQueue.begin(), doublePriorityQueue.end());
        } else {
            // 비어있으면 삭제를 못 한다.
            if (doublePriorityQueue.empty()) continue;
            if (num == 1) {
                // 2-1. D 1 이면 최대값 삭제 -> 벡터의 끝을 pop
                doublePriorityQueue.pop_back();
            } else {
                // 2-2. D -1 이면 최소값 삭제 -> 벡터의 앞을 pop
                doublePriorityQueue.pop_front();
            }
        }
    }

    if (doublePriorityQueue.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(doublePriorityQueue.back());
        answer.push_back(doublePriorityQueue.front());
    }

    return answer;
}

int main() {
    vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};

    solution(operations);
}

// 	["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]