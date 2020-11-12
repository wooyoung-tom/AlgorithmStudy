//
// Created by 최우영 on 2020/11/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> player_map;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    for (int i = 0; i < completion.size(); ++i)
        ++player_map[completion[i]];

    for (int i = 0; i < participant.size(); ++i) {
        --player_map[participant[i]];

        if (player_map[participant[i]] < 0)
            answer = participant[i];
    }

    return answer;
}