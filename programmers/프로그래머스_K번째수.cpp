//
// Created by djdj7 on 2020-03-12.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0 ; i < commands.size() ; i++) {
        int begin = commands[i][0];
        int end = commands[i][1];
        int ind = commands[i][2];

        temp.clear();
        temp.assign(array.begin() + begin - 1, array.begin() + end);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[ind - 1]);
    }

    return answer;
}

