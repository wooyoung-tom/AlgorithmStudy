//
// Created by 최우영 on 2020/11/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> clothesMap;
vector<string> clotheTypeVector;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    for (int i = 0; i < clothes.size(); ++i) {
        // 0번째 원소가 옷의 이름, 1번째 원소가 옷의 종류
        string clothe_name = clothes[i][0];
        string clothe_type = clothes[i][1];

        // 옷 종류 담아놓을 벡터
        // 옷 종류는 map 의 원소가 0개일 때 넣음
        if (clothesMap[clothe_type] == 0) {
            clotheTypeVector.push_back(clothe_type);
        }

        // 옷의 종류를 key 로 하여 갯수 더해 나감.
        clothesMap[clothe_type]++;
    }

    // 옷 종류 담은 vector 의 크기만큼 돈다
    // answer 0 으로 초기화 되어있는것 곱해야 하므로 1 로 수정
    answer = 1;
    for (int i = 0; i < clotheTypeVector.size(); ++i) {
        string currentType = clotheTypeVector[i];
        int currentCount = clothesMap[currentType];
        // 경우의 수 = 의상 개수 + 1
        answer *= (currentCount + 1);
    }

    // 마지막에 아무것도 선택하지 않는 경우의 수 1 제외
    answer -= 1;

    return answer;
}