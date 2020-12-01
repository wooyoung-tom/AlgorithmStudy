//
// Created by 최우영 on 2020/12/01.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// 단, 2 ≤ N ≤ 50, 10 ≤ x,y ≤ 200 이다.
int N;
struct person {
    int weight, height, ranking;
};
vector<person> personContainer;

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        // 랭킹을 모두 1위로 초기화 시킨다.
        personContainer.push_back(person{x, y, 1});
    }
}

void solution() {
    for (int i = 0; i < N; ++i) {
        // 타겟을 정해놓고, 전체 탐색을 진행한다.
        for (int j = 0; j < N; ++j) {
            // 자기 자신 예외 처리 해준다.
            if (i == j) continue;
            // Target
            person target = personContainer[j];
            // 타겟으로 잡은 사람과 덩치를 비교한다.
            // 1. 키와 몸무게 모두 현재 선택된 사람이 타겟보다 작을 때
            if (personContainer[i].weight < target.weight
                && personContainer[i].height < target.height) {
                // 순위를 한 개 내려준다.
                personContainer[i].ranking++;
            }
        }
    }

    for (int i = 0; i < personContainer.size(); ++i) {
        cout << personContainer[i].ranking << " ";
    }
}

int main() {
    input();
    solution();
}