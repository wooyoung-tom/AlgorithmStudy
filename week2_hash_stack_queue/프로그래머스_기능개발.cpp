//
// Created by 최우영 on 2020/11/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> remainDayVector;
queue<int> dayQueue;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    // progresses 기준으로 초기화 위해서 for loop
    for (int i = 0; i < progresses.size(); ++i) {
        int currentProgress = progresses[i];
        int currentSpeed = speeds[i];

        // progress 가 100 기준으로 얼마나 남았는지 계산
        int remainProgress = 100 - currentProgress;

        // 남은 progress 가 speed 기준으로 몇일을 수행해야 하는지 계산
        // 1. remainProgress 에서 speed 를 나누었을 때 나누어 떨어질 때
        if (remainProgress % currentSpeed == 0) {
            int day = remainProgress / currentSpeed;
            // 1-1. 남은 일 수 넣는 벡터에 넣음
            remainDayVector.push_back(day);
        }
        // 2. remainProgress 에서 speed 를 나누었을 때 나누어 떨어지지 않을 때
        else {
            // 하루 더 필요 함
            int day = (remainProgress / currentSpeed) + 1;
            remainDayVector.push_back(day);
        }
    }

    // vector 에 넣어놓은 남은 일 수 루프 돌면서 계산
    for (int i = 0; i < remainDayVector.size(); ++i) {
        int currentRemainDay = remainDayVector[i];
        // queue 비어있다면 push
        if (dayQueue.empty()) {
            dayQueue.push(currentRemainDay);
            continue;
        }
        // queue 원소 유효할 때
        else {
            // queue 의 front 와 비교해야 한다.
            int front = dayQueue.front();
            // 1. front 가 현재 남은 일 수보다 크거나 같을 때
            if (front >= currentRemainDay) {
                // 1-1. queue 에 현재 남은 일 수 push
                dayQueue.push(currentRemainDay);
            }

            // 2. front 가 현재 남은 일 수보다 작을 때
            else {
                // 2-1. 앞의 모든 기능 (현재 제외) 배포 가능해진다.
                answer.push_back(dayQueue.size());

                // 2-2. queue 비워주어야 한다.
                while (!dayQueue.empty())
                    dayQueue.pop();

                // 2-3. 비어있는 queue 에 현재 남은 일 수 push
                dayQueue.push(currentRemainDay);
            }
        }
    }

    // 끝났는데 Queue 에 원소가 존재한다면 계산 해주어야 함
    if (!dayQueue.empty()) {
        answer.push_back(dayQueue.size());
    }

    return answer;
}