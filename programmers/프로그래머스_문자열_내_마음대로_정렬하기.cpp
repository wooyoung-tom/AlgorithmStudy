//
// Created by djdj7 on 2020-03-15.
//

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    string temp;

    for(int i = 0 ; i < strings.size() ; i++) {
        for(int j = 0 ; j < strings.size() ; j++) {
            if(strings[i][n] < strings[j][n]) {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            } else if(strings[i][n] == strings[j][n]) {
                if(strings[i] < strings[j]) {
                    temp = strings[i];
                    strings[i] = strings[j];
                    strings[j] = temp;
                }
            }
        }
    }

    answer = strings;
    return answer;
}