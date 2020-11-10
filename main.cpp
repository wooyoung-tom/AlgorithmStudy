//
// Created by 최우영 on 2020/11/01.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> crossingTruck;
vector<int> crossedTruck;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int second = 0;
    int currentTotalWeight = 0;
    int currentTruckIdx = 0;

    // 트럭이 모두 지날 때 까지 loop 진행
    while (crossedTruck.size() != truck_weights.size()) {
        int currentTruckWeight = truck_weights[currentTruckIdx];

        // 지나고 있는 트럭이 없으면 queue 에 넣음 (출발)
        if (crossingTruck.empty()) {
            crossingTruck.push(currentTruckWeight);

            currentTotalWeight += currentTruckWeight;

            currentTruckIdx++;
            second++;

            continue;
        }
        // 지나고 있는 트럭이 있을 때
        else {
            // 현재 트럭 총 무게를 현재 트럭무게와 합쳤을 때 weight 보다 크면
            if (currentTotalWeight + currentTruckWeight > weight) {
                // 출발 하지 못함

            }
        }
    }

    return answer;
}

void input() {

}

int main() {
//    input();
//    solution(v);
}