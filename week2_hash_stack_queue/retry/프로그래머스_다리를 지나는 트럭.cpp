//
// Created by 최우영 on 2020/11/11.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 다리위에 지나고 있는 트럭의 Queue
queue<int> crossingTruck;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    // 현재 다리위에 올라가 있는 트럭들의 총 무게 합
    int totalWeight = 0;
    // 현재 트럭의 index
    int truckIndex = 0;

    // 무한루프 구성
    while (true) {
        // 루프 한 번 돌면 1초가 지난다.
        answer++;

        // 다리 길이와 queue 의 크기가 같다면 더 이상 다리에 올라가지 못한다.
        if (crossingTruck.size() == bridge_length) {
            // 트럭이 더 이상 올라가지 못한다면 제일 앞의 트럭을
            // 빼주어야 한다.
            totalWeight -= crossingTruck.front();
            crossingTruck.pop();
        }

        // 트럭을 추가 할 수 있음
        if (totalWeight + truck_weights[truckIndex] <= weight) {
            // 마지막 트럭인지 check
            if (truckIndex == truck_weights.size() - 1) {
                // 마지막 트럭이라면 다리 길이만큼 answer 더하면 된다.
                answer += bridge_length;
                break;
            }
            // 마지막 트럭이 아니라면
            // 현재 트럭을 다리 위에 올린다.(queue 에 push)
            crossingTruck.push(truck_weights[truckIndex]);
            totalWeight += truck_weights[truckIndex];
            truckIndex++;
        }
            // 트럭을 올리지 못할 때
        else {
            // 현재 queue 에 있는 트럭을 앞으로 진행시켜야 한다.
            crossingTruck.push(0);
        }
    }

    return answer;
}