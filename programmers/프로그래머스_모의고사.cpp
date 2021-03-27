//
// Created by djdj7 on 2020-03-13.
//

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score;

    vector<int> answer1 = {1, 2, 3, 4, 5};
    vector<int> answer2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> answer3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for(int i = 0 ; i < answers.size() ; i++) {
        int mod1 = i % 5;
        int mod2 = i % 8;
        int mod3 = i % 10;

        if(answers[i] == answer1[mod1]) count1++;
        if(answers[i] == answer2[mod2]) count2++;
        if(answers[i] == answer3[mod3]) count3++;
    }

    int result = max(count1, max(count2, count3));

    if(result == count1) answer.push_back(1);
    if(result == count2) answer.push_back(2);
    if(result == count3) answer.push_back(3);
    return answer;
}