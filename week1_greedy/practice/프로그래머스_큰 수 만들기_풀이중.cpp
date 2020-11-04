//
// Created by 최우영 on 2020/11/04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 변환된 숫자 넣어놓을 vector
vector<int> number_v;

string solution(string number, int k) {
    string answer = "";

    // Char to Int 변환과정 및 변환된 Integer vector 로 넣음.
    for (int i = 0; i < number.length(); ++i) {
        int current_num = number[i] - 48;
        number_v.push_back(current_num);
    }

    // 변환된 숫자 넣어둔 vector 순회
    for (int i = 0; i < number_v.size(); ++i) {
        int current_num = number_v[i];
    }

    return answer;
}

int main() {
    solution("1924", 2);
}