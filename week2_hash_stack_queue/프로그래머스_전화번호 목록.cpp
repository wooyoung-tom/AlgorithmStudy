//
// Created by 최우영 on 2020/11/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> input_v;
unordered_map<string, int> prefix_map;

bool solution(vector<string> phone_book) {
    bool answer = true;

    // 하나씩 가져와서 생각
    for (int i = 0; i < phone_book.size(); ++i) {
        // 현재 전화번호 저장
        string current_str = phone_book[i];
        string temp_str = "";

        // 현재 전화번호에서 한글자씩 hash 에 key 로 매핑
        for (int j = 0; j < current_str.length(); ++j) {
            temp_str += current_str[j];
            prefix_map[temp_str]++;
        }
    }

    for (int i = 0; i < phone_book.size(); ++i) {
        // 목록을 돌면서 값이 2 이상이면 다른 어느 것의 접두어라는 것
        if (prefix_map[phone_book[i]] > 1) {
            return false;
        }
    }

    return answer;
}