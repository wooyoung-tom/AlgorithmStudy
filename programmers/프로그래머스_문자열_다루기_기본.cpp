//
// Created by djdj7 on 2020-03-15.
//

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if(s.size() == 4 || s.size() == 6) {
        for(int i = 0 ; i < s.size() ; i++) {
            int a = s[i];
            if((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
                answer = false;
            }
        }
    } else {
        answer = false;
    }
    return answer;
}