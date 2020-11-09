//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> clothes_map;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    for (int i = 0; i < clothes.size(); ++i) {
        // 0번째 원소가 옷의 이름, 1번째 원소가 옷의 종류
        string clothe_name = clothes[i][0];
        string clothe_type = clothes[i][1];

        // 옷의 종류를 key 로 하여 갯수 더해 나감.
        clothes_map[clothe_type]++;
    }

    return answer;
}

void input() {

}

int main() {
//    input();
//    solution();
}