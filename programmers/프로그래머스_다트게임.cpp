//
// Created by djdj7 on 2020-05-12.
//

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> number_v;
    string number_str;

    for (int i = 0; i < dartResult.length(); ++i) {
        if (dartResult[i] != 'S' && dartResult[i] != 'D'
            && dartResult[i] != 'T' && dartResult[i] != '*'
            && dartResult[i] != '#') {
            number_str += dartResult[i];
        } else {
            int current_number = atoi(number_str.c_str());
            if (dartResult[i] == 'S') {
                current_number = pow(current_number, 1);
                number_v.push_back(current_number);
                number_str = "";
            } else if (dartResult[i] == 'D') {
                current_number = pow(current_number, 2);
                number_v.push_back(current_number);
                number_str = "";
            } else  if (dartResult[i] == 'T') {
                current_number = pow(current_number, 3);
                number_v.push_back(current_number);
                number_str = "";
            } else if (dartResult[i] == '*') {
                if (number_v.size() > 1) {
                    number_v[number_v.size() - 1] *= 2;
                    number_v[number_v.size() - 2] *= 2;
                } else {
                    number_v[number_v.size() - 1] *= 2;
                }
            } else {
                number_v[number_v.size() - 1] *= -1;
            }
        }
    }

    for (int j = 0; j < number_v.size(); ++j) {
        answer += number_v[j];
    }

    return answer;
}