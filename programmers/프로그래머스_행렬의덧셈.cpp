//
// Created by djdj7 on 2020-05-13.
//

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> temp_answer;

    for (int i = 0; i < arr1.size(); ++i) {
        for (int j = 0; j < arr1[i].size(); ++j) {
            int left_operand = arr1[i][j];
            int right_operand = arr2[i][j];
            temp_answer.push_back(left_operand + right_operand);
        }
        answer.push_back(temp_answer);
        temp_answer.clear();
    }
    return answer;
}