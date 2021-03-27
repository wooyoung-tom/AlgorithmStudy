//
// Created by djdj7 on 2020-03-16.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string number;

    number = to_string(n);

    for(int i = (number.size() - 1) ; i >= 0 ; i--) {
        char a = number[i];
        answer.push_back(number[i] - '0');
    }
    return answer;
}