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

    for (int i = 0; i < completion.size(); ++i) {
        string current_player = completion[i];
        ++player_map[current_player];
    }

    for (int i = 0; i < participant.size(); ++i) {
        string current_player = participant[i];
        --player_map[current_player];

        if (player_map[current_player] < 0) {
            answer = current_player;
        }
    }

    return answer;
}