//
// Created by djdj7 on 2020-03-15.
//


#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<string> subak = {"수", "박"};

    for(int i = 0 ; i < n ; i++) {
        answer += subak[i % 2];
    }
    return answer;
}