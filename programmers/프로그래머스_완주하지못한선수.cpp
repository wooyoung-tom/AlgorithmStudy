//
// Created by djdj7 on 2020-03-12.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> _map;

    for(int i = 0 ; i < completion.size() ; i++) {
        _map[completion[i]]++;
    }

    for(int i = 0 ; i < participant.size() ; i++) {
        if(_map[participant[i]]) {
            _map[participant[i]]--;
        } else {
            answer = _map[participant[i]];
            break;
        }
    }

    return answer;
}

