//
// Created by djdj7 on 2020-03-15.
//

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int index = 0;

    for(int i = 0 ; i < seoul.size() ; i++) {
        if(seoul[i] == "Kim") {
            index = i;
        }
    }

    answer = "김서방은 " + to_string(index) + "에 있다";
    return answer;
}